#include <iostream>
#include <queue>
using namespace std;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};

void bfs(int h, int w, int y, int x,
         int& num_doc, int& key_bit, vector<pair<int, int>>& locked_doors,
         char board[][100], bool visited[][100]) {
    queue<pair<int, int>> q;
    q.push({y, x});
    visited[y][x] = true;

    while(!q.empty()) {
        pair<int, int> here = q.front();
        q.pop();

        char& here_char = board[here.first][here.second];
        if(here_char == '$') {
            num_doc++;
        } else if(here_char >= 'a' && here_char <= 'z') {
            key_bit |= (1 << (here_char - 'a'));
        } else if(here_char >= 'A' && here_char <= 'Z') {
            if((key_bit & (1 << (here_char - 'A'))) == 0) {
                locked_doors.push_back(here);
                continue;
            }
        }
        
        for(int i=0; i < 4; i++) {
            int new_y = here.first + dy[i];
            int new_x = here.second + dx[i];
            // 맵을 벗어나는지 확인
            if(new_y < 0 || new_y >= h || new_x < 0 || new_x >= w) {
                continue;
            } else {
                if(board[new_y][new_x] != '*') {
                    if(visited[new_y][new_x] == false) {
                        visited[new_y][new_x] = true;
                        q.push({new_y, new_x});
                    }
                }
            }
        }
    }
}

int get_ans(int h, int w, string start_key, char board[][100]) {
    int num_doc = 0;
    int key_bit = 0;
    bool visited[100][100] = {false};
    vector<pair<int, int>> start_points;
    vector<pair<int, int>> locked_doors;

    // 시작 열쇠
    if(start_key != "0") {
        for(int i=0; i < start_key.length(); i++) {
            key_bit |= (1 << (start_key[i] - 'a'));
        }
    }

    // 시작 위치
    for(int i=0; i < h; i++) {
        if(board[i][0] != '*') {
            start_points.push_back({i, 0});
        }
        if(board[i][w-1] != '*') {
            start_points.push_back({i, w - 1});
        }
    }
    for(int j=0; j < w; j++) {
        if(board[0][j] != '*') {
            start_points.push_back({0, j});
        }
        if(board[h-1][j] != '*') {
            start_points.push_back({h - 1, j});
        }
    }

    int prev_num_doc = num_doc;
    int prev_key_bit = key_bit;

    // 갈 수 있는 곳 탐색
    for(int i=0; i < start_points.size(); i++) {
        if(!visited[start_points[i].first][start_points[i].second]) {
            bfs(h, w, start_points[i].first, start_points[i].second,
                num_doc, key_bit, locked_doors, board, visited);
        }
    }
    
    // 잠긴 문을 중심으로 다시 탐색
    // 변동이 없을 때까지
    while(num_doc != prev_num_doc || key_bit != prev_key_bit) {
        prev_num_doc = num_doc;
        prev_key_bit = key_bit;
        for(int i=0; i < locked_doors.size(); i++) {
            int y = locked_doors[i].first;
            int x = locked_doors[i].second;
            if(key_bit & (1 << (board[y][x] - 'A'))) {
                locked_doors.erase(locked_doors.begin() + i);
                i--;
                bfs(h, w, y, x,
                    num_doc, key_bit, locked_doors, board, visited);
            }
        }
    }

    return num_doc;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    for(int t=0; t < T; t++) {
        int w, h;
        string start_key;
        char board[100][100];

        cin >> w >> h;
        for(int i=0; i < w; i++) {
            for(int j=0; j < h; j++) {
                cin >> board[i][j];
            }
        }

        cin >> start_key;
        cout << get_ans(w, h, start_key, board) << '\n';
    }
}
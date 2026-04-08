#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int H, W;
int board[100][100];
bool visited[100][100] = {0};
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};


void print_map() {
    cout << '\n';
    for(int i=0; i < H; i++) {
        for(int j=0; j < W; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}

bool is_valid_point(int y, int x) {
    if(y >= 0 && y < H && x >= 0 && x < W) {
        return true;
    } else {
        return false;
    }
}

void bfs(int start_y, int start_x, vector<pair<int, int>>* v) {
    queue<pair<int, int>> q;
    q.push({start_y, start_x});
    visited[start_y][start_x] = true;

    while(!q.empty()) {
        int here_y = q.front().first;
        int here_x = q.front().second;
        q.pop();

        for(int i=0; i < 4; i++) {
            int next_y = here_y + dy[i];
            int next_x = here_x + dx[i];

            if(is_valid_point(next_y, next_x)) {
                if(!visited[next_y][next_x]) {
                    visited[next_y][next_x] = true;
                    if(board[next_y][next_x] == 1) {
                        v->push_back({next_y, next_x});
                    } else {
                        q.push({next_y, next_x});
                        visited[next_y][next_x] = true;
                    }
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> H >> W;
    int cheese_size = 0;

    for(int i=0; i < H; i++) {
        for(int j=0; j < W; j++) {
            cin >> board[i][j];
            if(board[i][j] == 1) {
                cheese_size++;
            }
        }
    }

    int t = 0;
    if(cheese_size > 0) {
        vector<pair<int, int>>* v = new vector<pair<int, int>>;
        bfs(0, 0, v);
        for(int i=0; i < v->size(); i++) {
            board[(*v)[i].first][(*v)[i].second] = 0;
        }
        cheese_size -= v->size();
        t++;

#ifndef ONLINE_JUDGE
        cout << cheese_size << '\n';
        print_map();
#endif

        while(cheese_size > 0) {
            vector<pair<int, int>>* next_v = new vector<pair<int, int>>;
            for(int i=0; i < v->size(); i++) {
                bfs((*v)[i].first, (*v)[i].second, next_v);
            }
            cheese_size -= next_v->size();
            t++;
            delete v;
            v = next_v;
            for(int i=0; i < v->size(); i++) {
                board[(*v)[i].first][(*v)[i].second] = 0;
            }
#ifndef ONLINE_JUDGE
            cout << cheese_size << '\n';
            print_map();
#endif
        }

        cout << t << '\n';
        cout << v->size() << '\n';

        delete v;
    } else {
        cout << 0 << '\n' << 0 << '\n';
    }
}
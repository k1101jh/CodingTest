#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
vector<vector<int>> board;
vector<vector<bool>> visited;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};

void bfs(int start_y, int start_x) {
    // vector<vector<bool>> visited = vector<vector<bool>>(N, vector<bool>(N, 0));

    queue<pair<int, int>> q;
    q.push({start_y, start_x});

    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        for(int i=0; i < 4; i++) {
            pair<int, int> next = {cur.first + dy[i], cur.second + dx[i]};
            if(next.first < N && next.first >= 0 && next.second < N && next.second >= 0) {
                if(!visited[next.first][next.second]) {
                    q.push(next);
                    visited[next.first][next.second] = true;
                }
            }
        }
    }
}

int get_num_of_lands() {
    int num_of_lands = 0;
    for(int i=0; i < N; i++) {
        for(int j=0; j < N; j++) {
            if(!visited[i][j]) {
                bfs(i, j);
                num_of_lands++;
            }
        }
    }

    return num_of_lands;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    board = vector<vector<int>>(N, vector<int>(N, 0));
    visited = vector<vector<bool>>(N, vector<bool>(N, false));
    for(int i=0; i < N; i++) {
        for(int j=0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    int max_num = 1;
    for(int water_height=1; water_height < 100; water_height++) {
        for(int i=0; i < N; i++) {
            for(int j=0; j < N; j++) {
                if(board[i][j] <= water_height) {
                    visited[i][j] = true;
                } else {
                    visited[i][j] = false;
                }
            }
        }

        int num_of_lands = get_num_of_lands();
        max_num = max(max_num, num_of_lands);
        if(num_of_lands == 0) {
            break;
        }
    }

    cout << max_num << '\n';
}

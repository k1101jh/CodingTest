#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int n, m;
int dy[4] = {0, -1, 0, 1};
int dx[4] = {-1, 0, 1, 0};

void bfs(int x, int y, vector<vector<int>>& dist) {
    // q에 목표지점 입력
    queue<pair<int, int>> q;
    q.push({x, y});

    // q에서 위치를 꺼내서 해당 위치 주변을 q에 다시 추가
    // 이미 검사한 위치면 다음 원소 꺼내기
    while(!q.empty()) {
        pair<int, int> cur_pos = q.front();
        q.pop();

        for(int i=0; i < 4; i++) {
            // 가능한 위치인지 확인
            pair<int, int> new_pos = {cur_pos.first + dy[i], cur_pos.second + dx[i]};
            if(new_pos.first < 0 || new_pos.first >= n || new_pos.second < 0 || new_pos.second >= m) {
                continue;
            }

            if(dist[new_pos.first][new_pos.second] == -1) {
                dist[new_pos.first][new_pos.second] = dist[cur_pos.first][cur_pos.second] + 1;
                q.push(new_pos);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    int dest_y, dest_x;

    vector<vector<int>> board(n, vector<int>(m, 0));
    vector<vector<int>> dists(n, vector<int>(m, -1));

    // 입력
    for(int i=0; i < n; i++) {
        for(int j=0; j < m; j++) {
            cin >> board[i][j];
            if(board[i][j] == 2) {
                dest_y = i;
                dest_x = j;
                dists[i][j] = 0;
            } else if(board[i][j] == 0) {
                dists[i][j] = 0;
            }
        }
    }

    bfs(dest_y, dest_x, dists);

    for(int i=0; i < n; i++) {
        for(int j=0; j < m; j++) {
            cout << dists[i][j] << ' ';
        }
        cout << endl;
    }
}
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int M, N;
vector<vector<int>> board;
vector<vector<bool>> visited;
vector<vector<int>> dp;

int dy[4] = {0, -1, 0, 1};
int dx[4] = {-1, 0, 1, 0};


int dfs(pair<int, int> cur_pos) {
    // 종료조건
    if(cur_pos.first == M - 1 && cur_pos.second == N - 1) {
        return 1;
    }

    int num_routes = 0;
    visited[cur_pos.first][cur_pos.second] = true;

    for(int i=0; i < 4; i++) {
        pair<int, int> next_pos = {cur_pos.first + dy[i], cur_pos.second + dx[i]};

        // 범위 검사
        if(next_pos.first >= 0 && next_pos.first < M && next_pos.second >= 0 && next_pos.second < N) {
            // 저장한 해당 루트로 가는 가지수 확인
            if(board[next_pos.first][next_pos.second] < board[cur_pos.first][cur_pos.second]) {
                if(dp[next_pos.first][next_pos.second] != -1) {
                    num_routes += dp[next_pos.first][next_pos.second];
                } else {
                    if(!visited[next_pos.first][next_pos.second]) {
                        num_routes += dfs(next_pos);
                    }
                }
            }
        }
    }

    visited[cur_pos.first][cur_pos.second] = false;
    dp[cur_pos.first][cur_pos.second] = num_routes;
    return num_routes;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N;

    board = vector<vector<int>>(M, vector<int>(N, 0));
    visited = vector<vector<bool>>(M, vector<bool>(N, false));
    dp = vector<vector<int>>(M, vector<int>(N, -1));

    for(int i=0; i < M; i++) {
        for(int j=0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    visited[0][0] = true;

    cout << dfs({0, 0}) << '\n';
}
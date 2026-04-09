#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<vector<bool>> visited;
vector<string> board;

const int dy[4] = {0, -1, 0, 1};
const int dx[4] = {-1, 0, 1, 0};

bool is_valid_point(pair<int, int>& point) {
    return !(point.first < 0 || point.first >= N || point.second < 0 || point.second >= M);
}

int bfs(pair<int, int> start_point) {
    int result = 0;
    queue<pair<int, int>> q;
    q.push(start_point);
    visited[start_point.first][start_point.second] = true;

    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        for(int i=0; i < 4; i++) {
            pair<int, int> next = {cur.first + dy[i], cur.second + dx[i]};
            if(is_valid_point(next) && !visited[next.first][next.second]) {
                char& board_c = board[next.first][next.second];
                if(board_c == 'X') {
                    q.push(next);
                    visited[next.first][next.second] = true;
                } else if(board_c == 'Y') {
                    result++;
                }
            }
        }
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    board = vector<string>(N, "");
    visited = vector<vector<bool>>(N, vector<bool>(M, false));

    for(int i=0; i < N; i++) {
        cin >> board[i];
    }

    int ans = 0;
    for(int i=0; i < N; i++) {
        for(int j=0; j < M; j++) {
            if(board[i][j] == 'X') {
                ans = bfs({i, j});
                cout << ans << '\n';
                return 0;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
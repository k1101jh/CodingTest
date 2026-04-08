#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;

int dy[2] = {1, 0};
int dx[2] = {0, 1};

vector<string> board;

string Solution() {
    string ans = "";
    ans += board[0][0];

    vector<pair<int, int>> cur_level;
    cur_level.push_back({0, 0});

    vector<vector<bool>> visited(N, vector<bool>(M, false));
    visited[0][0] = true;

    for(int i=0; i < N + M - 2; i++) {
        char min_c = 'z' + 1;
        vector<pair<int, int>> next_cands;

        for(const auto& pos: cur_level) {
            for(int i=0; i < 2; i++) {
                int next_y = pos.first + dy[i];
                int next_x = pos.second + dx[i];

                if(next_y >= N || next_x >= M || visited[next_y][next_x]) continue;

                visited[next_y][next_x] = true;
                next_cands.push_back({next_y, next_x});
            }
        }

        for(const auto& next: next_cands) {
            min_c = min(min_c, board[next.first][next.second]);
        }

        ans += min_c;

        vector<pair<int, int>> next_level;
        for(const auto& next: next_cands) {
            if(board[next.first][next.second] == min_c) {
                next_level.push_back(next);
            }
        }

        cur_level = next_level;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    board = vector<string>(N, "");

    for(int i=0; i < N; i++) {
        cin >> board[i];
    }

    cout << Solution() << '\n';
}
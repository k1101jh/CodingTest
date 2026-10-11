#include <iostream>
#include <vector>
#include <queue>
#include <array>
using namespace std;


int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};

vector<vector<int>> board, memo;

int solve(int N, int y, int x) {
    int& cur = memo[y][x];
    if(cur) {
        return cur;
    }
    for(int i=0; i < 4; i++) {
        int next_y = y + dy[i];
        int next_x = x + dx[i];
        if(next_y < 0 || next_x < 0 || next_y >= N || next_x >= N) continue;
        if(board[next_y][next_x] - board[y][x] == 1) {
            cur = 1 + solve(N, next_y, next_x);
            break;
        }
    }
    return cur;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    for(int t=1; t <= T; t++) {
        int N;
        cin >> N;

        board.assign(N, vector<int>(N));
        memo.assign(N, vector<int>(N, 0));

        for(int i=0; i < N; i++) {
            for(int j=0; j < N; j++) {
                cin >> board[i][j];
            }
        }

        int max_len = 0;
        int ans_point_val = 0;
        // pair<int, int> ans_start;
        for(int i=0; i < N; i++) {
            for(int j=0; j < N; j++) {
                int len = solve(N, i, j);

                if(len > max_len || (len == max_len && board[i][j] < ans_point_val)) {
                    max_len = len;
                    ans_point_val = board[i][j];
                }
            }
        }
        

        cout << "#" << t << " " << ans_point_val << " " << max_len + 1 << '\n';;
    }
}
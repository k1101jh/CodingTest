#include <iostream>
#include <vector>
using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<string> board(N, "");

    for(int i=0; i < N; i++) {
        cin >> board[i];
    }

    int ans = 0;

    for(int i=1; i < M; i++) {
        if(board[0][i - 1] != board[0][i]) {
            ans++;
        }
    }

    for(int i=1; i < N; i++) {
        for(int j=0; j < M; j++) {
            // 가로 검사
            if(j != 0 && board[i][j - 1] != board[i][j]) {
                ans++;
            }

            // 세로 검사
            if(i % 2 == 0) {
                if(j != 0 && board[i - 1][j - 1] != board[i][j]) {
                    ans++;
                }
                
                if(board[i - 1][j] != board[i][j]) {
                    ans++;
                }
            } else {
                if(board[i - 1][j] != board[i][j]) {
                    ans++;
                }

                if(j < M - 1 && board[i - 1][j + 1] != board[i][j]) {
                    ans++;
                }
            }
        }
    }

    cout << ans << '\n';
}
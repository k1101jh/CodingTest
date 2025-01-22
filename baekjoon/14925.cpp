#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int M, N;
vector<vector<int>> board;
vector<vector<int>> dp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> M >> N;

    board = vector<vector<int>>(M, vector<int>(N, 0));
    dp = vector<vector<int>>(M + 1, vector<int>(N + 1, 0));

    for(int i=0; i < M; i++) {
        for(int j=0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    int ans = 0;

    for(int i=1; i <= M; i++) {
        for(int j=1; j <= N; j++) {

            if(board[i - 1][j - 1] > 0) continue;

            dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;

            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans << '\n';
    
}
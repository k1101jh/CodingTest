#include <iostream>
using namespace std;

int N, M;
int board[1000][1000];
int dp[1000][1000];

int recursive(int y, int x) {
    if(y == N || x == M) {
        return 0;
    } else {
        int& ret = dp[y][x];
        if(ret == -1) {
            ret = board[y][x] + max(recursive(y + 1, x), max(recursive(y, x + 1), recursive(y + 1, x + 1)));
        }
        return ret;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fill(&dp[0][0], &dp[999][1000], -1);
    cin >> N >> M;

    for(int i=0; i < N; i++) {
        for(int j=0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    cout << recursive(0, 0) << '\n';
}
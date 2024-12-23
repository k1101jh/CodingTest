#include <iostream>
#include <vector>
using namespace std;

const int DIV_NUM = 1000000009;
vector<vector<int>> dp;

int Solution(int n, int a) {
    if(dp[n][a] == -1) {
        if(a == 1) {
            dp[n][a] = Solution(n - a, 2) + Solution(n - a, 3);
        } else if(a == 2) {
            dp[n][a] = Solution(n - a, 1) + Solution(n - a, 3);
        } else {
            dp[n][a] = Solution(n - a, 1) + Solution(n - a, 2);
        }
        
        dp[n][a] %= DIV_NUM;
    }

    return dp[n][a];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    dp = vector<vector<int>>(100001, vector<int>(4, -1));

    for(int i=1; i <= 2; i++) {
        dp[i][1] = 0;
        dp[i][2] = 0;
        dp[i][3] = 0;
    }

    dp[1][1] = 1;
    dp[2][2] = 1;
    dp[3][1] = 1;
    dp[3][2] = 1;
    dp[3][3] = 1;
    dp[4][1] = 2;
    dp[4][2] = 0;
    dp[4][3] = 1;

    while(T--) {
        int n;
        cin >> n;

        cout << (((Solution(n, 1) + Solution(n, 2)) % DIV_NUM) + Solution(n, 3)) % DIV_NUM << '\n';
    }
}

#include <iostream>
#include <vector>
using namespace std;

int N, K;

vector<int> nums;
vector<vector<int>> dp;
vector<vector<bool>> stair;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    nums = vector<int>(N, 0);
    dp = vector<vector<int>>(2, vector<int>(N, INT32_MAX));
    stair = vector<vector<bool>>(2, vector<bool>(N, false));

    for(int i=0; i < N; i++) {
        cin >> nums[i];
    }

    if(K > 3) {
        int len_stair = 1;
        for(int i=N - 2; i >= 0; i--) {
            if(abs(nums[i] - nums[i + 1]) == 1) {
                len_stair++;
            } else {
                len_stair = 1;
            }
            
            if(len_stair >= K) {
                stair[0][i] = true;
                stair[1][i + K - 1] = true;
            }
        }
    }

    // 왼쪽이나 오른쪽에서 최대 3개를 지우는 경우 연산은 1회
    for(int i=0; i < 3; i++) {
        dp[0][i] = 1;
        dp[1][N - 1 - i] = 1;
    }

    // 왼쪽이나 오른쪽에서 길이가 K인 계단 수열을 지우는 경우
    if(stair[1][K - 1]) dp[0][K - 1] = 1;
    if(stair[0][N - 1 - (K - 1)]) dp[1][N - 1 - (K - 1)] = 1;

    for(int i=3; i < N; i++) {
        if(i >= K) {
            if(stair[1][i]) dp[0][i] = dp[0][i - K] + 1;
            if(stair[0][N - 1 - i]) dp[1][N - 1 - i] = dp[1][N - 1 - i + K] + 1;
        }

        for(int j=1; j <= 3; j++) {
            dp[0][i] = min(dp[0][i], dp[0][i - j] + 1);
            dp[1][N - 1 - i] = min(dp[1][N - 1 - i], dp[1][N - 1 - i + j] + 1);
        }
    }

    int ans = INT32_MAX;

    ans = min(ans, dp[0][N - 1]);
    ans = min(ans, dp[1][0]);

    for(int mid = 1; mid < N; mid++) {
        ans = min(ans, dp[0][mid - 1] + dp[1][mid]);
    }

    // for(int i=1; i < N; i++) {
    //     cout << dp[0][i - 1] << ' ' << dp[1][i] << '\n';
    // }

    cout << ans << '\n';
}
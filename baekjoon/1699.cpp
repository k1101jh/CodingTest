#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    int V = sqrt(N);
    vector<int> dp(N + 1, INT32_MAX);

    dp[0] = 0;
    dp[1] = 1;

    for(int i=2; i <= N; i++) {
        for(int j=1; j * j <= i; j++) {
            int val = j * j;
            if(i - val < 0) {
                continue;
            }
            dp[i] = min(dp[i], dp[i - val] + 1);
        }
    }

    cout << dp[N] << '\n';

}
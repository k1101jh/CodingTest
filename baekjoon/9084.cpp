#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> coins;
vector<int> dp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> N;
        dp.assign(N, 0);
        coins.assign(N, 0);
        for(int i=0; i < N; i++) {
            cin >> coins[i];
        }

        cin >> M;
        dp.assign(M + 1, 0);

        dp[0] = 1;

        for(int i=0; i < N; i++) {
            int coin = coins[i];
            for(int j=0; j <= M - coin; j++) {
                dp[j + coin] += dp[j];
            }
        }
        cout << dp[M] << '\n';
    }

}
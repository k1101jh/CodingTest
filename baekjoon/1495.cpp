#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, S, M;
    cin >> N >> S >> M;

    vector<int> vols(N, 0);
    vector<unordered_set<int>> dp(N, unordered_set<int>());

    for(int i=0; i < N; i++) {
        cin >> vols[i];
    }

    if(S - vols[0] >= 0) dp[0].insert(S - vols[0]);
    if(S + vols[0] <= M) dp[0].insert(S + vols[0]);

    for(int i=1; i < N; i++) {
        for(const auto& prev: dp[i - 1]) {
            if(prev - vols[i] >= 0) {
                dp[i].insert(prev - vols[i]);
            }
            if(prev + vols[i] <= M) {
                dp[i].insert(prev + vols[i]);
            }
        }
    }

    int ans = -1;
    for(const auto& vol: dp[N - 1]) {
        ans = max(ans, vol);
    }
    cout << ans << '\n';
}
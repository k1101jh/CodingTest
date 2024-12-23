#include <iostream>
#include <vector>
using namespace std;

int N, K;
vector<int> A;
vector<bool> dp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    A = vector<int>(N, 0);
    dp = vector<bool>(N, false);

    for(int i=0; i < N; i++) {
        cin >> A[i];
    }

    dp[0] = true;

    for(int i=0; i < N; i++) {
        if(!dp[i]) continue;

        for(int j=i + 1; j < N; j++) {
            if(dp[j]) continue;

            if((j - i) * (1 + abs(A[i] - A[j])) <= K) {
                dp[j] = true;
            }
        }
    }

    if(dp[N - 1]) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }
}
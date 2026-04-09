#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long N, B, C;
    cin >> N;
    vector<long long> A(N, 0);
    long long ans = N;

    for(int i=0; i < N; i++) {
        cin >> A[i];
    }

    cin >> B >> C;

    for(int i=0; i < N; i++) {
        ans += max(0LL, ((A[i] - B) + C - 1) / C);
    }

    cout << ans << '\n';
}
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, N, K, inp, ans;
    cin >> T;

    while(T--) {
        cin >> N >> K;
        ans = 0;
        for(int i=0; i < N; i++) {
            cin >> inp;
            ans += inp / K;
        }
        cout << ans << '\n';
    }
}
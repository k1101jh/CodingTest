#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, s, n, q, p, ans = 0;
    cin >> t;
    while(t--) {
        cin >> s >> n;
        ans = s;

        while(n--) {
            cin >> q >> p;
            ans += q * p;
        }
        cout << ans << '\n';
    }
}
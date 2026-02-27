#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, n, m, ans=0;
    cin >> T;

    while(T--) {
        ans = 0;
        cin >> n >> m;
        for(int b=2; b < n; b++) {
            for(int a=1; a < b; a++) {
                if((a * a + b * b + m) % (a * b) == 0) {
                    ans++;
                }
            }
        }
        cout << ans << '\n';
    }
}
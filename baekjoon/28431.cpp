#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    const int N = 5;
    int inp = 0, bit = 0;

    for(int i=0; i < N; i++) {
        cin >> inp;
        if(bit & (1 << inp)) {
            bit ^= (1 << inp);
        } else {
            bit |= (1 << inp);
        }
    }

    int ans = -1;
    while(bit) {
        bit >>= 1;
        ans++;
    }

    cout << ans << '\n';
}
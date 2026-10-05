#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        int X;
        cin >> X;

        string ans = "";

        if(X == 1) {
            ans = "0";
        } else{
            if(X & 1) {
                ans += '4';
                X--;
            }
            while(X) {
                ans += '8';
                X -= 2;
            }
        }

        cout << ans << '\n';

    }
}
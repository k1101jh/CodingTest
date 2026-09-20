#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int TC;
    cin >> TC;

    while(TC--) {
        int X, Y;
        cin >> X >> Y;
        int b = (X - Y) >> 1;
        int a = X - b;
        cout << a << ' ' << b << '\n';

    }
}
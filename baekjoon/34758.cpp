#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int X, Y, N, x_i, y_i;
    cin >> X >> Y >> N;

    for(int i=0; i < N; i++) {
        cin >> x_i >> y_i;
        if(X != x_i && Y != y_i) {
            cout << 1 << '\n';
        } else {
            cout << 0 << '\n';
        }
    }
}
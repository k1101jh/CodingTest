#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, A, B;
    cin >> N >> M >> A >> B;

    int required = N * 3 - M;
    if(required > 0) {
        cout << required * A + B << '\n';
    } else {
        cout << 0 << '\n';
    }
}
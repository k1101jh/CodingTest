#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A, B, C;
    cin >> A >> B >> C;

    int left_interval = B - A;
    int right_interval = C - B;

    int ans = max(left_interval, right_interval) - 1;

    cout << ans << '\n';
}
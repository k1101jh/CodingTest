#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K, power_strip, num_available_N = 0;
    cin >> N >> K;

    for(int i=0; i < K; i++) {
        cin >> power_strip;
        num_available_N += (power_strip + 1) / 2;
    }

    if(N > num_available_N) {
        cout << "NO" << '\n';
    } else {
        cout << "YES" << '\n';
    }

}
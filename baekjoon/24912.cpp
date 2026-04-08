#include <iostream>
#include <vector>
using namespace std;

int get_diff_num(const int& a, const int& b) {
    if(a == b || b == 0) {
        return a % 3 + 1;
    } else {
        return 6 - a - b;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, a;
    cin >> N;

    vector<int> cards(N + 1, 0);

    for(int i=0; i < N; i++) {
        cin >> cards[i];
    }

    if(N == 1) {
        if(cards[0] == 0) {
            cards[0] = 1;
        }
    } else {
        if(cards[0] == 0) {
            cards[0] = (cards[1]) % 3 + 1;
        }
        int prev = cards[0];

        for(int i=1; i < N; i++) {
            if(cards[i] == 0) {
                cards[i] = get_diff_num(cards[i - 1], cards[i + 1]);
            } else if(cards[i] == prev) {
                cout << -1 << '\n';
                return 0;
            }
            prev = cards[i];
        }
    }

    for(int i=0; i < N; i++) {
        cout << cards[i] << ' ';
    }
}
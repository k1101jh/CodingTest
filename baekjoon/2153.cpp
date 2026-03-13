#include <iostream>
#include <cmath>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string inp;
    cin >> inp;

    int ans = 0;
    for(const auto& c: inp) {
        ans += c - 'A' >= 26 ? c - 'a' + 1 : c - 'A' + 27;
    }

    bool is_prime = true;
    if(ans != 2 && ans % 2 == 0) {
        is_prime = false;
    }
    for(int i=3; i <= sqrt(ans); i+=2) {
        if(ans % i == 0) {
            is_prime = false;
            break;
        }
    }

    if(is_prime) {
        cout << "It is a prime word." << '\n';
    } else {
        cout << "It is not a prime word." << '\n';
    }
}
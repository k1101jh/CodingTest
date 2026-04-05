#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    string s;

    cin >> n >> s;

    int num_2 = 0, num_e = 0;

    for(const auto& c : s) {
        if(c == '2') {
            num_2++;
        } else {
            num_e++;
        }
    }

    if(num_2 == num_e) {
        cout << "yee" << '\n';
    } else if(num_2 > num_e) {
        cout << 2 << '\n';
    } else {
        cout << 'e' << '\n';
    }
}
#include <iostream>
#include <sstream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int sum = 0;
    string S;
    cin >> S;

    istringstream iss(S);
    string S_buf;
    while(getline(iss, S_buf, ',')) {
        sum += stoi(S_buf);
    }

    cout << sum << '\n';
}
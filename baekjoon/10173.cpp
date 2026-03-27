#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    while(true) {
        getline(cin, s);
        if(s == "EOI") {
            break;
        }
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        size_t nPos = s.find("nemo");

        if(nPos != string::npos) {
            cout << "Found" << '\n';
        } else {
            cout << "Missing" << '\n';
        }
    }
}
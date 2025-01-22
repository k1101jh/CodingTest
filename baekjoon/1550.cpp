#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;

    int answer = 0;

    for(int i=0; i < s.length(); i++) {
        answer *= 16;
        if(s[i] < 'A') {
            answer += (s[i] - '0');
        } else {
            answer += (s[i] - 'A' + 10);
        }
    }

    cout << answer << '\n';
}
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s, word;
    getline(cin, s);
    getline(cin, word);

    int cnt = 0;
    for(int i=0; i < s.length(); i++) {
        int j = 0;
        while(j < word.length() && s[i + j] == word[j]) {
            j++;
        }
        if(j == word.length()) {
            cnt++;
            i += j - 1;
        }
    }
    cout << cnt << '\n';
}
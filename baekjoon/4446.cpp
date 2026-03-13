#include <iostream>
using namespace std;

const string consonant = "bkxznhdcwgpvjqtsrlmf";
const string vowel = "aiyeou";

char get_translated_c(char c) {
    bool is_lower_c = islower(c);
    c = tolower(c);

    if(c < 'a' || c > 'z') return c;

    size_t pos = vowel.find(c);
    if(pos != string::npos) {
        c = vowel[(pos + 3) % vowel.length()];
    } else {
        pos = consonant.find(c);
        c = consonant[(pos + 10) % consonant.length()];
    }
    return  is_lower_c ? c : toupper(c);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s = "";
    while(getline(cin, s)) {
        for(int i=0; i < s.length(); i++) {
            cout << get_translated_c(s[i]);
        }
        cout << '\n';
    }
}
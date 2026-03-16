#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    string inp;
    cin >> N;

    while(N--) {
        cin >> inp;

        int position, cur_position = 0;

        int h_m_s[3] = {0};
        string h_m_s_str[3] = {""};

        h_m_s[0] = stoi(inp.substr(0, 2));
        h_m_s[1] = stoi(inp.substr(3, 5));
        h_m_s[2] = stoi(inp.substr(6, 8));

        for(int i=0; i < 3; i++) {
            for(int j=5; j >= 0; j--) {
                h_m_s_str[i] += (h_m_s[i] >> j & 1) + '0';
            }
        }

        for(int i=0; i < 6; i++) {
            for(int j=0; j < 3; j++) {
                cout << h_m_s_str[j][i];
            }
        }
        cout << ' ';

        for(int i=0; i < 3; i++) {
            for(int j=0; j < 6; j++) {
                cout << h_m_s_str[i][j];
            }
        }

        cout << '\n';

    }
}
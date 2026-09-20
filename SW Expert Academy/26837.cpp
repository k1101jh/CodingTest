#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int TC, N;
    string S;
    cin >> TC;

    while(TC--) {
        cin >> N >> S;
        int ans = 0;
        map<pair<int, int>, int> m;
        m[{0, 0}] = 1;

        int cnt1 = 0;
        int cnt2 = 0;
        for(int i=0; i < N; i++) {
            if(S[i] == 'A') cnt1++;
            else if(S[i] == 'T') cnt1--;
            else if(S[i] == 'C') cnt2++;
            else if(S[i] == 'G') cnt2--;

            ans += m[{cnt1, cnt2}];
            m[{cnt1, cnt2}]++;
        }
        cout << ans << '\n';
    }
}
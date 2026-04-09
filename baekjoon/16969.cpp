#include <iostream>
using namespace std;

long long LIMIT = 1000000009LL;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string inp;
    cin >> inp;

    long long ans = 1;
    for(int i=0; i < inp.length(); i++) {
        int j=0;
        while(i + j < inp.length() && inp[i] == inp[i + j]) {
            j++;
        }
        
        long long num_cand;
        if(inp[i] == 'd') {
            num_cand = 10;
        } else {
            num_cand = 26;
        }

        if(j) {
            ans *= num_cand;
            ans %= LIMIT;
        }
        for(int k=1; k < j; k++) {
            ans *= num_cand - 1;
            ans %= LIMIT;
        }

        ans = (ans + LIMIT) % LIMIT;
        i += j - 1;
    }

    cout << ans << '\n';
}
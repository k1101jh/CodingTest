#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, ans = 0;
    cin >> N;

    string N_s = to_string(N);
    string s = "";
    
    for(int i=1; i <= N; i++) {
        s += to_string(i);
    }

    cout << s.find(N_s) + 1 << '\n';
}
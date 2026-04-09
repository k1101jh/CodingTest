#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string jinho, inp;
    int N, ans = 0;

    cin >> jinho >> N;

    for(int i=0; i < N; i++) {
        cin >> inp;
        if(inp == jinho) {
            ans++;
        }
    }
    cout << ans << '\n';
}
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> dp1(N, 1);
    vector<int> dp2(N, 1);
    vector<int> vec(N, 0);

    for(int i=0; i < N; i++) {
        cin >> vec[i];
    }

    for(int i=1; i < N; i++) {
        if(vec[i - 1] < vec[i]) {
            dp1[i] = dp1[i - 1] + 1;
        }
    }
    for(int i=N - 2; i >= 0; i--) {
        if(vec[i] > vec[i + 1]) {
            dp2[i] = dp2[i + 1] + 1;
        }
    }

    int ans = 0;
    for(int i=0; i < N; i++) {
        ans = max(ans, dp1[i] + dp2[i] - 1);
    }

    cout << ans << '\n';
}
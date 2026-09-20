#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, C;
vector<int> X;
vector<vector<int>> dp;

void solution() {
    int left = 1;
    int right = X[N - 1] - X[0];
    int mid = (left + right) >> 1;

    int ans = INT32_MIN;
    while(left <= right) {
        mid = (left + right) >> 1;

        // 계산
        int prev = X[0];
        int cnt = 1;
        
        for(int i=1; i < N; i++) {
            if(X[i] - prev >= mid) {
                cnt++;
                prev = X[i];
            }
        }
            
        if(cnt >= C) {
            ans = max(ans, mid);
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> C;
    X.assign(N, 0);

    for(int i=0; i < N; i++) {
        cin >> X[i]; 
    }

    sort(X.begin(), X.end());

    solution();

}
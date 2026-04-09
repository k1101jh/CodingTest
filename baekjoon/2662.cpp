#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    vector<vector<int>> benefits(N + 1, vector<int>(M, 0));
    vector<vector<int>> dp(N + 1, vector<int>(M, 0));
    vector<vector<int>> trace(N + 1, vector<int>(M, 0));

    int temp;
    for(int i=1; i <= N; i++) {
        cin >> temp;
        for(int j=0; j < M; j++) {
            cin >> benefits[i][j];
        }
    }

    // 0번 기업 초기화
    for(int i=0; i <= N; i++) {
        dp[i][0] = benefits[i][0];
        trace[i][0] = i;
    }

    for(int i=0; i < M - 1; i++) {
        for(int j=1; j <= N; j++) {
            for(int k=0; k <= j; k++) {
                // i+1번째 기업에서 k원을 썼을 때 얻을 수 있는 이익 계산
                int cur_benefit = benefits[k][i + 1] + dp[j - k][i];
                if(dp[j][i + 1] < cur_benefit) {
                    dp[j][i + 1] = cur_benefit;
                    trace[j][i + 1] = k;
                }
            }
        }
    }
    
    cout << *max_element(dp[N].begin(), dp[N].end()) << '\n';

    vector<int> result(M, 0);

    int cur_remain = N;
    for(int i=M - 1; i >= 0; i--) {
        result[i] = trace[cur_remain][i];
        cur_remain -= result[i];
    }

    for(const auto& element: result) {
        cout << element << ' ';
    }
}
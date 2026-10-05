#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int TC;
    cin >> TC;
    while(TC--) {
        int N;
        cin >> N;

        vector<pair<int, int>> TDs(N, {0, 0});
        
        for(int i=0; i < N; i++) {
            cin >> TDs[i].second >> TDs[i].first;
        }

        sort(TDs.begin(), TDs.end());
        // TDs.push_back({1, 0});

        int remain = 0;
        int ans = TDs[N - 1].first;
        for(int i=N - 1; i > 0; i--) {
            // 필요 시간
            int cur_req = TDs[i].second;
            // 기한
            int cur_limit = TDs[i].first;
            // 이번 과제 기한 - 다음 과제 기한
            // 이 사이에는 이번 과제 시간 + 이전 과제에서 필요했던 시간 만큼을 충족 가능
            int remain_time = cur_limit - TDs[i - 1].first;
            int cur_remain = cur_req + remain - remain_time;

            // 총 수행해야 하는 과제 양보다 시간이 많았으면 남은 과제 양 0으로 설정
            // cout << "day: " << cur_limit << " " << cur_remain << '\n';
            if(cur_remain < 0) cur_remain = 0;

            remain = cur_remain;
            
        }

        // 얼마나 쉴 수 있는지 계산
        int cur_req = TDs[0].second;
        int cur_limit = TDs[0].first;

        // 첫 과제의 기한 - 시작 날짜
        int remain_time = cur_limit - 0;
        // 남은 시간동안 모든 과제를 끝내야 함
        // 음수가 되면? 그 시간동안은 과제를 하지 않아도 됨
        int cur_remain = cur_req + remain - remain_time;
        
        cout << -cur_remain << '\n';
    }
}
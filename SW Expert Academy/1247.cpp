#include <iostream>
#include <vector>
#include <stack>
#include <cstdint>
#include <array>
using namespace std;


int get_dist(const pair<int, int>& a, const pair<int, int>& b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

// N <= 10
int dfs(const int N, const vector<pair<int, int>>& customers, pair<int, int> start, pair<int, int> dest) {
    // 각 상태 최소비용 저장
    vector<vector<int>> memo(1 << N, vector<int>(N, INT32_MAX));

    stack<array<int, 3>> s;
    for(int i=0; i < N; i++) {
        int d = get_dist(start, customers[i]);
        memo[1 << i][i] = d;
        s.push({1 << i, d, i});
    }
    
    int ans = INT32_MAX;
    while(!s.empty()) {
        int cur_mask = s.top()[0];
        int cur_dist = s.top()[1];
        int cur = s.top()[2];
        s.pop();

        if(cur_dist > memo[cur_mask][cur]) continue;

        if(cur_mask == (1 << N) - 1) {
            ans = min(ans, cur_dist + get_dist(customers[cur], dest));
            continue;
        }

        for(int i=0; i < customers.size(); i++) {
            int next_bit = (1 << i);
            if(cur_mask & next_bit) continue;
            int next_mask = cur_mask | next_bit;

            int next_dist = get_dist(customers[cur], customers[i]) + cur_dist;

            if(memo[next_mask][i] <= next_dist) continue;
            memo[next_mask][i] = next_dist;

            s.push({cur_mask | next_bit, next_dist, i});
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int TC;
    cin >> TC;
    for(int tc=1; tc <= TC; tc++) {
        int N;
        cin >> N;

        pair<int, int> company, house;
        cin >> company.first >> company.second >> house.first >> house.second;

        vector<pair<int, int>> customers(N, {0, 0});

        for(int i=0; i < N; i++) {
            cin >> customers[i].first >> customers[i].second;
        }

        int ans = dfs(N, customers, company, house);

        cout << "#" << tc << " " << ans << '\n';
    }
}
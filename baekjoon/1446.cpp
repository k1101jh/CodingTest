#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, D;
vector<vector<pair<int, int>>> roads;
vector<int> dists;

void Solution() {
    dists[0] = 0;

    for(int i=1; i <= D; i++) {
        dists[i] = min(dists[i], dists[i - 1] + 1);

        if(roads[i].size() == 0) continue;

        for(const auto& prev_info: roads[i]) {
            dists[i] = min(dists[i], dists[prev_info.first] + prev_info.second);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> D;

    roads = vector<vector<pair<int, int>>>(D + 1, vector<pair<int, int>>());
    dists = vector<int>(D + 1, INT32_MAX);

    int start, dest, dist;

    for(int i=0; i < N; i++) {
        cin >> start >> dest >> dist;
        if(dest > D) continue;
        roads[dest].push_back({start, dist});
    }

    Solution();

    cout << dists[D] << '\n';
}
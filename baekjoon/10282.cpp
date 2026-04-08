#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, d, c;

vector<vector<pair<int, int>>> edges;
vector<int> dists;

void Dijkstra(int start) {
    dists = vector<int>(n, INT32_MAX);
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    dists[start] = 0;

    int ans = 0;
    int cnt = 1;

    while(!pq.empty()) {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if(dists[cur] < cost) {
            continue;
        }

        ans = cost;

        for(const auto& edge: edges[cur]) {
            int next_cost = cost + edge.second;
            if(dists[edge.first] > next_cost) {
                if(dists[edge.first] == INT32_MAX) {
                    cnt++;
                }
                dists[edge.first] = next_cost;
                pq.push({-next_cost, edge.first});
            }
        }
    }
    cout << cnt << ' ' << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, a, b, s;
    cin >> t;
    while(t--) {
        cin >> n >> d >> c;
        edges.assign(n, vector<pair<int, int>>());
        for(int i=0; i < d; i++) {
            cin >> a >> b >> s;
            edges[b - 1].push_back({a - 1, s});
        }

        Dijkstra(c - 1);
    }
}
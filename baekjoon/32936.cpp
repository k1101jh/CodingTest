#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, a, b, c;
vector<vector<int>> graph;
vector<int> times;

void BFS(int start) {
    vector<bool> visited(N + 1, false);
    times.assign(N + 1, INT32_MAX);
    queue<pair<int, int>> q;
    q.push({start, 0});
    visited[start] = true;

    while(!q.empty()) {
        int cur = q.front().first;
        int cur_time = q.front().second;
        q.pop();

        if(times[cur] < cur_time) {
            continue;
        }
        times[cur] = cur_time;

        for(auto& next : graph[cur]) {
            if(visited[next]) continue;
            
            visited[next] = true;
            q.push({next, cur_time + 1});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> a >> b >> c;

    graph = vector<vector<int>>(N + 1, vector<int>());

    int u, v;
    for(int i=0; i < M; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
    }

    BFS(1);
    int time_1_to_a = times[a];
    int time_1_to_N = times[N];

    BFS(b);
    int time_b_to_N = times[N];
    int time_b_to_a = times[a];

    bool can_reach_direct = (time_1_to_N != INT32_MAX);
    bool can_reach_with_machine = (time_1_to_a != INT32_MAX && time_b_to_N != INT32_MAX);
    
    if(!can_reach_direct && !can_reach_with_machine) {
        cout << "x" << '\n';
    } else if(can_reach_with_machine && time_b_to_a < c) {
        cout << "-inf" << '\n';
    } else {
        if(can_reach_with_machine) {
            cout << min(time_1_to_N, time_1_to_a + time_b_to_N - c) << '\n';
        } else {
            cout << time_1_to_N << '\n';
        }
    }
}
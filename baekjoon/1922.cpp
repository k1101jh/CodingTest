#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<pair<int,int>>> parents;

int Prim() {
    vector<bool> added(N + 1, false);
    vector<int> min_dists(N + 1, INT32_MAX);

    int return_val = 0;

    // 1번 노드 추가
    min_dists[1] = 0;

    for(int i=0; i < N; i++) {
        // 다음에 추가할 정점 찾기
        int cur = -1;
        int min_cost = INT32_MAX;
        for(int next_node=1; next_node <= N; next_node++) {
            if(added[next_node]) continue;

            if(min_cost > min_dists[next_node]) {
                cur = next_node;
                min_cost = min_dists[next_node];
            }
        }

        added[cur] = true;
        return_val += min_cost;

        for(auto& next_node: parents[cur]) {
            if(added[next_node.first]) continue;

            if(min_dists[next_node.first] > next_node.second) {
                min_dists[next_node.first] = next_node.second;
            }
        }
    }
    return return_val;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    parents = vector<vector<pair<int, int>>>(N + 1, vector<pair<int, int>>());

    int a, b, c;
    for(int i=0; i < M; i++) {
        cin >> a >> b >> c;

        parents[a].push_back({b, c});
        parents[b].push_back({a, c});
    }

    cout << Prim() << '\n';
}
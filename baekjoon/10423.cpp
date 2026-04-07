#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K;

vector<int> powerplants;
vector<pair<int, pair<int, int>>> edges;
vector<int> roots;
vector<int> ranks;

int num_remains = 0;

int Find(int n) {
    if(roots[n] == n) {
        return n;
    }
    return roots[n] = Find(roots[n]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);

    if(a == b) { 
        return;
    }
    if(ranks[a] < ranks[b]) {
        roots[a] = b;
    } else {
        roots[b] = a;
        if(ranks[a] == ranks[b]) {
            ranks[a]++;
        }
    }
}

void Kruskal() {
    int ans = 0;
    int cnt = 0;

    for(const auto& edge: edges) {
        if(Find(edge.second.first) != Find(edge.second.second)) {
            Union(edge.second.first, edge.second.second);
            ans += edge.first;
            cnt++;
            if(cnt == num_remains) {
                break;
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;

    num_remains = N - K;

    powerplants.assign(K, 0);
    roots.assign(N, 0);
    ranks.assign(N, 0);
    edges.assign(M, {0, {0, 0}});

    for(int i=0; i < N; i++) {
        roots[i] = i;
    }

    int u, v, w;
    for(int i=0; i < K; i++) {
        cin >> u;
        powerplants[i] = u - 1;
    }

    for(int i=1; i < K; i++) {
        Union(powerplants[0], powerplants[i]);
    }

    for(int i=0; i < M; i++) {
        cin >> u >> v >> w;
        edges[i] = {w, {u - 1, v - 1}};
    }

    sort(edges.begin(), edges.end());

    Kruskal();
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
using namespace std;

// vector<vector<int>> graph;
vector<array<long long, 3>> edges;
vector<int> roots, ranks;

int Find(int n) {
    if(roots[n] == n) return n;
    return roots[n] = Find(roots[n]);
}

bool Union(int a, int b) {
    a = Find(a);
    b = Find(b);

    if(a == b) {
        return false;
    }

    if(ranks[a] < ranks[b]) {
        roots[a] = b;
        
    } else {
        roots[b] = a;
        if(ranks[a] == ranks[b]) {
            ranks[a]++;
        }
    }
    return true;
}

long long Kruskal(int V) {
    int cnt = 0;;
    long long ans = 0;

    for(auto& edge: edges) {
        long long c = edge[0];
        long long a = edge[1];
        long long b = edge[2];

        if(Find(a) != Find(b)) {
            if(Union(a, b)) {
                cnt++;
                ans += c;
            }

        }
        if(cnt == V - 1) break;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    for(int test_case=1; test_case <= T; test_case++) {
        int V, E;
        cin >> V >> E;

        edges.assign(E, {0, 0, 0});
        roots.assign(V + 1, 0);
        ranks.assign(V + 1, 0);

        int a, b, c;
        for(int i=0; i < E; i++) {
            cin >> a >> b >> c;
            edges[i] = {c, a, b};
        }

        sort(edges.begin(), edges.end());

        for(int i=1; i <= V; i++) {
            roots[i] = i;
        }

        long long ans = Kruskal(V);
        cout << "#" << test_case << " " << ans << '\n';
    }
}
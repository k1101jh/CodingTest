#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

vector<pair<int, pair<int, int>>> edges;
vector<int> roots;
vector<int> ranks;

int Find(int n) {
    if(roots[n] == n) {
        return roots[n];
    }
    return roots[n] = Find(roots[n]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);

    if(a == b) {
        return;
    } else {
        if(ranks[a] < ranks[b]) {
            roots[a] = b;
        } else {
            roots[b] = a;
            if(ranks[a] == ranks[b]) {
                ranks[a]++;
            }
        }
    }
}

int Kruskal() {
    int ans = 0;
    
    roots.assign(N + 1, 0);
    ranks.assign(N + 1, 0);

    for(int i=0; i < N + 1; i++) {
        roots[i] = i;
    }

    for(const auto& edge : edges) {
        if(Find(edge.second.first) != Find(edge.second.second)) {
            Union(edge.second.first, edge.second.second);
            ans += edge.first;
        }
    }
    return ans * ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    int A, B, C;

    for(int i=0; i < M + 1; i++) {
        cin >> A >> B >> C;
        edges.push_back({1 - C, {A, B}});
    }

    sort(edges.begin(), edges.end());    
    int best_result = Kruskal();

    sort(edges.begin(), edges.end(), greater<pair<int, pair<int, int>>>());
    int worst_result = Kruskal();

    cout << worst_result - best_result << '\n';
}
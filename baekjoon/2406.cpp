#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;

vector<pair<int, pair<int, int>>> edges;
vector<int> roots;
vector<int> ranks;

int num_components = n - 1;

int Find(int n) {
    if(roots[n] == n) {
        return n;
    } else {
        return roots[n] = Find(roots[n]);
    }
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

void Kruskal() {
    int ans = 0;
    int cnt = 0;
    vector<pair<int, int>> pairs;
    for(const auto& edge : edges) {
        if(num_components == 1) break;
        if(Find(edge.second.first) != Find(edge.second.second)) {
            if(Union(edge.second.first, edge.second.second)) {
                num_components--;
            }

            ans += edge.first;
            cnt++;
            pairs.push_back(edge.second);
        }
    }
    cout << ans << ' ' << cnt << '\n';

    for(const auto& pair: pairs) {
        cout << pair.first + 1 << ' ' << pair.second + 1 << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    ranks = vector<int>(n, 0);
    roots = vector<int>(n, 0);

    for(int i=0; i < n; i++) {
        roots[i] = i;
    }

    int x, y;
    for(int i=0; i < m; i++) {
        cin >> x >> y;
        Union(y - 1, x - 1);
        num_components--;
    }

    int cost;
    for(int i=0; i < n; i++) {
        for(int j=0; j < n; j++) {
            cin >> cost;
            if(i < j && i != 0) {
                edges.push_back({cost, {i, j}});
            }
        }
    }

    sort(edges.begin(), edges.end());

    Kruskal();

}
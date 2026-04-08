#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N, M;

vector<pair<int, int>> nodes;
vector<pair<double, pair<int, int>>> edges;
vector<int> roots;
vector<int> ranks;

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

double Kruskal() {
    int cnt = 0;
    double ans = 0;

    for(const auto& edge : edges) {
        if(Find(edge.second.first) != Find(edge.second.second)) {
            Union(edge.second.first, edge.second.second);
            ans += edge.first;
            cnt++;
            if(cnt == N - 1) {
                break;
            }
        }
    }

    return ans;
}

double GetDist(const pair<int, int>& a, const pair<int, int>& b) {
    long long dx = (long long)a.first - b.first;
    long long dy = (long long)a.second - b.second;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    nodes.assign(N, {0, 0});
    roots = vector<int>(N, 0);
    ranks = vector<int>(N, 0);

    for(int i=0; i < N; i++) {
        roots[i] = i;
    }

    int X, Y;
    for(int i=0; i < N; i++) {
        cin >> X >> Y;
        nodes[i] = {X, Y};
    }

    for(int i=0; i < M; i++) {
        cin >> X >> Y;
        edges.push_back({0, {X - 1, Y - 1}});
    }

    for(int i=0; i < N; i++) {
        for(int j=i + 1; j < N; j++) {
            edges.push_back({GetDist(nodes[i], nodes[j]), {i, j}});
        }
    }

    sort(edges.begin(), edges.end());

    cout << fixed;
    cout.precision(2);

    cout << Kruskal() << '\n';
}
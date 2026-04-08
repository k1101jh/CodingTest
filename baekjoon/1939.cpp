#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;

vector<pair<int, pair<int, int>>> bridges;

vector<int> roots;
vector<int> ranks;

int Find(int a) {
    if(roots[a] == a) {
        return a;
    }

    return roots[a] = Find(roots[a]);
}

void Merge(int a, int b) {
    a = Find(a);
    b = Find(b);

    if(a == b) return;
    if(ranks[a] > ranks[b]) roots[b] = a;
    else {
        roots[a] = b;
        if(ranks[a] == ranks[b]) {
            ranks[b]++;
        }
    }
}

int Kruskal(int A, int B) {
    for(auto& bridge : bridges) {
        int cost = bridge.first;
        int start = bridge.second.first;
        int end = bridge.second.second;

        if(Find(start) != Find(end)) {
            Merge(start, end);
        }

        if(Find(A) == Find(B)) {
            return cost;
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    bridges = vector<pair<int, pair<int, int>>>(M, {0, {0, 0}});
    roots = vector<int>(N, 0);
    ranks = vector<int>(N, 0);

    for(int i=0; i < N; i++) {
        roots[i] = i;
    }
    
    int A, B, C;
    for(int i=0; i < M; i++) {
        cin >> A >> B >> C;
        A--;
        B--;
        bridges[i] = {C, {A, B}};
    }

    sort(bridges.begin(), bridges.end(), greater<pair<int, pair<int, int>>>());

    cin >> A >> B;
    cout << Kruskal(A - 1, B - 1) << '\n';
}
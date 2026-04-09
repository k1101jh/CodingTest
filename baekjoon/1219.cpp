#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long LL_MAX = 1e18;
const long long LL_MIN = -1e18;
vector<long long> money;
vector<long long> incomes;
vector<pair<long long, pair<int, int>>> graph;
int N, S, D, M;

void BellmanFord() {
    money.assign(N, LL_MIN);
    money[S] = incomes[S];

    for(int i=0; i < N; i++) {
        for(const auto& edge: graph) {
            long long cost = edge.first;
            int cur = edge.second.first;
            int next = edge.second.second;
            if(money[cur] != LL_MIN && money[next] < money[cur] - cost + incomes[next]) {
                money[next] = money[cur] - cost + incomes[next];
            }
        }
    }

    vector<long long> temp(money.begin(), money.end());
    for(int i=0; i < N; i++) {
        for(const auto& edge: graph) {
            long long cost = edge.first;
            int cur = edge.second.first;
            int next = edge.second.second;

            if(temp[cur] == LL_MIN) continue;

            if(temp[cur] == LL_MAX) {
                temp[next] = LL_MAX;
            } else if(temp[next] < temp[cur] - cost + incomes[next]) {
                temp[next] = LL_MAX;
            }
        }
    }

    if(money[D] == LL_MIN) {
        cout << "gg" << '\n';
    } else if(temp[D] == LL_MAX) {
        cout << "Gee" << '\n';
    } else {
        cout << money[D] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> S >> D >> M;

    incomes.assign(N, 0);
    graph.assign(M, {0, {0, 0}});

    int start, end, cost;
    for(int i=0; i < M; i++) {
        cin >> start >> end >> cost;
        graph[i] = {cost, {start, end}};
    }
    for(int i=0; i < N; i++) {
        cin >> incomes[i];
    }

    BellmanFord();
}
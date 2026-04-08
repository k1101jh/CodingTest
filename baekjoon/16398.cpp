#include <iostream>
#include <vector>
using namespace std;

int N;

vector<vector<int>> board;

long long Prim() {
    vector<bool> added(N, false);
    vector<int> min_costs(N, INT32_MAX);

    long long cost_sum = 0;

    // 0번 노드 선택
    min_costs[0] = 0;
    
    for(int i=0; i < N; i++) {
        int cur = -1;
        long long cost = INT32_MAX;
        for(int next=0; next < N; next++) {
            if(added[next]) continue;

            if(cost > min_costs[next]) {
                cur = next;
                cost = min_costs[next];
            }
        }

        added[cur] = true;
        cost_sum += cost;

        for(int next=0; next < N; next++) {
            if(next == cur) continue;
            if(added[next]) continue;

            min_costs[next] = min(min_costs[next], board[cur][next]);
        }
    }

    return cost_sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    board = vector<vector<int>>(N, vector<int>(N, 0));

    for(int i=0; i < N; i++) {
        for(int j=0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    cout << Prim() << '\n';
}
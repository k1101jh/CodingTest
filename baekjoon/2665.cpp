#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};
vector<string> board;
vector<vector<int>> costs;

int Dijkstra(pair<int, int> start) {
    costs = vector<vector<int>>(n, vector<int>(n, INT32_MAX));
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({0, start});
    costs[0][0] = 0;

    while(!pq.empty()) {
        int cost = -pq.top().first;
        pair<int, int> here = pq.top().second;
        pq.pop();

        if(cost > costs[here.first][here.second]) {
            continue;
        }

        if(here.first == n - 1 && here.second == n - 1) {
            break;
        }

        for(int i=0; i < 4; i++) {
            int next_y = here.first + dy[i];
            int next_x = here.second + dx[i];
            if(next_x < 0 || next_x >= n || next_y < 0 || next_y >= n) {
                continue;
            }

            int next_cost = cost;
            if(board[next_y][next_x] == '0') {
                next_cost += 1;
            }

            if(costs[next_y][next_x] > next_cost) {
                costs[next_y][next_x] = next_cost;
                pq.push({-next_cost, {next_y, next_x}});
            }
        }
    }

    return costs[n - 1][n - 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    board = vector<string>(n, "");

    for(int i=0; i < n; i++) {
        cin >> board[i];
    }
    
    cout << Dijkstra({0, 0}) << '\n';
}
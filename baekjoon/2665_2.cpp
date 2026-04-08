#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};
vector<string> board;
vector<vector<int>> costs;

int BFS(pair<int, int> start) {
    deque<pair<int, pair<int, int>>> dq;
    costs = vector<vector<int>>(n, vector<int>(n, INT32_MAX));
    dq.push_back({0, start});

    while(!dq.empty()) {
        int cost = dq.front().first;
        pair<int, int> here = dq.front().second;
        dq.pop_front();

        for(int i=0; i < 4; i++) {
            int next_y = here.first + dy[i];
            int next_x = here.second + dx[i];
            if(next_y < 0 || next_y >= n || next_x < 0 || next_x >= n) {
                continue;
            }

            int add_cost = 0;
            if(board[next_y][next_x] == '0') {
                add_cost = 1;
            }
            int next_cost = cost + add_cost;
            if(costs[next_y][next_x] > next_cost) {
                costs[next_y][next_x] = next_cost;
                if(add_cost == 0) {
                    dq.push_front({next_cost, {next_y, next_x}});
                } else {
                    dq.push_back({next_cost, {next_y, next_x}});
                }
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
    
    cout << BFS({0, 0}) << '\n';
}
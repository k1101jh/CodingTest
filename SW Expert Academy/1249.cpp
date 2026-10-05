#include<iostream>
#include <vector>
#include <queue>
using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};

int bfs(const int& N, vector<vector<int>>& board) {
    priority_queue<pair<int, pair<int, int>>> pq;
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    pq.push({0, {0, 0}});
    visited[0][0] = true;

    int ans = -1;

    while(!pq.empty()) {
        int cur_time = -pq.top().first;
        pair<int, int> cur = pq.top().second;
        pq.pop();

        // if(visited[cur.first][cur.second]) continue;
        
        for(int i=0; i < 4; i++) {
            pair<int, int> next = {cur.first + dy[i], cur.second + dx[i]};
            if(next.first < 0 || next.second < 0 || next.first >= N || next.second >= N || visited[next.first][next.second]) {
                continue;
            }
            int next_time = cur_time + board[next.first][next.second];
            if(next.first == N - 1 && next.second == N - 1) {
                ans = next_time;
                return ans;
            }
            pq.push({-next_time, next});
            visited[cur.first][cur.second] = true;
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int TC;
    cin >> TC;

    for(int tc=1; tc <= TC; tc++) {
        int N;
        cin >> N;

        char inp;
        vector<vector<int>> board(N, vector<int>(N, 0));
        for(int i=0; i < N; i++) {
            for(int j=0; j < N; j++) {
                cin >> inp;
                board[i][j] = inp - '0';
            }
        }

        int answer = bfs(N, board);
        cout << "#" << tc << " " << answer << '\n';

    }
}
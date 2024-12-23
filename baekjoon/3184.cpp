#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<string> board;
vector<vector<bool>> visited;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int BFS(pair<int, int> start) {
    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = true;

    int num_sheeps = 0;
    int num_wolves = 0;

    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        if(board[cur.first][cur.second] == 'v') {
            num_wolves++;
        } else if(board[cur.first][cur.second] == 'o') {
            num_sheeps++;
        }

        for(int i=0; i < 4; i++) {
            pair<int, int> next = {cur.first + dy[i], cur.second + dx[i]};
            if(visited[next.first][next.second]) continue;
            if(board[next.first][next.second] == '#') continue;

            q.push(next);
            visited[next.first][next.second] = true;
        }
    }

    if(num_wolves >= num_sheeps) return -num_wolves;
    return num_sheeps;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int R, C;
    cin >> R >> C;

    board = vector<string>(R, "");

    for(int i=0; i < R; i++) {
        cin >> board[i];
    }

    int num_sheeps = 0;
    int num_wolves = 0;

    visited = vector<vector<bool>>(R, vector<bool>(C, false));

    for(int i=0; i < R; i++) {
        for(int j=0; j < C; j++) {
            if(visited[i][j]) continue;
            if(board[i][j] == '#' || board[i][j] == '.') continue;

            int cnt = BFS({i, j});
            if(cnt < 0) {
                num_wolves -= cnt;
            } else {
                num_sheeps += cnt;
            }
        }
    }

    cout << num_sheeps << ' ' << num_wolves << '\n';
}
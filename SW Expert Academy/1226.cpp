#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};
const int SIZE = 16;

vector<vector<char>> board;
vector<vector<bool>> visited;

bool bfs(const pair<int, int>& start, const pair<int, int>& end) {
    visited.assign(SIZE, vector<bool>(SIZE, false));
    queue<pair<int, int>> q;

    q.push(start);
    visited[start.first][start.second] = true;

    bool valid = false;

    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        if(cur.first == end.first && cur.second == end.second) {
            valid = true;
            break;
        }

        for(int i=0; i < 4; i++) {
            pair<int, int> next = {cur.first + dy[i], cur.second + dx[i]};
            if(next.first < 0 || next.second < 0 || next.first >= SIZE || next.second >= SIZE || visited[next.first][next.second] || board[next.first][next.second] == '1') continue;
            visited[next.first][next.second] = true;
            q.push(next);
        }
    }

    return valid;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T = 10;
    while(T--) {
        board.assign(SIZE, vector<char>(SIZE, 0));
        int test_case;
        cin >> test_case;
        // cout << "TEST case" << test_case << '\n';

        pair<int, int> start, end;

        for(int i=0; i < SIZE; i++) {
            for(int j=0; j < SIZE; j++) {
                cin >> board[i][j];

                if(board[i][j] == '2') {
                    start = {i, j};
                } else if(board[i][j] == '3') {
                    end = {i, j};
                }
            }
        }

        int valid_num = bfs(start, end) ? 1 : 0;

        cout << "#" << test_case << " " << valid_num << '\n';
    }
}
#include <iostream>
#include <queue>
using namespace std;

template <typename T>
pair<T, T> operator+(const pair<T, T>& l, const pair<T, T>& r) {
    return {l.first + r.first, l.second + r.second};
}

bool is_available(const int& h, const int& w, const pair<int, int>& pos) {
    return (pos.first >= 0 && pos.second >= 0 && pos.first < h && pos.second < w);
}

void bfs(const int& h, const int& w, vector<vector<int>>& board, vector<vector<bool>>& visited, const int& start_y, const int& start_x) {
    const static pair<int, int> directions[8] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    queue<pair<int, int>> q;
    q.push({start_y, start_x});

    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        for(int i=0; i < 8; i++) {
            pair<int, int> next = cur + directions[i];
            if(is_available(h, w, next)) {
                if(board[next.first][next.second] != 0 && !visited[next.first][next.second]) {
                    q.push(next);
                    visited[next.first][next.second] = true;
                }
            }
        }
    }
}

int bfs_all(const int& h, const int& w, vector<vector<int>>& board, vector<vector<bool>>& visited) {
    int num_land = 0;
    for(int i=0; i < h; i++) {
        for(int j=0; j < w; j++) {
            if(board[i][j] != 0 && !visited[i][j]) {
                visited[i][j] = true;
                bfs(h, w, board, visited, i, j);
                num_land++;
            }
        }
    }

    return num_land;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int w, h;
    cin >> w >> h;

    while(w != 0 && h != 0) {
        vector<vector<bool>> visited(h, vector<bool>(w, false));
        vector<vector<int>> board(h, vector<int>(w, 0));

        for(int i=0; i < h; i++) {
            for(int j=0; j < w; j++) {
                cin >> board[i][j];
            }
        }

        cout << bfs_all(h, w, board, visited) << '\n';

        cin >> w >> h;
    }
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

vector<vector<bool>> board;
int M, N, K;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};

int dfs(int start_y, int start_x) {
    stack<pair<int, int>> s;
    s.push({start_y, start_x});
    board[start_y][start_x] = true;
    int size = 0;

    while(!s.empty()) {
        pair<int, int> cur = s.top();
        s.pop();
        size++;

        for(int i=0; i < 4; i++) {
            pair<int, int> next = {cur.first + dy[i], cur.second + dx[i]};
            if(next.first >= 0 && next.first < N && next.second >= 0 && next.second < M) {
                if(!board[next.first][next.second]) {
                    s.push(next);
                    board[next.first][next.second] = true;
                }
            }
        }
    }

    return size;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int  bl_x, bl_y, tr_x, tr_y;
    cin >> M >> N >> K;

    board = vector<vector<bool>>(N, vector<bool>(M, false));

    for(int i=0; i < K; i++) {
        cin >> bl_x >> bl_y >> tr_x >> tr_y;

        for(int y=bl_x; y < tr_x; y++) {
            for(int x=bl_y; x < tr_y; x++) {
                board[y][x] = true;
            }
        }
    }

    int answer = 0;
    vector<int> sizes;
    for(int i=0; i < N; i++) {
        for(int j=0; j < M; j++) {
            if(!board[i][j]) {
                int size = dfs(i, j);
                answer++;
                sizes.push_back(size);
            }
        }
    }

    cout << answer << '\n';

    sort(sizes.begin(), sizes.end());
    for(auto& element : sizes) {
        cout << element << ' ';
    }
}
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Virus;

int N, M;
vector<vector<int>> map;
vector<vector<bool>> visited;
vector<Virus> start_point_cands;

int num_empty_points = 0;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

struct Virus {
    int y, x, t;
};

int bfs(int start_points_bit) {
    queue<Virus> q;
    visited = vector<vector<bool>>(N, vector<bool>(N, false));
    int area_size = 0;

    for(int i=0; i < start_point_cands.size(); i++) {
        if(start_points_bit & (1 << i)) {
            q.push(start_point_cands[i]);
            visited[start_point_cands[i].y][start_point_cands[i].x] = true;
        }
    }

    int last_t = 0;
    while(!q.empty()) {
        Virus cur = q.front();
        if(map[cur.y][cur.x] == 0) {
            last_t = cur.t;
        }
        q.pop();

        for(int i=0; i < 4; i++) {
            int next_y = cur.y + dy[i];
            int next_x = cur.x + dx[i];
            if(next_x < 0 || next_x >= N || next_y < 0 || next_y >= N) {
                continue;
            }
            if(map[next_y][next_x] != 1 && !visited[next_y][next_x]) {
                q.push({next_y, next_x, cur.t + 1});
                visited[next_y][next_x] = true;
                if(map[next_y][next_x] == 0) {
                    area_size++;
                }
            }
        }
    }

    // cout << area_size << ' ' << num_empty_points << ' ' << last_t << '\n';
    if(area_size != num_empty_points) {
        return INT32_MAX;
    } else {
        return last_t;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    map = vector<vector<int>>(N, vector<int>(N, 0));
    visited = vector<vector<bool>>(N, vector<bool>(N, false));

    for(int i=0; i < N; i++) {
        for(int j=0; j < N; j++) {
            cin >> map[i][j];
            if(map[i][j] == 2) {
                start_point_cands.push_back({i, j, 0});
            }
            if(map[i][j] == 0) {
                num_empty_points++;
            }
        }
    }

    vector<bool> temp(start_point_cands.size(), false);
    for(int i=0; i < M; i++) {
        temp[i] = true;
    }

    int ans = INT32_MAX;
    do {
        int bit = 0;
        for(int i=0; i < start_point_cands.size(); i++) {
            if(temp[i]) {
                bit |= (1 << i);
            }
        }
        ans = min(ans, bfs(bit));
    } while(prev_permutation(temp.begin(), temp.end()));

    if(ans == INT32_MAX) {
        cout << -1 << '\n';
    } else {
        cout << ans << '\n';
    }
}
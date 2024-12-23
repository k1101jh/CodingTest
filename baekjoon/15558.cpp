#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, k;

int dy[3] = {0, 0, 1};
int dx[3] = {1, -1, 0};

vector<vector<char>> lines;

bool BFS(pair<int, int> start) {
    queue<pair<int, pair<int, int>>> q;
    vector<vector<int>> visited(2, vector<int>(N, false));
    visited[0][0] = true;

    q.push({0, start});

    while(!q.empty()) {
        int cur_time = q.front().first;
        pair<int, int> cur = q.front().second;

        q.pop();

        for(int i=0; i < 3; i++) {
            pair<int, int> next = {(cur.first + dy[i]) % 2, cur.second + dx[i]};

            if(next.second >= N) return true;

            if(next.second <= cur_time) continue;
            if(lines[next.first][next.second] != '1') continue;
            if(visited[next.first][next.second]) continue;

            visited[next.first][next.second] = true;
            q.push({cur_time + 1, {next.first, next.second}});
        }
    }

    return false;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> k;

    lines = vector<vector<char>>(2, vector<char>(N, 0));

    dx[2] = k;

    for(int i=0; i < N; i++) {
        cin >> lines[0][i];
    }

    for(int i=0; i < N; i++) {
        cin >> lines[1][i];
    }

    if(BFS({0, 0})) {
        cout << 1 << '\n';
    } else {
        cout << 0 << '\n';
    }

}
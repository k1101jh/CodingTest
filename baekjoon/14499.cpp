#include <iostream>
#include <vector>
using namespace std;

int dx[5] = {0, 1, -1, 0, 0};
int dy[5] = {0, 0, 0, -1, 1};

int N, M, x, y, K;
vector<int> dice(6, 0);

bool CheckValid(const int& new_x, const int new_y) {
    return !(new_x < 0 || new_x >= M || new_y < 0 || new_y >= N);
}

void Roll(vector<vector<int>>& map, int dir) {
    int new_x = x + dx[dir];
    int new_y = y + dy[dir];
    if(CheckValid(new_x, new_y)) {
        x = new_x;
        y = new_y;
        int temp = dice[0];
        if(dir == 1) {
            dice[0] = dice[3];
            dice[3] = dice[5];
            dice[5] = dice[2];
            dice[2] = temp;
        } else if(dir == 2) {
            dice[0] = dice[2];
            dice[2] = dice[5];
            dice[5] = dice[3];
            dice[3] = temp;
        } else if(dir == 3) {
            dice[0] = dice[4];
            dice[4] = dice[5];
            dice[5] = dice[1];
            dice[1] = temp;
        } else {
            dice[0] = dice[1];
            dice[1] = dice[5];
            dice[5] = dice[4];
            dice[4] = temp;
        }

        int& next_grid_val = map[new_y][new_x];
        if(next_grid_val == 0) {
            next_grid_val = dice[5];
        } else {
            dice[5] = next_grid_val;
            next_grid_val = 0;
        }
        cout << dice[0] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> y >> x >> K;
    vector<vector<int>> map(N, vector<int>(M, 0));

    for(int i=0; i < N; i++) {
        for(int j=0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    int inp;
    for(int i=0; i < K; i++) {
        cin >> inp;
        Roll(map, inp);
    }
}
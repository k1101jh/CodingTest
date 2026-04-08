#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int grid_dx[4] = {0, 0, 1, 1,};
int grid_dy[4] = {0, 1, 0, 1};

int cur_gen = 0;

const int BOARD_SIZE = 101;

vector<vector<bool>> board(BOARD_SIZE, vector<bool>(BOARD_SIZE, false));
vector<int> dragon_c;

void Draw(int x, int y, int dir, int g) {
    int limit = (1 << g);
    int cur_x = x;
    int cur_y = y;

    board[y][x] = true;

    for(int i=0; i <= limit; i++) {
        int cur_dir = (dragon_c[i] + dir) % 4;
        board[cur_y][cur_x] = true;
        cur_x += dx[cur_dir];
        cur_y += dy[cur_dir];
    }
}

void NextGeneration(int g) {
    while(cur_gen < g) {
        int size = dragon_c.size();
        for(int i=0; i < size; i++) {
            // 반시계 방향
            int next_dir = (dragon_c[size - i - 1] + 1) % 4;
            dragon_c.push_back(next_dir);
        }
        cur_gen++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x, y, d, g;
    cin >> N;

    dragon_c.push_back(0);

    for(int i=0; i < N; i++) {
        cin >> x >> y >> d >> g;
        NextGeneration(g);
        Draw(x, y, d, g);
    }

    int ans = 0;
    for(int i=0; i < BOARD_SIZE - 1; i++) {
        for(int j=0; j < BOARD_SIZE - 1; j++) {
            int k = 0;
            for(k=0; k < 4; k++) {
                if(!board[i + grid_dy[k]][j + grid_dx[k]]) {
                    break;
                }
            }
            if(k == 4) {
                ans++;
            }
        }
    }

    cout << ans << '\n';
}
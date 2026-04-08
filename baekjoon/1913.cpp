#include <iostream>
#include <vector>
using namespace std;

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, num_to_find;
    cin >> N >> num_to_find;

    vector<vector<int>> board = vector<vector<int>>(N, vector<int>(N, 0));

    int y = 0, x = 0, d = 0, num = N * N, cur_len = N - 1, remain_num = 3;
    int answer_y = 0, answer_x = 0;
    int dest_y = static_cast<int>(N / 2);
    int dest_x = static_cast<int>(N / 2);

    board[y][x] = num--;

    while(cur_len != 0) {
        for(int i=0; i < cur_len; i++) {
            y += dy[d];
            x += dx[d];
            if(num == num_to_find) {
                answer_y = y;
                answer_x = x;
            }
            board[y][x] = num--;
        }

        d = (d + 1) % 4;
        remain_num--;

        if(remain_num == 0) {
            remain_num = 2;
            cur_len--;
        }
    }

    for(int i=0; i < N; i++) {
        for(int j=0; j < N; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }

    cout << answer_y + 1 << ' ' << answer_x + 1 << '\n';
}
#include <iostream>
using namespace std;

int N;
char board[101][101];
int dy[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dx[] = {-1, 0, 1, 1, 1, 0, -1, -1};

bool is_closed_point(int y, int x) {
    if(y >= 1 && y < N - 1 && x >= 1 && x < N - 1) {
        return true;
    } else {
        return false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i=0; i < N; i++) {
        for(int j=0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    if(N <= 2) {
        cout << 0 << '\n';
        return 0;
    }

    int ans = (N - 2) * (N - 2);

    for(int i=1; i < N - 1; i++) {
        for(int j=1; j < N - 1; j++) {
            if(i == 1 || i == N - 2 || j == 1 || j == N - 2) {
                bool is_empty = false;
                for(int k=0; k < 8; k++) {
                    int next_y = i + dy[k];
                    int next_x = j + dx[k];
                    if(board[next_y][next_x] == '0' && !is_empty) {
                        is_empty = true;
                        ans--;
                    }
                }
                if(!is_empty) {
                    for(int k=0; k < 8; k++) {
                        int next_y = i + dy[k];
                        int next_x = j + dx[k];
                        if(board[next_y][next_x] >= '1' && board[next_y][next_x] <= '9') {
                            board[next_y][next_x]--;
                        }
                    }
                }
            }
        }
    }

    cout << ans << '\n';
}
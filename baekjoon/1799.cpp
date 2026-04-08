#include <iostream>
using namespace std;

int N;
int d_range;
int board[10][10] = {0};


int recursive(int r_d_idx, int r_d, int l_d, int n) {
    if(r_d_idx >= d_range) {
        return n;
    }
    int max_num = n;
    int idx_range = d_range - abs(r_d_idx - (N - 1));
    // 정해진 r_d(오른쪽 아래방향 대각선)과 l_d(왼쪽 아래방향 대각선)가 교차하는 점을 순차적으로 탐색
    for(int l_d_idx=max(0, abs(N - 1 - r_d_idx)); l_d_idx < idx_range; l_d_idx += 2) {
        int i = (r_d_idx + l_d_idx - (N - 1)) / 2;
        int j = l_d_idx - i;
        if(board[i][j] == 1) {
            int r_d_bit = (1 << r_d_idx);
            int l_d_bit = (1 << l_d_idx);
            if((!(r_d_bit & r_d)) && (!(l_d_bit & l_d))) {
                max_num = max(max_num, recursive(r_d_idx + 2, r_d | r_d_bit, l_d | l_d_bit, n + 1));
            }
        }
    }
    // 이 대각선에 비숍을 놓지 않는 경우/
    max_num = max(max_num, recursive(r_d_idx + 2, r_d, l_d, n));
    return max_num;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    d_range = N + N - 1;
    for(int i=0; i < N; i++) {
        for(int j=0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    // 홀수칸 짝수칸 따로 계산한 뒤 합산
    // x o x     o x o
    // o x o  +  x o x
    // x o x     o x o
    cout << recursive(0, 0, 0, 0) + recursive(1, 0, 0, 0) << '\n';
}
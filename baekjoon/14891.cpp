#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const int NUM_GEARS = 4;

vector<vector<bool>> gears(NUM_GEARS, vector<bool>(8, false));
vector<int> gear_top_idx(NUM_GEARS, 0);
int dirs_residual[NUM_GEARS] = {0, 2, 4, 6}; // 북, 동, 남, 서

void Rotate(int gear_idx, int rotate_dir) {
    // rotate_dir == 1이면 시계방향

    // 현재 기어 회전하기 전에 인접한 기어 톱니 상태 확인하기
    int gear_rotate_dirs[NUM_GEARS] = {0};
    gear_rotate_dirs[gear_idx] = rotate_dir;

    // 좌측 검사
    int cur_rotate_dir = rotate_dir;
    for(int i=gear_idx; i > 0; i--) {
        int cur_gear_left_idx = (gear_top_idx[i] + dirs_residual[3]) % 8;
        int left_gear_right_idx = (gear_top_idx[i - 1] + dirs_residual[1]) % 8;
        if(gears[i][cur_gear_left_idx] != gears[i - 1][left_gear_right_idx]) {
            cur_rotate_dir = -cur_rotate_dir;
            gear_rotate_dirs[i - 1] = cur_rotate_dir;
        } else {
            break;
        }
    }
    
    // 우측 검사
    cur_rotate_dir = rotate_dir;
    for(int i=gear_idx; i < NUM_GEARS - 1; i++) {
        int cur_gear_right_idx = (gear_top_idx[i] + dirs_residual[1]) % 8;
        int right_gear_left_idx = (gear_top_idx[i + 1] + dirs_residual[3]) % 8;
        if(gears[i][cur_gear_right_idx] != gears[i + 1][right_gear_left_idx]) {
            cur_rotate_dir = -cur_rotate_dir;
            gear_rotate_dirs[i + 1] = cur_rotate_dir;
        } else {
            break;
        }
    }

    // 기어 회전
    for(int i=0; i < NUM_GEARS; i++) {
        if(gear_rotate_dirs[i] == 1) {
            gear_top_idx[i] = (gear_top_idx[i] + 7) % 8;
        } else if(gear_rotate_dirs[i] == -1) {
            gear_top_idx[i] = (gear_top_idx[i] + 9) % 8;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string gear_str;
    int K;
    int gear_num, dir;

    for(int i=0; i < NUM_GEARS; i++) {
        cin >> gear_str;
        for(int j=0; j < gear_str.length(); j++) {
            gears[i][j] = gear_str[j] == '1';
        }
    }

    cin >> K;
    for(int i=0; i < K; i++) {
        cin >> gear_num >> dir;
        Rotate(gear_num - 1, dir);
    }

    // 점수 계산
    int score = 0;
    for(int i=0; i < NUM_GEARS; i++) {
        if(gears[i][gear_top_idx[i]] == 1) {
            score += (1 << i);
        }
    }

    cout << score << '\n';
}
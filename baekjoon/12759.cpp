#include <iostream>
using namespace std;

int board[3][3] = {0};
int cur_player;
int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int opposite_d[] = {4, 5, 6, 7, 0, 1, 2, 3};

bool is_closed_point(int y, int x) {
    if(y >= 0 && y < 3 && x >= 0 && x < 3) {
        return true;
    }
    return false;
}

void change_turn() {
    cur_player = (cur_player == 1) ? 2 : 1;
}

int count_stone(int y, int x, int d) {
    int new_y = y + dy[d];
    int new_x = x + dx[d];
    int num_stone = 1;
    while(is_closed_point(new_y, new_x) && board[new_y][new_x] == cur_player) {
        num_stone++;
        new_y += dy[d];
        new_x += dx[d];
    }
    return num_stone;
}

bool is_three(int y, int x, int d) {
    if((count_stone(y, x, d) + count_stone(y, x, opposite_d[d]) - 1) == 3) {
        return true;
    }
    return false;
}

bool check_game_over(int y, int x) {
    for(int i=0; i < 4; i++) {
        if(is_three(y, x, i)) {
            return true;
        }
    }
    return false;
}

int apply_move(int y, int x) {
    board[y][x] = cur_player;
    if(check_game_over(y, x)) {
        return cur_player;
    }
    change_turn();
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int y, x, i;
    cin >> cur_player;
    for(i=0; i < 9; i++) {
        cin >> y >> x;
        int winner = apply_move(y - 1, x - 1);
        if(winner != 0) {
            cout << winner << '\n';
            break;
        }
    }

    if(i == 9) {
        cout << 0 << '\n';
    }
}
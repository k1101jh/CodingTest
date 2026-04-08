#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int R, C, M;

class Shark {
    public:
        int r;
        int c;
        int s;
        int d;
        int z;
        Shark(int r, int c, int s, int d, int z)  {
            this->r = r;
            this->c = c;
            this->s = s;
            this->d = d;
            this->z = z;
        }
};

Shark*** board = {};
Shark*** next_map = {};
int next_d[] = {0, 2, 1, 4, 3};
int d_r[] = {0, -1, 1, 0, 0};
int d_c[] = {0, 0, 0, 1, -1};
int ans = 0;

void catch_shark(int col) {
    for(int r=0; r < R; r++) {
        if(board[r][col] != nullptr) {
            Shark* cached_shark = board[r][col];
            ans += cached_shark->z;
            delete cached_shark;
            board[r][col] = nullptr;
            break;
        }
    }
}

void simulation() {
    for(int c=0; c < C; c++) {
        // 상어 잡기
        catch_shark(c);
        // 상어 이동
        // 새로운 맵 생성
        next_map = new Shark** [R];
        for(int i=0; i < R; i++) {
            next_map[i] = new Shark* [C];
            for(int j=0; j < C; j++) {
                next_map[i][j] = nullptr;
            }
        }

        // 상어를 찾고 이동시키기
        for(int r=0; r < R; r++) {
            for(int c=0; c < C; c++) {
                if(board[r][c] != nullptr) {
                    Shark* shark = board[r][c];

                    switch(shark->d) {
                        case 1:
                            shark->r -= shark->s;
                            if(shark->r < 0) {
                                shark->r = -shark->r;
                                shark->d = 2;
                            }
                            if(shark->r >= R) {
                                shark->r = R - 2 - (shark->r - R); // (R - 1) - (shark->r - (R - 1))
                                shark->d = 1;
                            }
                            break;
                        case 2:
                            shark->r += shark->s;
                            if(shark->r >= R) {
                                shark->r = R - 2 - (shark->r - R);
                                shark->d = 1;
                            }
                            if(shark->r < 0) {
                                shark->r = -shark->r;
                                shark->d = 2;
                            }
                            break;
                        case 3:
                            shark->c += shark->s;
                            if(shark->c >= C) {
                                shark->c = C - 2 - (shark->c - C);
                                shark->d = 4;
                            }
                            if(shark->c < 0) {
                                shark->c = -shark->c;
                                shark->d = 3;
                            }
                            break;
                        case 4:
                            shark->c -= shark->s;
                            if(shark->c < 0) {
                                shark->c = -shark->c;
                                shark->d = 3;
                            }
                            if(shark->c >= C) {
                                shark->c = C - 2 - (shark->c - C);
                                shark->d = 4;
                            }
                            break;
                    }

                    Shark* shark_already_came = next_map[shark->r][shark->c];
                    if(shark_already_came != nullptr) {
                        if(shark_already_came->z < shark->z) {
                            delete shark_already_came;
                            next_map[shark->r][shark->c] = shark;
                        } else {
                            delete shark;
                        }
                    } else {
                        next_map[shark->r][shark->c] = shark;
                    }
                }
            }
        }
        for(int i=0; i < R; i++) {
            delete[] board[i];
        }
        delete[] board;
        board = next_map;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C >> M;

    board = new Shark** [R];
    for(int i=0; i < R; i++) {
        board[i] = new Shark* [C];
        for(int j=0; j < C; j++) {
            board[i][j] = nullptr;
        }
    }

    int r, c, s, d, z;
    for(int i=0; i < M; i++) {
        cin >> r >> c >> s >> d >> z;
        r--;
        c--;

        // 속도가 너무 빠른 경우
        // 같은 이동 결과를 내는 느린 속도로 설정
        switch(d) {
            case 1:
            case 2:
                s %= (2 * (R - 1));
                break;
            case 3:
            case 4:
                s %= (2 * (C - 1));
                break;
        }
        board[r][c] = new Shark(r, c, s, d, z);
    }

    simulation();

    for(int i=0; i < R; i++) {
        for(int j=0; j < C; j++) {
            delete board[i][j];
        }
        delete[] board[i];
    }
    delete[] board;

    cout << ans << '\n';
}
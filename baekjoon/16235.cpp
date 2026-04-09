#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

int N, M, K;
int x, y, z;

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int ground[10][10] = {0};
int A[10][10] = {0};
deque<int> map_trees[10][10];

void Simulation() {
    // 봄
    for(int i=0; i < N; i++) {
        for(int j=0; j < N; j++) {
            deque<int>& cur_trees = map_trees[i][j];
            int& cur_nutri = ground[i][j];
            int dead_idx = -1;
            for(int k=0; k < cur_trees.size(); k++) {
                int& age = cur_trees[k];
                if(cur_nutri >= age) {
                    cur_nutri -= age;
                    age++;
                } else {
                    dead_idx = k;
                    break;
                }
            }
            if(dead_idx != -1) {
                for(int k=dead_idx; k < cur_trees.size(); k++) {
                    ground[i][j] += cur_trees[k] / 2;
                }
                cur_trees.erase(cur_trees.begin() + dead_idx, cur_trees.end());
            }
        }
    }

    // 가을
    for(int i=0; i < N; i++) {
        for(int j=0; j < N; j++) {
            deque<int>& cur_trees = map_trees[i][j];
            for(int k=0; k < cur_trees.size(); k++) {
                if(cur_trees[k] % 5 == 0) {
                    for(int dir=0; dir < 8; dir++) {
                        int new_y = i + dy[dir];
                        int new_x = j + dx[dir];
                        if(new_x < 0 || new_x >= N || new_y < 0 || new_y >= N) {
                            continue;
                        }
                        map_trees[new_y][new_x].push_front(1);
                    }
                }
            }
        }
    }

    // 겨울
    for(int i=0; i < N; i++) {
        for(int j=0; j < N; j++) {
            ground[i][j] += A[i][j];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;

    for(int i=0; i < N; i++) {
        for(int j=0; j < N; j++) {
            cin >> A[i][j];
            ground[i][j] = 5;
        }
    }

    for(int i=0; i < M; i++) {
        cin >> y >> x >> z;
        map_trees[y - 1][x - 1].push_back(z);
    }

    for(int i=0; i < N; i++) {
        for(int j=0; j < N; j++) {
            sort(map_trees[i][j].begin(), map_trees[i][j].end());
        }
    }

    for(int i=0; i < K; i++) {
        Simulation();
    }

    int ans = 0;
    for(int i=0; i < N; i++) {
        for(int j=0; j < N; j++) {
            ans += map_trees[i][j].size();
        }
    }

    cout << ans << '\n';
}
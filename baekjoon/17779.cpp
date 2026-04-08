#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
// #define DEBUG
using namespace std;

int N;

vector<vector<int>> board;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    board.assign(N, vector<int>(N, 0));
#ifdef DEBUG
    vector<vector<int>> debug_board(N, vector<int>(N, 0));
    vector<vector<int>> best_debug_board;
#endif

    for(int i=0; i < N; i++) {
        for(int j=0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    int ans = INT32_MAX;

    for(int y=0; y < N; y++) {
        for(int x=0; x < N; x++) {
            for(int d1=1; d1 < N; d1++) {
                for(int d2=1; d2 < N; d2++) {
                    if(x + d1 + d2 >= N || y - d1 < 0 || y + d2 >= N) {
                        continue;
                    }
                    
                    // 좌, 상, 우, 하 순으로 꼭짓점
                    vector<pair<int, int>> points(4, {0, 0});
                    points[0] = {y, x};
                    points[1] = {y - d1, x + d1};
                    points[2] = {y - d1 + d2, x + d1 + d2};
                    points[3] = {y + d2, x + d2};

                    // 우상 1번
                    int diag_val1 = x + y; // 1, 3 => 4
                    // 좌상 1번
                    int diag_val2 = y - x - d1 - d1;  // 5.  (3, 1), (5, 3)
                    // 좌상 2번
                    int diag_val3 = y - x; // 11
                    // 우상 2번
                    int diag_val4 = x + y + d2 + d2; // (3, 5), (5, 3) => (4 + 2 + 2)

                    vector<int> num_people(5, 0);

                    for(int i=0; i < N; i++) {
                        for(int j=0; j < N; j++) {
                            int idx = 0;
                            if(i + j >= diag_val1 && i + j <= diag_val4 && i - j >= diag_val2 && i - j <= diag_val3) {
                                idx = 4;
                            } else if(i + j < diag_val1 && i < points[0].first && j <= points[1].second) {
                                idx = 0;
                            } else if(i - j < diag_val2 && i <= points[2].first && j > points[1].second) {
                                idx = 1;
                            } else if(i - j > diag_val3 && i >= points[0].first && j < points[3].second) {
                                idx = 2;
                            } else {
                                idx = 3;
                            }
                            num_people[idx] += board[i][j];
#ifdef DEBUG
                            debug_board[i][j] = idx + 1;
#endif

                        }
                    }

                    int min_val = *min_element(num_people.begin(), num_people.end());
                    int max_val = *max_element(num_people.begin(), num_people.end());
#ifdef DEBUG
                    if(ans > max_val - min_val) {
                        best_debug_board = debug_board;
                    }
#endif
                    ans = min(ans, max_val - min_val);
                }
            }
        }
    }

    cout << ans << '\n';

#ifdef DEBUG
    for(int i=0; i < N; i++) {
        for(int j=0; j < N; j++) {
            cout << best_debug_board[i][j] << ' ';
        }
        cout << '\n';
    }
#endif
}
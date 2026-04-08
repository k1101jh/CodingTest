#include <iostream>
#include <vector>
using namespace std;

int N, L;

bool CheckLine(const vector<int>& line) {
    vector<bool> slope_check(N, false);

    for(int i=1; i < N; i++) {
        int diff = line[i] - line[i - 1];
        if(diff == 0) {
            continue;
        }

        if(abs(diff) > 1) {
            return false;
        }

        // 오르막
        if(diff == 1) {
            for(int k=1; k <= L; k++) {
                if(i - k < 0 || line[i - k] != line[i - 1] || slope_check[i - k]) {
                    return false;
                }
                slope_check[i - k] = true;
            }
        } else { // 내리막
            for(int k=0; k < L; k++) {
                if(i + k >= N || line[i + k] != line[i] || slope_check[i + k]) {
                    return false;
                }
                slope_check[i + k] = true;
            }

            i += L - 1;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> L;

    vector<vector<int>> board(N, vector<int>(N, 0));

    for(int i=0; i < N; i++) {
        for(int j=0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    int ans = 0;

    // 가로 행 검사
    for(int i=0; i < N; i++) {
        ans += CheckLine(board[i]) ? 1 : 0;
    }

    // 세로 행 검사
    for(int i=0; i < N; i++) {
        vector<int> line(N, 0);
        for(int j=0; j < N; j++) {
            line[j] = board[j][i];
        }
        ans += CheckLine(line) ? 1 : 0;
    }

    cout << ans << '\n';
}
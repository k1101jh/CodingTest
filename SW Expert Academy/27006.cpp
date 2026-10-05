#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int TC;
    cin >> TC;
    while(TC--) {
        int N;
        cin >> N;
        vector<vector<char>> board(N, vector<char>(N, 'a'));
        for(int i=0; i < N; i++) {
            for(int j=0; j < N; j++) {
                cin >> board[i][j];
            }
        }

        int ans = 0;
        for(int a=0; a < N; a++) {
            bool is_symmetric = true;
            for(int i=0; i < N; i++) {
                for(int j=0; j < N; j++) {
                    pair<int, int> next_point = {(j - a + N) % N, (i + a) % N};
                    if(board[i][j] != board[next_point.first][next_point.second]) {
                        is_symmetric = false;
                        break;
                    }
                }
                if(!is_symmetric) break;
            }
            if(is_symmetric) ans++;
        }

        cout << ans * N << '\n';
    }
}
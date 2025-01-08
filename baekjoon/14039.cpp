#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<vector<int>> board(4, vector<int>(4, 0));

    int sum_val = 0;

    bool is_magic = true;

    for(int i=0; i < 4; i++) {
        cin >> board[0][i];
        sum_val += board[0][i];
    }

    for(int i=1; i < 4; i++) {
        int sum = 0;
        for(int j=0; j < 4; j++) {
            cin >> board[i][j];
            sum += board[i][j];
        }
        if(sum != sum_val) {
            is_magic = false;
        }
    }

    if(is_magic) {
        for(int i=0; i < 4; i++) {
            int sum = 0;
            for(int j=0; j < 4; j++) {
                sum += board[j][i];
            }
            if(sum != sum_val) {
                is_magic = false;
            }
        }
    }

    if(is_magic) cout << "magic" << '\n';
    else cout << "not magic" << '\n';
}
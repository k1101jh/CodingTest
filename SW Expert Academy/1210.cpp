#include <iostream>
#include <vector>
using namespace std;

#define SWAP(type, a, b) do {type temp = a; a = b; b = temp;} while(0);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    const int BOARD_SIZE = 100;
    int TC = 10;

    while(TC--) {
        int tc;
        cin >> tc;
        int inp;
        int cur = -1;
        // int start = -1;
        vector<vector<bool>> board(BOARD_SIZE, vector<bool>(BOARD_SIZE, false));
        for(int i=0; i < BOARD_SIZE; i++) {
            for(int j=0; j < BOARD_SIZE; j++) {
                cin >> inp;
                if(inp) board[i][j] = true;
                if(inp == 2) cur = j;
            }
        }

        for(int i=BOARD_SIZE - 2; i >= 0; i--) {
            if(cur > 0 && board[i][cur - 1]) {
                while(cur > 0 && board[i][cur - 1]) cur--;
            } else if(cur < BOARD_SIZE - 1 && board[i][cur + 1]) {
                while(cur < BOARD_SIZE - 1 && board[i][cur + 1]) cur++;
            }

        }
        cout << "#" << tc << " " << cur << '\n';
        
    }
}
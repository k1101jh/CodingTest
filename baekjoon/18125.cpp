#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int R, C, inp;
    bool ans = true;
    cin >> R >> C;

    vector<vector<int>> ans_board(C, vector<int>(R, 0));

    for(int i=0; i < C; i++) {
        for(int j=0; j < R; j++) {
            cin >> ans_board[i][j];
        }
    }
    for(int i=0; i < R; i++) {
        for(int j=0; j < C; j++) {
            cin >> inp;
            if(inp != ans_board[C - j - 1][i]) {
                ans = false;
            }
        }
    }

    if(ans) {
        cout << "|>___/|        /}\n| O < |       / }\n(==0==)------/ }\n| ^  _____    |\n|_|_/     ||__|";
    } else {
        cout << "|>___/|     /}\n| O O |    / }\n( =0= )\"\"\"\"  \\\n| ^  ____    |\n|_|_/    ||__|";
    }
}
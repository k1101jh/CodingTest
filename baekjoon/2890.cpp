#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int R, C;
    cin >> R >> C;

    vector<string> board(R, "");
    vector<int> ranks(10, -1);
    priority_queue<pair<int, int>> pq;

    for(int i=0; i < R; i++) {
        cin >> board[i];
    }

    for(int i=0; i < R; i++) {
        for(int j=0; j < C - 3; j++) {
            if(board[i][j] >= '1' && board[i][j] <= '9') {
                pq.push({j, board[i][j] - '0'});
                break;
            }
        }
    }

    int prev = pq.top().first;
    int rank = 1;

    while(!pq.empty()) {
        int pos = pq.top().first;
        int num = pq.top().second;
        pq.pop();

        if(pos != prev) {
            rank++;
            prev = pos;   
        }
        ranks[num] = rank;
    }

    for(int i=1; i <= 9; i++) {
        cout << ranks[i] << '\n';
    }
}
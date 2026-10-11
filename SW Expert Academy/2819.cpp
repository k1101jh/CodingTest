#include <iostream>
#include <vector>
#include <unordered_set>
#include <stack>
using namespace std;

const int SIZE = 4;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};

vector<vector<char>> board;
unordered_set<string> us;

void dfs(pair<int, int> cur) {

    stack<pair<pair<int, int>, string>> s;
    s.push({cur, string(1, board[cur.first][cur.second])});

    while(!s.empty()) {
        pair<int, int> cur = s.top().first;
        string cur_s = s.top().second;
        s.pop();

        if(cur_s.length() == 7) {
            us.insert(cur_s);
            continue;
        }

        for(int i=0; i < 4; i++) {
            pair<int, int> next = {cur.first + dy[i], cur.second + dx[i]};
            if(next.first < 0 || next.second < 0 || next.first >= SIZE || next.second >= SIZE) continue;

            s.push({next, cur_s + board[next.first][next.second]});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    for(int test_case=1; test_case <= T; test_case++) {

        board.assign(SIZE, vector<char>(SIZE, ' '));
        us.clear();

        for(int i=0; i < SIZE; i++) {
            for(int j=0; j < SIZE; j++) {
                cin >> board[i][j];
            }
        }

        // 만들 수 있는 문자열의 개수는?
        for(int i=0; i < SIZE; i++) {
            for(int j=0; j < SIZE; j++) {
                dfs({i, j});
            }
        }
        cout << "#" << test_case << " " << us.size() << '\n';
    }
}
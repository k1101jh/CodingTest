#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int N, M;
char board[50][50];
bool visited[(1 << 6)][50][50] = {0};
int sy, sx;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int ans = -1;

bool is_valid_point(pair<int, int> point) {
    if(point.first >= 0 && point.first < N && point.second >= 0 && point.second < M) {
        return true;
    }
    return false;
}

void bfs(int y, int x) {
    queue<tuple<pair<int, int>, int, int>> q;
    q.push({{y, x}, 0, 0});
    visited[0][y][x] = true;
    while(!q.empty()) {
        pair<int, int> here = get<0>(q.front());
        int here_move_count = get<1>(q.front());
        int here_keys = get<2>(q.front());
        q.pop();

        char& here_char = board[here.first][here.second];
        if(here_char == '#') {
            continue;
        } else if(here_char == '1') {
            ans = here_move_count;
            break;
        } else if(here_char >= 'a' && here_char <= 'f') {
            here_keys |= (1 << (here_char - 'a'));
            visited[here_keys][here.first][here.second] = true;
        } else if(here_char >= 'A' && here_char <= 'F') {
            if((here_keys & (1 << (here_char - 'A'))) == 0) {
                continue;
            }
        }
        
        for(int i=0; i < 4; i++) {
            pair<int, int> there = {here.first + dy[i], here.second + dx[i]};
            if(is_valid_point(there)) {
                if(!visited[here_keys][there.first][there.second]) {
                    visited[here_keys][there.first][there.second] = true;
                    q.push(make_tuple(there, here_move_count + 1, here_keys));
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i=0; i < N; i++) {
        for(int j=0; j < M; j++) {
            cin >> board[i][j];
            if(board[i][j] == '0') {
                sy = i;
                sx = j;
            }
        }
    }

    bfs(sy, sx);

    cout << ans << '\n';
}
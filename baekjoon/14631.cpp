#include <iostream>
#include <queue>
#include <tuple>
using namespace std;


int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

string gallary_s = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

bool is_valid(int y, int x) {
    if(y >= 0 && y < 4 && x >= 0 && x < 5) {
        return true;
    }
    return false;
}

int get_idx_of_map(int y, int x) {
    return y * 5 + x;
}

int get_idx_of_map(pair<int, int> p) {
    return p.first * 5 + p.second;
}

int get_gallary_idx(char c) {
    if(c >= '0' && c <= '9') {
        return c - '0';
    } else {
        return c - 'A' + 10;
    }
}

char get_char_by_gallary_idx(int idx) {
    return gallary_s[idx];
}

int bfs(char board[][5], pair<int, int> start_g, int full_visit_bit) {
    queue<tuple<pair<int, int>, int, int, int, int>> q;
    vector<int> dp[4][5];
    int here_bit = (1 << get_idx_of_map(start_g));
    q.push(make_tuple(start_g, 0, 1, here_bit, here_bit));
    while(!q.empty()) {
        int cur_y = get<0>(q.front()).first;
        int cur_x = get<0>(q.front()).second;
        int cur_dist = get<1>(q.front());
        int next_gallary = get<2>(q.front());
        int visited_bit = get<3>(q.front());
        int cur_step_visited_bit = get<4>(q.front());
        q.pop();

        bool visited = false;
        for(int i=0; i < dp[cur_y][cur_x].size(); i++) {
            if(dp[cur_y][cur_x][i] == visited_bit) {
                visited = true;
            }
        }
        if(visited) {
            continue;
        }

        if(board[cur_y][cur_x] == get_char_by_gallary_idx(next_gallary)) {
            next_gallary++;
            cur_step_visited_bit = (1 << get_idx_of_map(cur_y, cur_x));
        }

        dp[cur_y][cur_x].push_back(visited_bit);

        if(visited_bit == full_visit_bit) {
            return cur_dist;
        }

        for(int i=0; i < 4; i++) {
            int next_y = cur_y + dy[i];
            int next_x = cur_x + dx[i];
            if(is_valid(next_y, next_x)) {
                if(board[next_y][next_x] != '.') {
                    int next_bit = (1 << get_idx_of_map(next_y, next_x));
                    if(cur_step_visited_bit & next_bit) {
                        continue;
                    } else if(board[next_y][next_x] == '#' || get_gallary_idx(board[next_y][next_x]) <= next_gallary) {
                        pair<int, int> next_p = {next_y, next_x};
                        q.push(make_tuple(next_p,
                                          cur_dist + 1,
                                          next_gallary,
                                          visited_bit | next_bit,
                                          cur_step_visited_bit | next_bit));
                    }
                }
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    for(int t=0; t < T; t++) {       
        char board[4][5];
        pair<int, int> start_g;
        int full_visit_bit = 0;
        for(int i=0; i < 4; i++) {
            for(int j=0; j < 5; j++) {
                cin >> board[i][j];
                if(board[i][j] != '.') {
                    full_visit_bit |= (1 << get_idx_of_map(i, j));
                    if(board[i][j] == '0') {
                        start_g.first = i;
                        start_g.second = j;
                    }
                }
            }
        }

        cout << bfs(board, start_g, full_visit_bit) << '\n';
    }
}
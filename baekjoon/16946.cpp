#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int board[1000][1000];
int ans[1000][1000] = {0};
bool visited[1000][1000] = {0};
int sizes[1000000] = {0};
int roots[1000000];
int ranks[1000000] = {0};
int d_y[] = {-1, 0, 1, 0};
int d_x[] = {0, 1, 0, -1};

int find_root(int num) {
    if(roots[num] == num) {
        return num;
    } else {
        return roots[num] = find_root(roots[num]);
    }
}

void my_union(int x, int y) {
    x = find_root(x);
    y = find_root(y);

    if(x == y) {
        return;
    } else if(ranks[x] < ranks[y]) {
        roots[x] = y;
    } else {
        roots[y] = x;
        if(ranks[x] == ranks[y]) {
            ranks[x]++;
        }
    }
}

void dfs(int y, int x) {
    stack<pair<int, int>> s;
    s.push({y, x});
    int num = 0;
    int start_idx = y * M + x;

    while(!s.empty()) {
        pair<int, int> here = s.top();
        s.pop();
        if(visited[here.first][here.second] == true) {
            continue;
        }
        visited[here.first][here.second] = true;
        num++;
        for(int i=0; i < 4; i++) {
            int new_y = here.first + d_y[i];
            int new_x = here.second + d_x[i];
            if(new_y >= 0 && new_y < N && new_x >= 0 && new_x < M) {
                if(board[new_y][new_x] == 0 && visited[new_y][new_x] == false) {
                    s.push({new_y, new_x});
                    my_union(start_idx, new_y * M + new_x);
                }
            }
        }
    }

    sizes[find_root(start_idx)] = num;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    char inp;
    cin >> N >> M;
    for(int i=0; i < N; i++) {
        for(int j=0; j < M; j++) {
            cin >> inp;
            board[i][j] = inp - '0';
            roots[M * i + j] = M * i + j;
        }
    }

    for(int i=0; i < N; i++) {
        for(int j=0; j < M; j++) {
            if(board[i][j] == 0 && visited[i][j] == false) {
                dfs(i, j);
            }
        }
    }

    for(int i=0; i < N; i++) {
        for(int j=0; j < M; j++) {
            if(board[i][j] == 1) {
                vector<int> closed_groups;
                for(int k=0; k < 4; k++) {
                    int new_y = i + d_y[k];
                    int new_x = j + d_x[k];
                    if(new_y >= 0 && new_y < N && new_x >= 0 && new_x < M) {
                        if(board[new_y][new_x] == 0) {
                            closed_groups.push_back(find_root(new_y * M + new_x));
                        }
                    }
                }
                sort(closed_groups.begin(), closed_groups.end());
                closed_groups.erase(unique(closed_groups.begin(), closed_groups.end()), closed_groups.end());
                ans[i][j] = 1;
                for(int p : closed_groups) {
                    ans[i][j] += sizes[p];
                }
                ans[i][j] %= 10;
            }
            cout << ans[i][j];
        }
        cout << "\n";
    }
}
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<pair<int, int>> houses;
vector<pair<int, int>> empty_spaces;

int get_l1_dist(const pair<int, int>& a, const pair<int, int>& b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    vector<string> board = vector<string>(N, "");

    for(int i=0; i < N; i++) {
        cin >> board[i];
        for(int j=0; j < M; j++) {
            if(board[i][j] == '1') {
                houses.push_back({i, j});
            } else {
                empty_spaces.push_back({i, j});
            }
        }
    }

    int min_dist = INT32_MAX;
    for(int i=0; i < static_cast<int>(empty_spaces.size()) - 1; i++) {
        for(int j=i + 1; j < static_cast<int>(empty_spaces.size()); j++) {
            int dist = 0;
            for(const auto& house: houses) {
                dist = max(dist, min(get_l1_dist(house, empty_spaces[i]), get_l1_dist(house, empty_spaces[j])));
                if(dist > min_dist) {
                    break;
                }
            }
            min_dist = min(min_dist, dist);
        }
    }
    cout << min_dist << '\n';
}
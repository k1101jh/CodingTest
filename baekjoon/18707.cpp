#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int T, K;
long long N, M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> T;

    while(T--) {
        cin >> N >> M >> K;
        vector<pair<int, int>> white_cells(K, {0, 0});

        set<int> set_y;
        set<int> set_x;
        set_y.insert(1);
        set_x.insert(1);
        set_y.insert(M + 1);
        set_x.insert(N + 1);
        
        int x, y;
        for(int i=0; i < K; i++) {
            cin >> x >> y;
            set_y.insert(y);
            set_x.insert(x);
            white_cells[i] = {y, x};
        }

        vector<int> vx(set_x.begin(), set_x.end());
        vector<int> vy(set_y.begin(), set_y.end());

        vector<vector<int>> cell_v(vy.size() + 1, vector<int>(vx.size() + 1, 0));

        for(const auto& cell : white_cells) {
            int y_idx = lower_bound(vy.begin(), vy.end(), cell.first) - vy.begin() + 1;
            int x_idx = lower_bound(vx.begin(), vx.end(), cell.second) - vx.begin() + 1;

            cell_v[y_idx][x_idx]++;
        }

        long long ans = 0;
        vector<vector<int>> psum(vy.size() + 1, vector<int>(vx.size() + 1, 0));
        
        for(int i=1; i < vy.size(); i++) {
            for(int j=1; j < vx.size(); j++) {
                psum[i][j] = psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1] + cell_v[i][j];
                if(psum[i][j] % 2 != 0) {
                    long long height = vy[i] - vy[i - 1];
                    long long width = vx[j] - vx[j - 1];

                    ans += width * height;
                }
            }
        }

        cout << ans << ' ' << N * M - ans << '\n';
    }
}


#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int N, L;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> L;

    vector<pair<int, int>> pools(N, {0, 0});

    int start, end;
    for(int i=0; i < N; i++) {
        cin >> start >> end;
        pools[i] = {start, end};
    }

    sort(pools.begin(), pools.end());

    int cnt = 0;
    int prev_end = -1;
    for(int i=0; i < N; i++) {
        start = max(pools[i].first, prev_end);

        int len = pools[i].second - start;
        if(len > 0) {
            int num_required = (len + L - 1) / L;
            int size_over = num_required * L - len;
            prev_end = pools[i].second + size_over;
            cnt += num_required;
        }
    }
    cout << cnt << '\n';
}
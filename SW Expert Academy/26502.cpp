#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int TC, N, x, y;
    cin >> TC;
    while(TC--) {
        // 2차원 평면에서 서로 다른 3개의 점을 골라서 만들 수 있는 최대 넓이 구하기
        cin >> N;
        unordered_map<int, int> y_max;
        unordered_map<int, int> x_max;
        unordered_map<int, int> y_min;
        unordered_map<int, int> x_min;
        vector<pair<int, int>> nums(N, {0, 0});
        for(int i=0; i < N; i++) {
            cin >> x >> y;
            nums[i] = {x, y};
            y_max[x] = max(y_max.count(x) ? y_max[x] : y, y);
            x_max[y] = max(x_max.count(y) ? x_max[y] : x, x);
            y_min[x] = min(y_min.count(x) ? y_min[x] : y, y);
            x_min[y] = min(x_min.count(y) ? x_min[y] : x, x);
        }
        
        long long ans = 0;
        for(auto& point : nums) {
            x = point.first;
            y = point.second;
            long long height = max((y_max[x] - y), (y - y_min[x]));
            long long width = max((x_max[y] - x), (x - x_min[y]));
            ans = max(ans, abs(width * height));
        }
        cout << ans << '\n';
    }
}
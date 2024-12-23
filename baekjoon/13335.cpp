#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, w, L;
    cin >> n >> w >> L;

    vector<int> weights(n, 0);
    for(int i=0; i < n; i++) {
        cin >> weights[i];
    }

    int on_bridge = 0;
    int t = 1;
    queue<pair<int, int>> q;

    q.push({1, weights[0]});
    on_bridge = weights[0];
    int i = 1;

    while(!q.empty()) {
        // 트럭을 빼는 것을 먼저 검사
        if(q.front().first + w <= t) {
            on_bridge -= q.front().second;
            q.pop();
        }
        // 새로운 트럭 추가
        if(i < n && q.size() + 1 <= w && on_bridge + weights[i] <= L) {
            q.push({t, weights[i]});
            on_bridge += weights[i];
            i++;
        }
        t++;
    }
    t--;

    cout << t << '\n';
}
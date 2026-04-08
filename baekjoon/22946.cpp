#include <iostream>
#include <vector>
#include <memory>
#include <cmath>
#include <queue>
#include <stack>
using namespace std;

int N;

struct Circle {
    int x, y, r;
};

vector<Circle> circles;
vector<int> parents;
vector<vector<int>> tree;

bool IsContained(const Circle& a, const Circle& b) {
    // a에 b가 있는 경우
    if(a.r < b.r) return false;;
    long long dx = a.x - b.x;
    long long dy = a.y - b.y;
    long long dist = dx * dx + dy * dy;
    long long r_diff = a.r - b.r;
    return dist <= r_diff * r_diff;
}

pair<int, int> DFS(int start) {
    vector<bool> visited(N + 1, false);
    stack<pair<int, int>> s;
    s.push({start, 0});
    visited[start] = true;

    int farthest = start;
    int ans = 0;
    while(!s.empty()) {
        int cur = s.top().first;
        int num_c = s.top().second;
        s.pop();
        Circle& cur_circle = circles[cur];

        if(num_c > ans) {
            farthest = cur;
            ans = num_c;
        }

        for(const auto& next: tree[cur]) {
            if(!visited[next]) {
                s.push({next, num_c + 1});
                visited[next] = true;
            }
        }
    }
    return {farthest, ans};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x, y, R;
    cin >> N;

    parents = vector<int>(N + 1, 0);
    tree.assign(N + 1, vector<int>());

    // 가상의 루트
    circles.push_back({-1, -1, -1});

    for(int i=0; i < N; i++) {
        cin >> x >> y >> R;
        circles.push_back({x, y, R});
    }

    for(int i=1; i <= N; i++) {
        int parent_idx = 0;
        int min_r = INT32_MAX;
        for(int j=1; j <= N; j++) {
            if(i == j) continue;

            if(IsContained(circles[j], circles[i])) {
                if(circles[j].r < min_r) {
                    min_r = circles[j].r;
                    parent_idx = j;
                }
            }
        }
        tree[parent_idx].push_back(i);
        tree[i].push_back(parent_idx);
    }

    // 두 번 DFS 진행
    // 아무 노드에서 DFS 진행
    // 이후 그 노드에서 DFS 진행해서 가장 먼 거리 출력
    int start = DFS(0).first;
    cout << DFS(start).second << '\n';
}
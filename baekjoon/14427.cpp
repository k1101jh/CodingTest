#include <iostream>
#include <vector>
using namespace std;

int N, M;

struct Node {
    int val, idx;
};

bool compare(const Node& a, const Node& b) {
    if(a.val == b.val) {
        return a.idx < b.idx;
    }
    return a.val < b.val;
}

vector<Node> seg_tree;

Node Init(const vector<int>& nums, int node, int left_idx, int right_idx) {
    if(left_idx == right_idx) {
        return seg_tree[node] = {nums[left_idx], left_idx};
    }

    int mid_idx = (left_idx + right_idx) >> 1;
    return seg_tree[node] = min(Init(nums, node * 2, left_idx, mid_idx), Init(nums, node * 2 + 1, mid_idx + 1, right_idx), compare);
}

Node Update(int target_idx, int val, int node, int left_idx, int right_idx) {
    if(target_idx < left_idx || target_idx > right_idx) {
        return seg_tree[node];
    }

    if(left_idx == right_idx) {
        return seg_tree[node] = {val, left_idx};
    }
    int mid_idx = (left_idx + right_idx) >> 1;
    return seg_tree[node] = min(Update(target_idx, val, node * 2, left_idx, mid_idx), Update(target_idx, val, node * 2 + 1, mid_idx + 1, right_idx), compare);
}

Node Query(int node, int left_idx, int right_idx) {
    return seg_tree[node];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    seg_tree = vector<Node>(N * 4, {0, 0});
    vector<int> A = vector<int>(N, 0);

    for(int i=0; i < N; i++) {
        cin >> A[i];
    }

    Init(A, 1, 0, N - 1);

    cin >> M;

    int op, i, v;
    for(int j=0; j < M; j++) {
        cin >> op;
        if(op == 1) {
            cin >> i >> v;
            Update(i - 1, v, 1, 0, N - 1);
        } else {
            Node result = Query(1, 0, N - 1);
            cout << result.idx + 1 << '\n';
        }
    }

}
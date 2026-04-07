#include <iostream>
#include <vector>
using namespace std;

int N, K;
vector<int> seg_tree;

int GetNumToStore(int n) {
    if(n > 0) {
        return 1;
    } else if(n < 0) { 
        return -1;
    } else {
        return 0;
    }
}

int Init(const vector<int>& nums, int node, int left_idx, int right_idx) {
    if(left_idx == right_idx) {
        return seg_tree[node] = GetNumToStore(nums[left_idx]);
    }
    int mid_idx = (left_idx + right_idx) >> 1;
    return seg_tree[node] = Init(nums, node * 2, left_idx, mid_idx) * Init(nums, node * 2 + 1, mid_idx + 1, right_idx);
}

int Update(int target_idx, int val, int node, int left_idx, int right_idx) {
    if(target_idx < left_idx || target_idx > right_idx) {
        return seg_tree[node];
    }

    if(left_idx == right_idx) {
        return seg_tree[node] = GetNumToStore(val);
    }

    int mid_idx = (left_idx + right_idx) >> 1;
    return seg_tree[node] = Update(target_idx, val, node * 2, left_idx, mid_idx) * Update(target_idx, val, node * 2 + 1, mid_idx + 1, right_idx);
}

int Mul(int i, int j, int node, int left_idx, int right_idx) {
    if(right_idx < i || left_idx > j) {
        return 1;
    }
    if(left_idx >= i && right_idx <= j) {
        return seg_tree[node];
    }

    int mid_idx = (left_idx + right_idx) >> 1;
    return Mul(i, j, node * 2, left_idx, mid_idx) * Mul(i, j, node * 2 + 1, mid_idx + 1, right_idx);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(cin >> N >> K) {
        seg_tree = vector<int>(N * 4, 0);
        vector<int> nums(N, 0);

        for(int i=0; i < N; i++) {
            cin >> nums[i];
        }
        Init(nums, 1, 0, N - 1);

        char op;
        int i, v, j;
        for(int k=0; k < K; k++) {
            cin >> op;
            if(op == 'C') {
                cin >> i >> v;
                Update(i - 1, v, 1, 0, N - 1);
            } else {
                cin >> i >> j;
                int result = Mul(i - 1, j - 1, 1, 0, N - 1);
                if(result > 0) {
                    cout << '+';
                } else if(result < 0) {
                    cout << '-';
                } else {
                    cout << result;
                }
            }
        }
        cout << '\n';
    }
}
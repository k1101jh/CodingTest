#include <iostream>
#include <vector>
using namespace std;

int N;

class Node;

vector<Node*> node_vec;
vector<int> parent_info;
vector<int> min_col;
vector<int> max_col;
int col_idx = 1;
int max_depth = 0;

class Node {
public:
    int idx;
    Node* left = nullptr;
    Node* right = nullptr;

    Node(int idx)
    : idx(idx) {

    }
};

void dfs(Node* cur, int level) {
    if(cur == nullptr) return;

    if(level > max_depth) {
        max_depth = level;
        min_col.resize(level + 1, INT32_MAX);
        max_col.resize(level + 1, INT32_MIN);
    }

    dfs(cur->left, level + 1);

    min_col[level] = min(min_col[level], col_idx);
    max_col[level] = max(max_col[level], col_idx);
    col_idx++;

    dfs(cur->right, level + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    node_vec = vector<Node*>(N + 1, nullptr);
    parent_info = vector<int>(N + 1, -1);
    for(int i=1; i <= N; i++) {
        node_vec[i] = new Node(i);
    }

    int idx, left, right;
    for(int i=0; i < N; i++) {
        cin >> idx >> left >> right;
        if(left != -1) {
            node_vec[idx]->left = node_vec[left];
            parent_info[left] = idx;
        }
        if(right != -1) {
            node_vec[idx]->right = node_vec[right];
            parent_info[right] = idx;
        }
    }
    
    int root_id = 1;
    for(int i=1; i <= N; i++) {
        if(parent_info[i] == -1) {
            root_id = i;
            break;
        }
    }

    dfs(node_vec[root_id], 1);

    // 가장 너비가 넓은 레벨 출력
    int ans_lev = 1;
    int max_width = 1;

    for(int lev=1; lev <= max_depth; lev++) {
        int width = max_col[lev] - min_col[lev] + 1;
        if(width > max_width) {
            max_width = width;
            ans_lev = lev;
        }
    }

    cout << ans_lev << ' ' << max_width << '\n';

    for(int i=1; i <= N; i++) {
        delete node_vec[i];
    }
}
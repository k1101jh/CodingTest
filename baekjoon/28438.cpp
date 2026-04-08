#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, Q, op, a, b;
    cin >> N >> M >> Q;

    vector<vector<int>> arr(N, vector<int>(M, 0));
    vector<int> rows(N, 0);
    vector<int> cols(M, 0);

    for(int i=0; i < Q; i++) {
        cin >> op >> a >> b;
        if(op == 1) {
            rows[a - 1] += b;
        } else {
            cols[a - 1] += b;
        }
    }

    for(int i=0; i < N; i++) {
        for(int j=0; j < M; j++) {
            cout << arr[i][j] + rows[i] + cols[j] << ' ';
        }
        cout << '\n';
    }
}
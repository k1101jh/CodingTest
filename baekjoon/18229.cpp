#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<int>> vec(N, vector<int>(M, 0));
    vector<int> stretch_vec(N, 0);

    for(int i=0; i < N; i++) {
        for(int j=0; j < M; j++) {
            cin >> vec[i][j];
        }
    }

    for(int i=0; i < M; i++) {
        for(int j=0; j < N; j++) {
            stretch_vec[j] += vec[j][i];
            if(stretch_vec[j] >= K) {
                cout << j + 1 << ' ' << i + 1 << '\n';
                return 0;
            }
        }
    }
}
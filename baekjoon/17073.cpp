#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> parents;
vector<double> water;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, W, U, V;
    cin >> N >> W;

    parents = vector<vector<int>>(N + 1, vector<int>());

    for(int i=0; i < N - 1; i++) {
        cin >> U >> V;
        parents[U].push_back(V);
        parents[V].push_back(U);
    }

    // 리프 노드의 개수 구하기
    int num_leafs = 0;

    // N이 2 이상이므로 루트 노드는 리프 노드가 될 수 없음
    for(int i=2; i <= N; i++) {
        if(parents[i].size() == 1) {
            num_leafs++;
        }
    }

    cout.precision(15);
    cout << W / (double)num_leafs << '\n';
}
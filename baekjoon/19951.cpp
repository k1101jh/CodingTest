#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> ground;
vector<int> sums;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    ground = vector<int>(N, 0);
    sums = vector<int>(N + 1, 0);

    for(int i=0; i < N; i++) {
        cin >> ground[i];
    }

    int a, b, k;
    for(int i=0; i < M; i++) {
        cin >> a >> b >> k;

        a--;
        b--;

        sums[a] += k;
        sums[b + 1] -= k;
    }

    int cur_val = 0;
    for(int i=0; i < N; i++) {
        cur_val += sums[i];
        ground[i] += cur_val;
        cout << ground[i] << ' ';
    }
    cout << '\n';
}
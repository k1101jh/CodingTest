#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, k, inp;
    cin >> N >> k;
    vector<int> vec(N, 0);

    for(int i=0; i < N; i++) {
        cin >> inp;
        vec[i] = inp;
    }

    sort(vec.begin(), vec.end(), greater<int>());
    cout << vec[k - 1] << '\n';
}
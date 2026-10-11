#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for(int t=1; t <= T; t++) {
        int N;
        cin >> N;
        vector<int> scores(N, 0);

        for(int i=0; i < N; i++) {
            cin >> scores[i];
        }


        sort(scores.begin(), scores.end());

        bitset<10001> b; //100x100
        b[0] = 1;
        for(int i=0; i < scores.size(); i++) {
            b |= (b << scores[i]);
        }


        cout << "#" << t << " " << b.count() << '\n';
    }
}
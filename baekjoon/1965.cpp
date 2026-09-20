#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    vector<int> boxes(n, 0);
    for(int i=0; i < n; i++) {
        cin >> boxes[i];
    }

    vector<int> tails;
    tails.push_back(0);
    int len = 0;
    for(int i=0; i < n; i++) {
        if(tails[len] < boxes[i]) {
            tails.push_back(boxes[i]);
            len++;
        } else {
            int idx = lower_bound(tails.begin(), tails.end(), boxes[i]) - tails.begin();
            tails[idx] = boxes[i];
        }
    }

    cout << len << '\n';
}
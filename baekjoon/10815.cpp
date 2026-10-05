#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> nums;

bool BinarySearch(int n) {
    int left = 0;
    int right = N - 1;
    int mid;

    while(left <= right) {
        mid = (left + right) >> 1;
        if(nums[mid] == n) {
            return true;
        } else if(nums[mid] > n) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    nums.assign(N, 0);

    for(int i=0; i < N; i++) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    cin >> M;
    int inp;
    for(int i=0; i < M; i++) {
        cin >> inp;
        if(BinarySearch(inp)) {
            cout << 1 << ' ';
        } else {
            cout << 0 << ' ';
        }
    }
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int GetGCD(int a, int b) {
    int c;

    while(b != 0) {
        c = a % b;
        a = b;
        b = c;
    }

    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> nums(n, 0);
    for(int i=0; i < n; i++) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    int gcd = nums[1] - nums[0];

    for(int i=1; i < n - 1; i++) {
        gcd = GetGCD(gcd, nums[i + 1] - nums[i]);
    }
    cout << gcd << '\n';
}
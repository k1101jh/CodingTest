#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long x;
    cin >> x;

    long long x2 = x + 1;

    vector<long long> nums;
    nums.push_back(1);

    long long i;
    for(i=2; i * i < x2; i++) {
        if(x2 % i == 0) {
            nums.push_back(i);
            nums.push_back(x2 / i);
        }
    }

    if(i * i == x2) {
        nums.push_back(i);
    }

    sort(nums.begin(), nums.end());
    
    for(const auto& num : nums) {
        cout << num << ' ';
    }
}
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    const long long DIV_NUM = 998244353;
    int TC;
    cin >> TC;
    while(TC--) {
        long long ans = 1;
        vector<long long> nums(3, 0);
        for(int i=0; i < 3; i++) {
            cin >> nums[i];
        }
        
        for(auto& num : nums) {
            long long cur = 1;
            if((num % 2 == 1)) {
                cur = (((num + 1) >> 1) * num) % DIV_NUM;
            } else {
                cur = ((num >> 1) * (num + 1)) % DIV_NUM;
            }
            ans = (ans * cur) % DIV_NUM;
        }
        
        cout << ans << '\n';
    }
}
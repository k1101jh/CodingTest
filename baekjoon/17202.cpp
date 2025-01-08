#include <iostream>
#include <vector>
using namespace std;

vector<int> Solution(vector<int>& nums) {
    if(nums.size() == 2) {
        return nums;
    }

    vector<int> new_nums;

    for(int i=0; i < nums.size() - 1; i++) {
        new_nums.push_back((nums[i] + nums[i + 1]) % 10);
    }

    return Solution(new_nums);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string A, B;
    cin >> A >> B;

    vector<int> nums;

    for(int i=0; i < 8; i++) {
        nums.push_back(A[i] - '0');
        nums.push_back(B[i] - '0');
    }

    vector<int> answer = Solution(nums);

    cout << answer[0] << answer[1] << '\n';
}
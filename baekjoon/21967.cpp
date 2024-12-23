#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> vec(N, 0);
    vector<int> nums(11, 0);
    for(int i=0; i < N; i++) {
        cin >> vec[i];
    }

    int ans = 1;

    int left = 0;
    int right = 0;
    int min_num = vec[0];
    int max_num = vec[0];
    nums[vec[0]]++;

    while(right < N - 1) {
        right++;
        nums[vec[right]]++;

        min_num = min(min_num, vec[right]);
        max_num = max(max_num, vec[right]);

        while(max_num - min_num > 2) {
            while(nums[min_num] != 0 && nums[max_num] != 0) {
                nums[vec[left]]--;
                left++;
            }
            if(nums[min_num] == 0) {
                for(int i=min_num + 1; i <= 10; i++) {
                    if(nums[i] > 0) {
                        min_num = i;
                        break;
                    }
                }
            } else {
                for(int i=max_num - 1; i >= 0; i--) {
                    if(nums[i] > 0) {
                        max_num = i;
                        break;
                    }
                }
            }
        }

        // cout << right << ' ' << min_num << ' ' << max_num << '\n';

        ans = max(ans, right - left + 1);
    }

    cout << ans << '\n';
}
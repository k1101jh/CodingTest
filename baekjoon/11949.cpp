#include <iostream>
#include <vector>
#define SWAP(type, a, b) do {type temp = a; a = b; b = temp;} while(0);
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, A;
    cin >> N >> M;

    vector<int> nums(N, 0);

    for(int i=0; i < N; i++) {
        cin >> nums[i];
    }

    for(int i=1; i <= M; i++) {
        for(int j=0; j < N - 1; j++) {
            if(nums[j] % i > nums[j + 1] % i) {
                SWAP(int, nums[j], nums[j + 1])
            }
        }
    }

    for(int i=0; i < N; i++) {
        cout << nums[i] << '\n';
    }
}
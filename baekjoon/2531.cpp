#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, d, k, c;
    cin >> N >> d >> k >> c;

    vector<int> vec(N, 0);
    unordered_map<int, int> eaten;

    for(int i=0; i < N; i++) {
        cin >> vec[i];
    }

    int left = 0;
    int right = 0;
    int ans = 0;

    eaten.insert({vec[left], 1});
    eaten.insert({c, 1});

    for(int i=1; i < k; i++) {
        right++;
        if(eaten.find(vec[right]) == eaten.end()) {
            eaten.insert({vec[right], 1});
        } else {
            eaten[vec[right]]++;
        }
    }

    ans = eaten.size();

    while(left != N) {
        right++;
        right %= N;
        if(eaten.find(vec[right]) != eaten.end()) {
            eaten[vec[right]]++;
        } else {
            eaten.insert({vec[right], 1});
        }

        if(eaten[vec[left]] == 1) {
            eaten.erase(vec[left]);
        } else {
            eaten[vec[left]]--;
        }
        left++;

        ans = max(ans, static_cast<int>(eaten.size()));
    }

    cout << ans << '\n';
}
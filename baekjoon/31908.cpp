#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    string p, s;
    unordered_map<string, vector<string>> map;
    int ans = 0;

    for(int i=0; i < N; i++) {
        cin >> p >> s;
        if(s != "-") {
            map[s].push_back(p);
            if(map[s].size() == 2) {
                ans++;
            } else if(map[s].size() == 3) {
                ans--;
            }
        }
    }

    cout << ans << '\n';
    if(ans > 0) {
        for(const auto& element: map) {
            const vector<string>& vec = element.second;
            if(vec.size() == 2) {
                cout << vec[0] << ' ' << vec[1] << '\n';
            }
        }
    }
}
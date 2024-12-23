#include <iostream>
#include <vector>
using namespace std;

vector<int> cumulative_sum;

int RecursiveCount(const string& s, int prev, int idx) {
    int cnt = 0;

    if(idx == s.size()) {
        return 1;
    }

    for(int i=idx + 1; i <= s.size(); i++) {
        int cur = cumulative_sum[i] - cumulative_sum[idx];
        if(cur >= prev) {
            cnt += RecursiveCount(s, cur, i);
        }
    }

    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string inp;
    cin >> inp;

    int case_cnt = 1;
    while(inp != "bye") {
        cumulative_sum = vector<int>(inp.size() + 1, 0);

        for(int i=1; i <= inp.size(); i++) {
            cumulative_sum[i] = cumulative_sum[i - 1] + (inp[i - 1] - '0');
        }

        int cnt = RecursiveCount(inp, 0, 0);

        cout << case_cnt << ". " << cnt << '\n';
        case_cnt++;
        cin >> inp;
    }
}
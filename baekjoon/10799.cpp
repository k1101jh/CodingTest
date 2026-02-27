#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string inp;
    cin >> inp;

    stack<int> s;

    int num_sticks = 0;
    int cnt = 0;

    for(int i=0; i < inp.size(); i++) {
        if(inp[i] == '(') {
            s.push(i);
            num_sticks++;
        } else {
            if(!s.empty()) {
                if(i - s.top() == 1) {
                    num_sticks--;
                    cnt += num_sticks;
                } else {
                    num_sticks--;
                    cnt++;
                }
            }
            s.pop();
        }
    }

    cout << cnt << '\n';
}
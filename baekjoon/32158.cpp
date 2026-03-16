#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    string S;
    cin >> N >> S;

    queue<int> P_q;
    queue<int> C_q;

    for(int i=0; i < N; i++) {
        if(S[i] == 'P') {
            P_q.push(i);
        } else if(S[i] == 'C') {
            C_q.push(i);
        }

        if(!P_q.empty() && !C_q.empty()) {
            S[P_q.front()] = 'C';
            S[C_q.front()] = 'P';
            P_q.pop();
            C_q.pop();
        }
    }

    cout << S << '\n';
}
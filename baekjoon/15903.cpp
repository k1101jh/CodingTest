#include <iostream>
#include <vector>
#include <queue>
using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    int inp;
    priority_queue<long long> pq;

    for(int i=0; i < n; i++) {
        cin >> inp;
        pq.push(-inp);
    }

    for(int i=0; i < m; i++) {
        long long a = pq.top();
        pq.pop();
        long long b = pq.top();
        pq.pop();
        pq.push(a + b);
        pq.push(a + b);
    }

    long long sum = 0;

    while(!pq.empty()) {
        sum -= pq.top();
        pq.pop();
    }

    cout << sum << '\n';
}
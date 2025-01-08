#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int D, K;

vector<int> fib;
vector<int> dp;

int GetFib(int n) {
    if(n == 1) return 1;
    if(n == 2) return 1;
    if(dp[n] != -1) return dp[n];
    return GetFib(n - 1) + GetFib(n - 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> D >> K;

    dp = vector<int>(D, -1);
    GetFib(D - 1);

    int i=1;
    while(true) {
        int remain = (K - GetFib(D - 2) * i);
        if(remain % GetFib(D - 1) == 0){
            cout << i << '\n' << remain / GetFib(D - 1) << '\n';
            break;
        }
        i++;
    }
}

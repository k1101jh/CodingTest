#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

long long K, A, B;

long long GetCnt(long long n) {
    // X <= n 중 K가 영선 수열에 포함되어 있는 x의 개수를 구함
    if(n == 0) return (K == 0) ? 1 : 0;
    if(n < K) return 0;

    long long num = K;

    // 처음에 K가 0이라면, 0을 포함한 이후 모든 숫자가 가능함
    // 1이라면, 1에서 n까지 가능
    if(num <= 1) {
        return n + (1 - num);
    }

    // 범위 구해주기
    long long K_begin = num;
    long long K_end = num;

    if((num & 1) == 0) {
        K_end++;
    }

    long long ans = max(0LL, min(n, K_end) - K_begin + 1LL);
    while(K_begin <= n) {
        K_begin <<= 1;
        K_end <<= 1;
        K_end += 1;
        ans += max(0LL, min(n, K_end) - K_begin + 1LL);
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> K >> A >> B;

    long long ans = GetCnt(B) - GetCnt(A - 1);

    cout << ans << '\n';
}
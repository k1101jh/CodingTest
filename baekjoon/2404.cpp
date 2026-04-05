#include <iostream>
using namespace std;

int p, q, a, n;
int cnt = 0;

// int Recursive(int denom_mul, int prev_q, int remain_p, int remain_q, int num) {
//     int cnt = 0;

//     if(denom_mul > a) {
//         return 0;
//     }
//     if(num == n) {
//         return 0;
//     }

//     for(int i=prev_q / q; i * q * denom_mul <= a / q; i++) {
//         int cur_q = i * q;
//         cnt += Recursive(denom_mul * cur_q, cur_q, )
//     }
// }

int get_gcd(int a, int b) {
    int c;

    while(b != 0) {
        c = a % b;
        a = b;
        b = c;
    }

    return a;
}

void recursive(int denom_mul, int prev_q, int remain_p, int remain_q, int depth) {
    // cout << denom_mul << ' ' << prev_q << ' ' << remain_p << ' ' << remain_q << ' ' << depth << '\n';
    if(denom_mul > a) {
        return;
    }

    if(remain_p == 0) {
        cnt++;
        return;
    }

    if(depth == n) {
        return;
    }

    for(int i=prev_q; i * denom_mul <= a; i++) {
        int next_q = i * remain_q;
        int next_p = remain_p * i - remain_q;
        if(next_p >= 0) {
            int gcd = get_gcd(next_p, next_q);
            next_p /= gcd;
            next_q /= gcd;
            recursive(denom_mul * i, i, next_p, next_q, depth + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> p >> q >> a >> n;

    recursive(1, 1, p, q, 0);
    cout << cnt << '\n';
}
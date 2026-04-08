#include <iostream>
#include <vector>
using namespace std;

long long get_gcd(long long a, long long b) {
    long long c;

    while(b != 0) {
        c = a % b;
        a = b;
        b = c;
    }

    return a;
}

long long get_lcm(long long a, long long b) {
    return (a * b) / get_gcd(a, b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long N, inp;
    cin >> N;

    vector<long long> nums(N, 0);
    long long denominator = 0;

    for(int i=0; i < N; i++) {
        cin >> nums[i];
    }

    long long lcm = nums[0];
    for(int i=1; i < N; i++) {
        lcm = get_lcm(lcm, nums[i]);
    }

    for(int i=0; i < N; i++) {
        denominator += lcm / nums[i];
    }

    long long gcd = get_gcd(lcm, denominator);
    cout << lcm / gcd << '/' << denominator / gcd << '\n';

}
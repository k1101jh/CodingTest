#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A, B;
    cin >> A >> B;

    vector<int> count(11, 2);
    count[A]--;
    count[B]--;
    
    double denominator = 18 * 17 / 2;
    double numerator = 0, ans = 0;

    if(A == B) {
    // 영학이가 땡인 경우
        // 상대가 이기는 경우
        numerator = 10 - A;
        // 1에서 빼기
        ans = (denominator - numerator) / denominator;
    } else {
    // 영항이가 끗인 경우
        int young = (A + B) % 10;

        for(int i=1; i <= 10; i++) {
            for(int j=i + 1; j <= 10; j++) {
                if((i + j) % 10 < young) {
                    numerator += count[i] * count[j];
                }
            }
        }

        ans = numerator / denominator;
    }

    cout << fixed;
    cout.precision(3);
    cout << ans << '\n';
}
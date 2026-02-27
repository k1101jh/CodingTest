#include <iostream>
#include <vector>
#include <queue>
using namespace std;

long long N, M;
vector<long long> rides;

long long count(long long t) {
    long long cnt = 0;
    for(int i=0; i < M; i++) {
        cnt += t / rides[i];
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    rides = vector<long long>(M, 0);

    long long max_val = 0;
    for(int i=0; i < M; i++) {
        cin >> rides[i];
        max_val = max(max_val, rides[i]);
    }

    int ans = 0;

    if(N <= M) {
        ans = N - 1;
    } else {
        N -= M;
        long long left = 0;
        long long right = M * max_val * N;

        long long t = -1;
        long long prev_cnt = -1;

        while(left <= right) {
            long long mid = ((left + right) >> 1);
            long long cnt = count(mid);

            if(cnt >= N) {
                prev_cnt = count(mid - 1);
                if(prev_cnt < N) {
                    t = mid;
                    break;
                }
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        for(int i=0; i < M; i++) {
            if(t % rides[i] == 0) {
                prev_cnt++;
                if(prev_cnt == N) {
                    ans = i;
                    break;
                }
            }
        }
    }

    cout << ans + 1 << '\n';
}
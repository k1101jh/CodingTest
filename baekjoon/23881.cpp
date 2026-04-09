#include <iostream>
#include <vector>
#define SWAP(type, a, b) do {type temp = a; a = b; b = temp;} while(0);
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<int> A(N, 0);

    for(int i=0; i < N; i++) {
        cin >> A[i];
    }

    int cnt = 0;
    for(int i=N - 1; i > 0; i--) {
        int max_val = A[i];
        int max_val_idx = i;
        for(int j=i - 1; j >= 0; j--) {
            if(A[j] > max_val) {
                max_val = A[j];
                max_val_idx = j;
            }
        }
        if(max_val_idx != i) {
            if(cnt + 1 == K) {
                cout << A[i] << ' ' << A[max_val_idx] << '\n';
            }
            SWAP(int, A[i], A[max_val_idx]);
            cnt++;
        }
    }

    if(cnt < K) {
        cout << -1 << '\n';
    }

}
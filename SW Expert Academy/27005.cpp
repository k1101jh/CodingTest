#include <iostream>
#include <vector>
using namespace std;

vector<int> A;

void make_A() {
    A[0] = 1;
    A[1] = 1;

    for(int i=2; i < 1001; i++) {
        for(int j=1; j < 1001; j++) {
            bool is_valid = true;

            for(int k=1; k <= i / 2; k++) {
                if(j == 2 * A[i - k] - A[i - 2 * k]) {
                    is_valid = false;
                    break;
                }
            }
            
            if(is_valid) {
                A[i] = j;
                break;
            }
        } 
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    A.assign(1001, -1);

    int TC, n;
    cin >> TC;

    make_A();

    while(TC--) {
        cin >> n;
        cout << A[n] << '\n';
    }
}
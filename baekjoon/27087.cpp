#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while(T--) {
        int lens[3], p;
        for(int i=0; i < 3; i++) {
            cin >> lens[i];
        }
        cin >> p;
        int num_devide = 0;

        for(int i=0; i < 3; i++) {
            if(lens[i] % p == 0) num_devide++;
        }

        if(num_devide >= 2) {
            cout << 1 << '\n';
        } else {
            cout << 0 << '\n';
        }
        
    }
}
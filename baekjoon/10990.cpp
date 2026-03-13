#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for(int i=0; i < N - 1; i++) {
        cout << ' ';
    }
    cout << '*' << '\n';

    for(int i=1; i < N; i++) {
        for(int j=0; j <= (N - 2) - i; j++) {
            cout << ' ';
        }
        cout << '*';
        for(int j=0; j < i * 2 - 1; j++) {
            cout << ' ';
        }
        cout << '*' << '\n';
    }
}
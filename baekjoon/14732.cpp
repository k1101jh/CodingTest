#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    const int SIZE = 500;
    int N, x1, y1, x2, y2, sum = 0;
    cin >> N;

    vector<vector<bool>> ground(SIZE, vector<bool>(SIZE, false));
    
    for(int i=0; i < N; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        for(int j=x1; j < x2; j++) {
            for(int k=y1; k < y2; k++) {
                ground[j][k] = true;
            }
        }
    }

    for(int i=0; i < SIZE; i++) {
        for(int j=0; j < SIZE; j++) {
            sum += 1 ? ground[i][j] : 0;
        }
    }

    cout << sum << '\n';
}
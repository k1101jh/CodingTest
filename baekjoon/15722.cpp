#include <iostream>
using namespace std;

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int i=2;
    int cnt = 0;
    while(n - i >= 0) {
        n -= i;
        i += 2;
        cnt++;
    }

    int x = (cnt + 1) / 2;
    int y = (cnt + 1) / 2;

    if(n - (i / 2) >= 0) {
        y *= -1;
        x -= n - i / 2;
        if(cnt % 2 == 0) y--;
    } else {
        y -= n;
    }
    
    if(cnt % 2 == 0) {
        x *= -1;
        y *= -1;
    }

    cout << x << ' ' << y << '\n';

}


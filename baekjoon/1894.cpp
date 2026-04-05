#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    double x1, y1, x2, y2, x3_c1, y3_c1, x3_c2, y3_c2, x3, y3, x4, y4;
    cout << fixed;
    cout.precision(3);
    while(cin >> x1 >> y1 >> x2 >> y2 >> x3_c1 >> y3_c1 >> x3_c2 >> y3_c2) {
        
        if(x1 == x3_c1 && y1 == y3_c1) {
            x4 = x3_c2 + (x2 - x1);
            y4 = y3_c2 + (y2 - y1);
        }
        else if (x2 == x3_c1 && y2 == y3_c1) {
            x4 = x3_c2 + (x1 - x2);
            y4 = y3_c2 + (y1 - y2);
        } else if(x1 == x3_c2 && y1 == y3_c2) {
            x4 = x3_c1 + (x2 - x1);
            y4 = y3_c1 + (y2 - y1);
        } else {
            x4 = x3_c1 + (x1 - x2);
            y4 = y3_c1 + (y1 - y2);
        }

        cout << x4 << ' ' << y4 << '\n';
    }
}
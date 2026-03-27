#include <iostream>
using namespace std;

int getPrice(int n, int time, int price) {
    int result = (n + 1) / time * price;
    if((n + 1) % time) result += price;
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, inp;
    int price1 = 0;
    int price2 = 0;

    cin >> N;

    for(int i=0; i < N; i++) {
        cin >> inp;
        price1 += getPrice(inp, 30, 10);
        price2 += getPrice(inp, 60, 15);
    }

    if(price1 < price2) {
        cout << "Y " << price1;
    } else if(price2 < price1) {
        cout << "M " << price2;
    } else {
        cout << "Y M " << price2;
    }

}
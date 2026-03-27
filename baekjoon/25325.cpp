#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const pair<string, int>& a, const pair<string, int>& b) {
    if(a.second == b.second) {
        return a.first < b.first;
    }
    return a.second > b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    string inp, word;
    cin >> n;

    map<string, int> m;

    for(int i=0; i < n; i++) {
        cin >> inp;
        m.insert({inp, 0});
    }

    cin.ignore();

    size_t pos = 0;
    size_t cur_pos = 0;
    for(int i=0; i < n; i++) {
        getline(cin, inp);

        stringstream ss(inp);
        while(ss >> word) {
            m[word]++;
        }
    }

    vector<pair<string, int>> vec(m.begin(), m.end());

    sort(vec.begin(), vec.end(), compare);

    for(const auto& element: vec) {
        cout << element.first << ' ' << element.second << '\n';
    }
}
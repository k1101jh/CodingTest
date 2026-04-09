#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define SWAP(type, a, b) do (type temp = a; a = b; b = temp;) while(0);
using namespace std;

map<char, int> tier_dict = {
    {'B', 0},
    {'S', 1},
    {'G', 2},
    {'P', 3},
    {'D', 4},
};

map<int, char> reverse_tier_dict = {
    {0, 'B'},
    {1, 'S'},
    {2, 'G'},
    {3, 'P'},
    {4, 'D'},
};

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    if(a.first < b.first) {
        return true;
    } else if(a.first > b.first) {
        return false;
    } else {
        return a.second > b.second;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    string inp;

    vector<pair<int, int>> vec(N, {0, 0});

    for(int i=0; i < N; i++) {
        cin >> inp;
        int tier = tier_dict[inp[0]];
        int rank = stoi(inp.substr(1));
        vec[i] = {tier, rank};
    }

    vector<pair<int, int>> ref_vec(vec.begin(), vec.end());
    sort(ref_vec.begin(), ref_vec.end(), compare);

    bool is_sorted = true;
    vector<pair<int, int>> ans;
    for(int i=0; i < N; i++) {
        if(vec[i] != ref_vec[i]) {
            is_sorted = false;
            ans.push_back(ref_vec[i]);
        }
    }

    if(is_sorted) {
        cout << "OK" << '\n';
    } else {
        cout << "KO" << '\n';
        for(const auto& element: ans) {
            cout << reverse_tier_dict[element.first] << element.second << ' ';
        }
        cout << '\n';
    }
}
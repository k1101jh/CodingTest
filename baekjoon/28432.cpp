#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, idx;
    string inp;
    cin >> N;

    vector<string> vec;
    set<string> word_set;

    for(int i=0; i < N; i++) {
        cin >> inp;
        if(inp == "?") {
            idx = i;
            continue;
        }
        vec.push_back(inp);
        word_set.insert(inp);
    }

    char start = '0';
    char end = '0';

    if(idx > 0) {
        start = vec[idx - 1].back();
    }
    if(idx < N - 1) {
        end = vec[idx][0];
    }

    cin >> M;
    for(int i=0; i < M; i++) {
        cin >> inp;
        if(word_set.find(inp) != word_set.end()) {
            continue;
        }
        if((start == '0' || inp[0] == start) && (end == '0' || inp.back() == end)) {
            cout << inp << '\n';
            break;
        }
    }
}
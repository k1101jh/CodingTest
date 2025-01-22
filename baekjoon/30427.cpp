#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int N, M;
set<string> names;
set<string> observed_names;

bool CheckNoObservationHomePresence(string name) {
    if(find(observed_names.begin(), observed_names.end(), name) != observed_names.end()) return false;
    if(find(names.begin(), names.end(), name) == names.end()) return false;
    return true;
}

string Solution() {
    // condition 1
    if(find(names.begin(), names.end(), "dongho") != names.end()) {
        return "dongho";
    }

    vector<string> candidates;

    set<string>::iterator name_iter = names.begin();
    // set<string>::iterator observed_iter = observed_names.begin();
    for(const auto& observed : observed_names) {

        while(name_iter != names.end() && *name_iter < observed) {
            candidates.push_back(*name_iter);
            name_iter++;
        }

        if(name_iter == names.end()) {
            break;
        }

        if(*name_iter == observed) {
            name_iter++;
            continue;
        } else {
            continue;
        }
    }

    while(name_iter != names.end()) {
        candidates.push_back(*name_iter);
        name_iter++;
    }

    // condition 2
    if(candidates.size() == 1) {
        return candidates[0];
    }

    // condition 3 ~ 5
    if(find(candidates.begin(), candidates.end(), "bumin") != candidates.end()) return "bumin";
    if(find(candidates.begin(), candidates.end(), "cake") != candidates.end()) return "cake";
    if(find(candidates.begin(), candidates.end(), "lawyer") != candidates.end()) return "lawyer";

    // condition 6
    if(candidates.size() > 1) {
        if(candidates[0] == "swi") 
            return candidates[1];
        return candidates[0];
    }

    return "something wrong";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    getline(cin, s);
    
    cin >> N;

    names.insert("swi");
    for(int i=0; i < N; i++) {
        cin >> s;
        names.insert(s);
    }

    cin >> M;

    for(int i=0; i < M; i++) {
        cin >> s;
        observed_names.insert(s);
    }

    cout << Solution();
}
#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    Node(string s)
    : cur_s(s)
    {
        num_childs = 0;
    }

    void Insert(string s) {
        if(s == "")
            return;
        
        if(cur_s != "") {
            child_nodes[cur_s[0] - 'a'] = new Node(cur_s.substr(1, cur_s.size() - 1));
            cur_s = "";
            num_childs++;
        }
        
        if(child_nodes[s[0] - 'a'] != nullptr) {
            child_nodes[s[0] - 'a']->Insert(s.substr(1, s.size() - 1));
        } else {
            child_nodes[s[0] - 'a'] = new Node(s.substr(1, s.size() - 1));
            num_childs++;
        }
    }

    int Count(int len) {
        if(num_childs == 0) {
            return len;
        }

        int cnt = 0;
        for(auto child_node : child_nodes) {
            if(child_node != nullptr) cnt += child_node->Count(len + 1);
        }
        return cnt;
    }

    string cur_s;
    Node* child_nodes[26] = {nullptr,};
    int num_childs;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, l;
    cin >> n >> l;

    vector<string> names(n, "");
    for(int i=0; i < n; i++) {
        cin >> names[i];
    }

    Node root("");

    for(int i=0; i < n; i++) {
        root.Insert(names[i]);
    }
    
    int cnt = root.Count(0);
    cout << cnt << '\n';
}
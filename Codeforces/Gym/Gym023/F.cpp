#pragma gcc optimize ("O2")
#pragma gcc optimize ("unroll-loops")

#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 5e4 + 10, M = 26;

int tc;
int n;

struct Trie{
    struct Node{
        Node * next[M];
        int g;

        Node() : g(0) {
            for (int i=0;i<M;i++){
                next[i] = 0;
            }
        }
    };
    Node * head;
    Trie(){
        head = new Node();
    }
    void update(Node * node){
        vector<int> v;
        for (int i=0;i<M;i++){
            if (node->next[i]){
                v.pb(node->next[i]->g + 1);
            }
        }
        int ng = 0;
        for (auto x : v) ng ^= x;
        node->g = ng;
    }
    void dfs(const string& s, Node * node, int pos){
        if (pos == s.size()) return;

        int c = s[pos] - 'a';
        if (node->next[c] == 0){
            node->next[c] = new Node();
        }
        dfs(s, node->next[c], pos + 1);
        update(node);
    }
    void insert(const string& s){
        dfs(s, head, 0);
    }
    int get(){
        return head->g;
    }
};

void solve(){
    cin >> n;
    Trie t;
    for (int i=1;i<=n;i++){
        string temp;
        cin >> temp;
        t.insert(temp);
    }
    int q;
    cin >> q;
    while (q--){
        string temp;
        cin >> temp;
        t.insert(temp);
        if (t.get() == 0){
            cout << 2 << el;
        } else{
            cout << 1 << el;
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    for (int i=1;i<=tc;i++){
        cout << "Case " << i << ":\n";
        solve();
    }

    return 0;
}
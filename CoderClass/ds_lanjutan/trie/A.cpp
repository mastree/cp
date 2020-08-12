#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e5 + 10;

vector<int> act;

struct Trie{
    struct Node{
        int cnt; // last
        Node * ch[26];
        Node() {
            cnt = 0;
            for (auto& x : ch) x = 0; 
        }
    };
    Node * head;
    int kata = 0;
    Trie() {
        head = new Node();
    }

    void insert(const string& s){
        Node * cur = head;
        kata++;
        for (auto x : s){
            int dig = (int)(x - 'a');
            if (!cur->ch[dig]) cur->ch[dig] = new Node();
            cur = cur->ch[dig];
        }
        cur->cnt++;
    }
    int dfs(Node * node){
        int ret = 0;
        for (int i=0;i<26;i++){
            if (node->ch[i]){
                ret++;
                ret += dfs(node->ch[i]);
            }
        }
        if (node->cnt){
            ret += node->cnt;
            kata -= node->cnt;
        }
        ret++;
        return ret;
    }
    int ask(){
        return dfs(head);
    }
};

int n;
Trie trie;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    int mx = 0;
    for (int i=1;i<=n;i++){
        string s;
        cin >> s;
        mx = max(mx, (int)s.size());
        trie.insert(s);
    }
    cout << trie.ask() - (mx + 1) << el;

    return 0;
}
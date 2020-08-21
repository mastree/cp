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
        int cnt;
        bool ada;
        Node * ch[26];
        Node() {
            ada = cnt = 0;
            for (auto& x : ch) x = 0; 
        }
    };
    Node * head;
    Trie() {
        head = new Node();
    }
    bool ada(const string& s){
        Node * cur = head;
        for (auto x : s){
            int dig = (int)(x - 'a');
            if (!cur->ch[dig]) cur->ch[dig] = new Node();
            cur = cur->ch[dig];
        }
        return cur->ada;
    }
    void insert(const string& s){
        if (ada(s)) return;
        Node * cur = head;
        for (auto x : s){
            cur->cnt++;
            int dig = (int)(x - 'a');
            if (!cur->ch[dig]) cur->ch[dig] = new Node();
            cur = cur->ch[dig];
        }
        cur->cnt++;
        cur->ada = 1;
    }
    int ask(const string& s){
        Node * cur = head;
        for (auto x : s){
            int dig = (int)(x - 'a');
            if (!cur->ch[dig]) cur->ch[dig] = new Node();
            cur = cur->ch[dig];
        }
        return cur->cnt;
    }
};

int n;
Trie trie;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        int tipe;
        string s;
        cin >> tipe >> s;
        if (tipe == 1){
            trie.insert(s);
        } else{
            cout << trie.ask(s) << el;
        }
    }

    return 0;
}
#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int K = 26;

struct Vertex{
    int next[K];
    int go[K];
    int id = -1;
    char pch;
    int p = -1;
    int link = -1;

    Vertex(int p = -1, char ch = '$') : p(p), pch(ch) {
        fill(begin(next), end(next), -1);
        fill(begin(go), end(go), -1);
    }
};
vector<Vertex> t(1);

void add_string(string s, int id){
    int v = 0;
    for (auto ch : s){
        int c = ch - 'a';
        if (t[v].next[ch] == -1){
            t[v].next[ch] = t.size();
            t.emplace_back(v, ch);
        }
        v = t[v].next[c];
    }
    t[v].id = id;
}
int go(int v, char ch);
int get_link(int v){
    if (t[v].link == -1){
        if (v == 0 ||  t[v].p == 0){
            t[v].link = 0;
        } else{
            t[v].link = go(get_link(t[v].p), t[v].pch);
        }
    }
    return t[v].link;
}
int go(int v, int ch){
    int c = ch - 'a';
    if (t[v].go[c] == -1){
        if (t[v].next[c] != -1){
            t[v].go[c]  = t[v].next[c];
        } else{
            t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
        }
    }
    return t[v].go[c];
}

const int N = 1e5 + 10;

string s;
int n, q;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    n = s.size();
    cin >> q;
    for (int i=1;i<=q;i++){
        int k;
        string st;
        cin >> k >> st;
        add_string(st, i);
    }


    return 0;
}
#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int K = 70;
const int N = 1e6 + 10;
struct Vertex{
    int go[K];
    // int id = -1;
    vector<int> id;
    char pch;
    int p = -1;
    int link = -1;

    int deg = 0;

    Vertex(int p = -1, char ch = '$') : p(p), pch(ch) {
        fill(begin(go), end(go), -1);
    }
};
vector<Vertex> t;
set<int> ans;
bool ada[N];

void add_string(const string& s, int id){
    int v = 0;
    for (auto ch : s){
        int c = ch - 'A';
        if (t[v].go[c] <= v){
            t[v].go[c] = t.size();
            t.emplace_back(v, ch);
        }
        v = t[v].go[c];
    }
    t[v].id.pb(id);
}
int go(int v, char ch);
int get_link(int v) {
    if (t[v].link == -1) {
        if (v == 0 || t[v].p == 0)
            t[v].link = 0;
        else
            t[v].link = go(get_link(t[v].p), t[v].pch);
    }
    return t[v].link;
}

int go(int v, char ch) {
    int c = ch - 'A';
    if (t[v].go[c] == -1) {
        t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
    }
    return t[v].go[c];
}

void solve(const string& s){
    int v = 0;
    for (auto ch : s){
        ada[v] = 1;
        v = go(v, ch);
    }
    ada[v] = 1;
    queue<int> qu;
    for (int i=0;i<t.size();i++){
        if (ada[i]) qu.push(i);
    }
    while (!qu.empty()){
        int tp = qu.front();
        qu.pop();

        int lnk = get_link(tp);
        if (!ada[lnk]){
            ada[lnk] = 1;
            qu.push(lnk);
        }
    }
    for (int i=0;i<t.size();i++){
        if (ada[i]){
            for (auto x : t[i].id){
                ans.insert(x);
            }
        }
    }
}
void init(){
    fill(ada, ada + N, 0);
    ans.clear();
    t.clear();
    t.push_back(Vertex());
}

void solve(){
    init();
    string s;
    cin >> s;
    int n;
    cin >> n;

    for (int i=1;i<=n;i++){
        string t;
        cin >> t;
        add_string(t, i);
    }
    solve(s);
    for (int i=1;i<=n;i++){
        if (ans.find(i) != ans.end()){
            cout << "ADA" << el;
        } else{
            cout << "TIDAK" << el;
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> q;
    while (q--){
        solve();
    }

    return 0;
}
#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'

using namespace std;

const int N = 5e5 + 10;

int n, q;
vector<int> adl[N];

int timer, tin[N], tout[N];
vector<int> tur;
int t[8 * N];
int lazy[8 * N]; // query-id

int t2[8 * N];

void dfs(int node, int p){
    tin[node] = ++timer;
    tur.pb(node);
    for (auto x : adl[node]){
        if (x == p) continue;
        dfs(x, node);
    }
    tout[node] = ++timer;
    tur.pb(node);
}

bool is_ancestor(int a, int b){
    return tin[a] <= tin[b] && tout[b] <= tout[a];
}

void push(int v){
    lazy[v * 2] = max(lazy[v * 2], lazy[v]);
    lazy[v * 2 + 1] = max(lazy[v * 2 + 1], lazy[v]);
    t[v * 2] = max(t[v * 2], lazy[v]);
    t[v * 2 + 1] = max(t[v * 2 + 1], lazy[v]);
    lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, int val){
    if (l > r) return;
    else if (l == tl && tr == r){
        lazy[v] = max(lazy[v], val);
        t[v] = max(t[v], val);
        return;
    } 
    push(v);
    int tm = (tl + tr) / 2;
    update(v * 2, tl, tm, l, min(tm, r), val);
    update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
    t[v] = max(t[v * 2], t[v * 2 + 1]);
}

int ask(int v, int tl, int tr, int l, int r){
    if (l > r) return 0;
    else if (l <= tl && tr <= r){
        return t[v];
    }
    push(v);
    int tm = (tl + tr) / 2;
    return max(ask(v * 2, tl, tm, l, min(tm, r)), ask(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

void update2(int v, int tl, int tr, int pos, int qid){
    if (tr < pos || pos < tl) return;
    else if (tl == tr){
        t2[v] = qid;
        return;
    }
    int tm = (tl + tr) / 2;
    update2(v * 2, tl, tm, pos, qid);
    update2(v * 2 + 1, tm + 1, tr, pos, qid);
    t2[v] = max(t2[v * 2], t2[v * 2 + 1]);
}

int ask2(int v, int tl, int tr, int l, int r){
    if (l > r) return 0;
    else if (l <= tl && tr <= r){
        return t2[v];
    }
    int tm = (tl + tr) / 2;
    return max(ask2(v * 2, tl, tm, l, min(tm, r)), ask2(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adl[a].pb(b);
        adl[b].pb(a);
    }
    tur.pb(0);
    dfs(1, 1);
    cin >> q;
    int qid = 0;
    while(q--){
        qid++;
        int tipe, v;
        cin >> tipe >> v;
        if (tipe == 1){
            update(1, 1, timer, tin[v], tout[v], qid);
        } else if (tipe == 2){
            update2(1, 1, timer, tin[v], qid);
            update2(1, 1, timer, tout[v], qid);
        } else{
            int idisi = ask(1, 1, timer, tin[v], tin[v]);
            idisi = max(idisi, ask(1, 1, timer, tout[v], tout[v]));
            int idkosong = ask2(1, 1, timer, tin[v], tout[v]);
            // cout << idisi << " " << idkosong << el;
            cout << (idisi > idkosong) << el;
        }
    }

    return 0;
}
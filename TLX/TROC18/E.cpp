#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e5 + 10;

int n;
vector<int> adj[N];

int t[8 * N], lazy[8 * N];
int tin[N], tout[N], len;
vector<int> tur;
void dfs_euler(int node, int p){
    tin[node] = len++;
    for (auto& x : adj[node]){
        if (x == p) continue;
        dfs_euler(x, node);
    }
    tout[node] = len++;
}
void init(){
    dfs_euler(1, 1);
}
void push(int v, int tl, int tr){
    int tm = (tl + tr) / 2;
    if (lazy[v]){
        lazy[v * 2] = (lazy[v * 2] ^ lazy[v]);
        lazy[v * 2 + 1] = (lazy[v * 2 + 1] ^ lazy[v]);
        if ((tm - tl + 1) & 1){
            t[v * 2] = (t[v * 2] ^ lazy[v]);
        }
        if ((tr - tm) & 1){
            t[v * 2 + 1] = (t[v * 2 + 1] ^ lazy[v]);
        }
        lazy[v] = 0;
    }
}
void update(int v, int tl, int tr, int l, int r, int val){
    if (l > r || tr < l || r < tl) return;
    else if (l <= tl && tr <= r){
        lazy[v] = (lazy[v] ^ val);
        if ((tr - tl + 1) & 1) t[v] = (t[v] ^ val);
        return;
    }
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    update(v * 2, tl, tm, l, r, val);
    update(v * 2 + 1, tm + 1, tr ,l, r, val);
    t[v] = (t[v * 2] ^ t[v * 2 + 1]);
}
int ask(int v, int tl, int tr, int l, int r){
    if (l > r || tr < l || r < tl) return 0;
    else if (l <= tl && tr <= r){
        return t[v];
    }
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    return (ask(v * 2, tl, tm, l, r) ^ ask(v * 2 + 1, tm + 1, tr, l, r));
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    init();
    int q;
    cin >> q;
    while (q--){
        int tipe;
        cin >> tipe;
        if (tipe == 1){
            int u, x;
            cin >> u >> x;
            update(1, 0, len - 1, tin[u], tout[u], x);
        } else{
            int u;
            cin >> u;
            cout << ask(1, 0, len - 1, 0, tin[u]) << el;
        }
    }

    return 0;
}
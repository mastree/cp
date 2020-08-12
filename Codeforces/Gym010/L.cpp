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
const int INF = 1e9;

bool ok = 1;
int n, f;
vector<int> adj[N];
set<pair<int, pii>> range;
vector<int> hpath, tony;

int dep[N], parent[N];
int head[N], heavy[N], pos[N], timer;

ll t[4 * N];

unordered_map<int, bool> cek[N];
int cnt[N];

int dfs_heavy(int node, int p){
    if (node != p) dep[node] = dep[p] + 1;
    parent[node] = p;

    int ret = 1, mx = 0;
    for (auto x : adj[node]){
        if (x == p) continue;
        int cur = dfs_heavy(x, node);
        ret += cur;
        if (cur > mx){
            mx = cur;
            heavy[node] = x;
        }
    }
    return ret;
}

void decompose(int node, int h){
    head[node] = h;
    hpath.pb(node);
    pos[node] = timer++;
    if (heavy[node]){
        decompose(heavy[node], h);
    }
    for (auto x : adj[node]){
        if (x == parent[node] || x == heavy[node]) continue;
        decompose(x, x);
    }
}

void update(int a, int b){
    for (; head[a] != head[b]; b = parent[head[b]]){
        if (dep[head[a]] > dep[head[b]]) swap(a, b);
        tony[pos[head[b]]]++;
        tony[pos[b] + 1]--;
    }
    if (dep[a] > dep[b]) swap(a, b);
    if (a == b) return;
    tony[pos[a] + 1]++;
    tony[pos[b] + 1]--;
}

int LCA(int a, int b){
    for (; head[a] != head[b]; b = parent[head[b]]){
        if (dep[head[a]] > dep[head[b]]) swap(a, b);
    }
    if (dep[a] > dep[b]) swap(a, b);
    return a;
}

void push(int v, int range){

}

void upd(int v, int tl, int tr, int l, int r, int add){
    if (l > r) return;
    else if (l <= tl && tr <= r){
        lazy[v] += add;
        t[v] 
    }
}

void ask(int v, int tl, int tr, int l, int r){

}

void update2(int a, int b){
    for (; head[a] != head[b]; b = parent[head[b]]){
        if (dep[head[a]] > dep[head[b]]) swap(a, b);
        tony[pos[head[b]]]++;
        tony[pos[b] + 1]--;
    }
    if (dep[a] > dep[b]) swap(a, b);
    if (a == b) return;
    tony[pos[a] + 1]++;
    tony[pos[b] + 1]--;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> f;
    for (int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs_heavy(1, 1);
    decompose(1, 1);
    int plen = hpath.size();
    tony.resize(plen + 2, 0);
    for (int i=1;i<=f;i++){
        int a, b;
        cin >> a >> b;
        if (a == b) continue;
        if (a > b) swap(a, b);
        update(a, b);
        int lca = LCA(a, b);
        range.insert(mp(dep[a] + dep[b] - dep[lca] - dep[lca], mp(a, b)));
    }
    int cur = 0;
    for (int i=0;i<plen;i++){
        cur += tony[i];
        tony[i] = cur;
        if (cur){
            cek[hpath[i]][parent[hpath[i]]] = 1;
        }
    }
    for (int i=1;i<=n;i++){
        for (auto x : cek[i]){
            if (x.se) cnt[i]++, cnt[x.fi]++;
        }
    }
    for (int i=1;i<=n;i++){
        if (cnt[i] > 2){
            ok = 0;
            break;
        }
    }
    if (!ok){
        cout << "No" << el;
        return 0;
    }
    for (auto x : range){
        int a = x.se.fi, b = x.se.se;
        update2(a, b);
    }
    if (!ok){
        cout << "No" << el;
    } else{
        cout << "Yes" << el;
    }

    return 0;
}
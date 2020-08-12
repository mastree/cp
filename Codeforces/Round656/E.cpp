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

int q;
int n, m;
vector<int> adj[N], radj[N];
vector<pii> edges;
unordered_map<int, bool> arah[N];

int comp[N], sz[N];
vector<int> order;
bool vis[N];

void dfs1(int node){
    vis[node] = 1;
    for (auto x : adj[node]){
        if (!vis[x]) dfs1(x);
    }
    order.pb(node);
}

void dfs2(int node, int cc){
    comp[node] = cc;
    sz[cc]++;
    for (auto x : radj[node]){
        if (!comp[x]) dfs2(x, cc);
    }
}

void kosaraju(){
    for (int i=1;i<=n;i++){
        if (!vis[i]) dfs1(i);
    }
    for (int i=n - 1, j = 0;i>=0;i--){
        if (!comp[order[i]]){
            dfs2(order[i], ++j);
        }
    }
}

void init(){
    fill(comp, comp + n + 3, 0);
    fill(vis, vis + n + 3, 0);
    fill(sz, sz + n + 3, 0);
    order.clear();
    edges.clear();
    for (int i=1;i<=n;i++){
        adj[i].clear();
        radj[i].clear();
        arah[i].clear();
    }
}

void solve(){
    cin >> n >> m;
    init();
    for (int i=1;i<=m;i++){
        bool dir;
        int a, b;
        cin >> dir >> a >> b;
        if (dir){
            arah[a][b] = 1;
            adj[a].pb(b);
            radj[b].pb(a);
        }
        edges.pb(mp(a, b));
    }
    kosaraju();
    bool ok = 1;
    for (int i=1;i<=n;i++){
        if (sz[i] > 1) ok = 0;
    }
    if (!ok){
        cout << "NO" << el;
        return;
    }
    cout << "YES" << el;
    for (auto x : edges){
        int a = x.fi, b = x.se;
        if (arah[a][b]){
            cout << a << " " << b << el;
            continue;
        }
        if (comp[b] > comp[a]) cout << a << " " << b << el; 
        else cout << b << " " << a << el;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        solve();
    }

    return 0;
}
#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;

const int N = 1e5 + 10, M = 17;
const ll INF = 1e18;

int n, m;
int par[N], sz[N];
vector<pair<ll, pii>> edges, buang;

int find(int a){
    if (par[a] == a) return a;
    return par[a] = find(par[a]);
}
void make(int a, int b){
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
}
void init(){
    for (int i=1;i<=n;i++){
        par[i] = i;
        sz[i] = 1;
    }
}

ll ans;

vector<pil> adj[N];

int tin[N], tout[N], timer;
int up[N][M];
ll mx[N][M];

void dfs_init(int node, int p, ll cost){
    tin[node] = ++timer;
    up[node][0] = p;
    mx[node][0] = cost;
    for (int i=1;i<M;i++){
        up[node][i] = up[up[node][i - 1]][i - 1];
        mx[node][i] = max(mx[node][i - 1], mx[up[node][i - 1]][i - 1]);
    }
    for (auto x : adj[node]){
        if (x.fi == p) continue;
        dfs_init(x.fi, node, x.se);
    }
    tout[node] = ++timer;
}
bool is_ancestor(int a, int b){
    return tin[a] <= tin[b] && tout[b] <= tout[a];
}
int LCA(int a, int b){
    if (is_ancestor(a, b)) return a;
    else if (is_ancestor(b, a)) return b;
    for (int i=M - 1;i>=0;i--){
        if (!is_ancestor(up[a][i], b)){
            a = up[a][i];
        }
    }
    return up[a][0];
}
ll calc(int a, int b){
    if (a == b) return 0;
    ll ret = 0;
    for (int i=M - 1;i>=0;i--){
        if (!is_ancestor(up[a][i], b)){
            ret = max(ret, mx[a][i]);
            a = up[a][i];
        }
    }
    ret = max(ret, mx[a][0]);
    return ret;
}
ll max_path(int a, int b){
    int lca = LCA(a, b);
    return max(calc(a, lca), calc(b, lca));
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    init();
    for (int i=1;i<=m;i++){
        int a, b;
        ll w;
        cin >> a >> b >> w;
        edges.pb(mp(w, mp(a, b)));
    }
    sort(edges.begin(), edges.end());
    for (auto x : edges){
        int a, b;
        a = x.se.fi;
        b = x.se.se;
        if (find(a) == find(b)){
            buang.pb(x);
            continue;
        }
        ans += x.fi;
        adj[a].pb(mp(b, x.fi));
        adj[b].pb(mp(a, x.fi));
        make(a, b);
    }
    ll mn = INF;
    dfs_init(1, 1, 0);
    for (auto x : buang){
        int a, b;
        a = x.se.fi;
        b = x.se.se;
        ll w = x.fi;

        mn = min(mn, w - max_path(a, b));
    }
    cout << ans + mn << el;

    return 0;
}
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
using pli = pair<ll, int>;

const int N = 1e5 + 10;
const ll MOD = 1e9 + 7;

int q;
int n, m;
ll base;
vector<pair<int, pii>> edges;
vector<pil> adj[N];

int par[N], sz[N];
int find(int a){
    return (par[a] == a ? a : par[a] = find(par[a]));
}
void make(int a, int b, ll w){
    adj[a].pb(mp(b, w));
    adj[b].pb(mp(a, w));
    a = find(a);
    b = find(b);
    if (sz[a] < sz[b]) swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
}

void init(){
    edges.clear();
    for (int i=0;i<N;i++){
        par[i] = i;
        sz[i] = 1;
        adj[i].clear();
    }
}

int szt[N];
void dfs(int node, int p){
    szt[node] = 1;
    for (auto x : adj[node]){
        if (x.fi == p) continue;
        dfs(x.fi, node);
        szt[node] += szt[x.fi];
    }
}

ll ans;
void dfs_push(int node, int p){
    for (auto x : adj[node]){
        if (x.fi == p) continue;
        dfs_push(x.fi, node);
        ans = (ans + ((1LL * (n - szt[x.fi]) * szt[x.fi]) % MOD) * x.se % MOD) % MOD;
    }
}

void solve(){
    cin >> n >> m >> base;
    init();

    if (1){
        int pang = 0;
        for (int i=1;i<=m;i++){
            int a, b;
            cin >> a >> b;
            edges.pb(mp(pang, mp(a, b)));
            pang++;
        }
    }
    sort(edges.begin(), edges.end());
    ll cur = 1;
    for (auto x : edges){
        int a = x.se.fi;
        int b = x.se.se;
        a = find(a);
        b = find(b);
        if (a == b){
            cur = cur * 2LL % MOD;
            continue;
        }
        make(x.se.fi, x.se.se, cur * base % MOD);
        cur = cur * 2LL % MOD;
    }
    dfs(1, 1);
    ans = 0;
    dfs_push(1, 1);

    cout << ans << el;
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
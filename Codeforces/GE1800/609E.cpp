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

const int N = 2e5 + 10;
const int M = 18;

int n, m;
vector<pil> adl[N];
vector<pair<ll, pii>> edge, sedge;
ll mst_w;

int par[N], sz[N];

int timer, tin[N], tout[N];
pair<int, ll> up[N][M];

int find(int a){
    if (par[a] == a) return a;
    return par[a] = find(par[a]);
}

void make(int a, int b, ll w){
    int ra = a, rb = b;
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    par[b] = a;
    adl[a].pb(mp(b, w));
    adl[b].pb(mp(a, w));
    mst_w += w;
}

void dfs_init(int node, int p){
    tin[node] = ++timer;
    for (auto x : adl[node]){
        if (x.fi == p) continue;
        up[x.fi][0] = mp(node, x.se);
        dfs_init(x.fi, node);
    }
    tout[node] = ++timer;
}

void init(){
    for (int j=1;j<M;j++){
        for (int i=1;i<=n;i++){
            up[i][j].fi = up[up[i][j - 1].fi][j - 1].fi;
            up[i][j].se = max(up[i][j - 1].se, up[up[i][j - 1].fi][j - 1].se);
        }
    }
}  

bool is_ancestor(int a, int b){
    return tin[a] <= tin[b] && tout[b] <= tout[a];
}

pil LCA(int a, int b){
    ll cur = 0;
    if (!is_ancestor(a, b)){
        for (int i=M - 1;i>=0;i--){
            if (!is_ancestor(up[a][i].fi, b)){
                cur = max(cur, up[a][i].se);
                a = up[a][i].fi;
            }
        }
        cur = max(cur, up[a][0].se);
        a = up[a][0].fi;
    }
    if (a == b) return mp(a, cur);
    for (int i=M - 1;i>=0;i--){
        if (!is_ancestor(up[b][i].fi, a)){
            cur = max(cur, up[b][i].se);
            b = up[b][i].fi;
        }
    }
    cur = max(cur, up[b][0].se);
    b = up[b][0].fi;
    return mp(a, cur);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=n;i++){
        par[i] = i;
        sz[i] = 1;
    }
    for (int i=1;i<=m;i++){
        int a, b;
        ll w;
        cin >> a >> b >> w;
        pair<ll, pii> temp = mp(w, mp(a, b));
        edge.pb(temp);
        sedge.pb(temp);
    }
    sort(sedge.begin(), sedge.end());
    for (auto x : sedge){
        ll w = x.fi;
        int a = x.se.fi, b = x.se.se;
        make(a, b, w);
    }
    up[1][0] = mp(1, 0);
    // cout << mst_w << el;
    dfs_init(1, 1);
    init();
    for (int i=0;i<m;i++){
        ll w = edge[i].fi;
        pii x = edge[i].se;
        auto temp = LCA(x.fi, x.se);
        cout << mst_w + w - temp.se << el;
    }

    return 0;
}
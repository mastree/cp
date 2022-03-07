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
using pll = pair<ll, ll>;

const int N = 1e5 + 10;
const ll INF = 1e18;

int n, q;
vector<pil> adj[N];
vector<pii> quers;
vector<ll> ans;

void dfs(int node, int p, ll dist, int& sc, vector<vector<ll>>& mat){
    mat[sc][node] = dist;
    for (auto& x : adj[node]){
        if (x.fi == p) continue;
        dfs(x.fi, node, dist + x.se, sc, mat);
    }
}

int par[N], sz[N];
// vector<int> ids[N];
int find(int a){
    if (a == par[a]) return a;
    return par[a] = find(par[a]);
}
void make(int a, int b, ll dist){
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    par[a] = b;
    sz[a] += sz[b];
    for (int i=0;i<q;i++){
        int u = quers[i].fi;
        int v = quers[i].se;
        if (find(u) == find(v)) ans[i] = max(ans[i], dist);
    }
}
void init_disjoint(){
    for (int i=1;i<=n;i++){
        par[i] = i;
        sz[i] = 1;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    for (int i=1;i<n;i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].pb(mp(b, c));
        adj[b].pb(mp(a, c));
    }
    {
        for (int i=0;i<q;i++){
            int a, b;
            cin >> a >> b;
            quers.pb(mp(a, b));
            ans.pb(-INF);
        }

        vector<vector<ll>> mat(n + 1, vector<ll>(n + 1, 0));
        for (int sc=1;sc<=n;sc++){
            dfs(sc, sc, 0, sc, mat);
        }
        vector<pair<ll, pii>> vec;
        // vector<vector<ll>> ans(n + 1, vector<ll>(n + 1, -INF));
        for (int i=1;i<=n;i++){
            // ans[i][i] = 0;
            for (int j=i + 1;j<=n;j++){
                // cout << mat[i][j] << ' ';
                vec.pb(mp(mat[i][j], mp(i, j)));
            }
            // cout << el;
        } 
        sort(vec.begin(), vec.end(), greater<pair<ll, pii>>());
        init_disjoint();
        for (auto& edge : vec){
            make(edge.se.fi, edge.se.se, edge.fi);
        }
        for (auto& x : ans){
            cout << x << el;
        }
    }

    return 0;
}
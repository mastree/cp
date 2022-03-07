#pragma gcc optimize ("O2")
#pragma gcc optimize ("unroll-loops")

#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

const ll INF = 1e18;
const int N = 2e5 + 10;
const int L = ceil(log2(N)) + 3;

int n, q;
int ar[N];
vector<int> adj[N];
int up[N][L];
int tin[N], tout[N], tim;
int parent[N];
int depth[N];

void processLCA(int u, int p) {
    depth[u] = (u == p ? 0 : 1 + depth[p]);
    up[u][0] = p;
    parent[u] = p;
    tin[u] = ++tim;
    for (int i = 1; i < L; i++)
        up[u][i] = up[up[u][i - 1]][i - 1];
    for (auto v : adj[u]) {
        if (v == p) continue;
        processLCA(v, u);
    }
    tout[u] = ++tim;
}

bool is_ancestor(int a, int b){ // a ancestor b
    return tin[a] <= tin[b] && tout[b] <= tout[a];
}

int LCA(int u, int v) {
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;
    for (int i = L - 1; i >= 0; i--) {
        if (!is_ancestor(up[u][i], v)) u = up[u][i];
    }
    return up[u][0];
}

int distance(int u, int v) {
    int w = LCA(u, v);
    return depth[u] + depth[v] - 2 * depth[w];
}

void init(){
    processLCA(1, 1);
}

int u, v;
bool kasus;
bool skip(int x){
    if (kasus == 0){
        return x == parent[u] || x == parent[v];
    }
    return is_ancestor(u, x) && is_ancestor(x, v);
}
void dfs(int node, int p, int dist, vector<pii>& cur){
    cur[ar[node]].fi += dist;
    cur[ar[node]].se++;
    for (auto& x : adj[node]){
        if (x == p || skip(x)) continue;
        dfs(x, node, dist + 1, cur);
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    for (int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    init();
    cin >> q;
    while (q--){
        int tipe;
        cin >> tipe;
        if (tipe == 1){
            int x;
            cin >> x;
            ar[x] = !ar[x];
        } else{
            cin >> u >> v;
            if (is_ancestor(v, u)) swap(u, v);
            kasus = is_ancestor(u, v);
            vector<pii> vecu(2, mp(0, 0));
            vector<pii> vecv(2, mp(0, 0));
            dfs(u, u, 0, vecu);
            dfs(v, v, 0, vecv);
            
            ll tota = 0, bagia = 1;
            ll dst = distance(u, v);
            // 0
            {
                pii a = vecu[0];
                pii b = vecv[0];
                if (a.se == 0 || b.se == 0) tota = INF;
                else{
                    tota = a.se * b.se * dst + a.fi * b.se + a.se * b.fi;
                    bagia = a.se * b.se;
                }
            }
            // 1
            ll totb = 0, bagib = 1;
            {
                pii a = vecu[1];
                pii b = vecv[1];
                if (a.se == 0 || b.se == 0) totb = INF;
                else{
                    totb = a.se * b.se * dst + a.fi * b.se + a.se * b.fi;
                    bagib = a.se * b.se;
                }
            }
            if (tota == INF){
                if (totb == INF){
                    cout << "TIE" << el;
                } else{
                    cout << "B" << el;
                }
                continue;
            } else if (totb == INF){
                cout << "A" << el;
                continue;
            }
            if (tota * bagib == totb * bagia) cout << "TIE" << el;
            else if (tota * bagib < totb * bagia) cout << "A" << el;
            else cout << "B" << el;
        }
    }

    return 0;
}
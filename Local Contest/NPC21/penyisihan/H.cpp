#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 4e5 + 10;
const int H = 20;
const int MOD = 1e9 + 7;

int n, m;
vector<int> adj[N];
int q;

int tin[N], low[N], comp[N], sz[N];
int timer, compNum;
vector<int> st;

void dfs_scc(int node, int p){
    st.pb(node);
    tin[node] = low[node] = ++timer;
    for (auto x : adj[node]){
        if (x == p) continue;
        if (tin[x]){
            low[node] = min(low[node], tin[x]); 
        } else {
            dfs_scc(x, node);
            low[node] = min(low[node], low[x]);
        }
    }
    if (low[node] == tin[node]){
        compNum++;
        while (st.back() != node){
            comp[st.back()] = compNum;
            sz[compNum]++;
            st.pop_back();
        }
        comp[st.back()] = compNum;
        sz[compNum]++;
        st.pop_back();
    }
}
void tarjan(){
    for (int i=1;i<=n;i++){
        tin[i] = low[i] = comp[i] = 0;
    }
    timer = compNum = 0;
    st.clear();
    for (int i=1;i<=n;i++){
        if (tin[i] == 0){
            dfs_scc(i, i);
        }
    }
}
ll fpow(ll a, ll b){
    if (b < 0) return 0;
    ll ret = 1;
    while (b){
        if (b & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ret;
}

vector<int> tadj[N];
int tout[N];
pii up[H][N];
void dfs(int node, int p){
    up[0][node] = mp(p, 0);
    if (node > n && sz[node - n] >= 2) up[0][node].se = 1;
    for (int i=1;i<H;i++){
        up[i][node].fi = up[i - 1][up[i - 1][node].fi].fi;
        up[i][node].se = up[i - 1][node].se + up[i - 1][up[i - 1][node].fi].se;
    }
    tin[node] = ++timer;
    for (auto& x : tadj[node]){
        if (x == p) continue;
        dfs(x, node);
    }
    tout[node] = ++timer;
}
bool is_ancestor(int a, int b){
    return tin[a] <= tin[b] && tout[b] <= tout[a];
}
int get(int a, int b){
    if (a == b) return 0;
    if (is_ancestor(b, a)) swap(a, b);
    int ret = 0;
    for (int i=H - 1;i>=0;i--){
        if (!is_ancestor(up[i][b].fi, a)){
            ret += up[i][b].se;
            b = up[i][b].fi;
        }
    }
    ret += up[0][b].se;
    b = up[0][b].fi;

    for (int i=H - 1;i>=0;i--){
        if (!is_ancestor(up[i][a].fi, b)){
            ret += up[i][a].se;
            a = up[i][a].fi;
        }
    }
    if (!is_ancestor(a, b)) ret += up[0][a].se;
    if (!is_ancestor(b, a)) return -1;
    ret += up[0][b].se;
    return ret;
}
void build_lca(){
    fill(tin, tin + N, 0);
    fill(tout, tout + N, 0);
    timer = 0;
    for (int i=1;i<=n;i++) {
        if (tin[i] == 0) dfs(i, i);
    }
}
void solve(){
    int a, b;
    cin >> a >> b;
    cout << fpow(2, get(a, b)) << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    tarjan();
    for (int i=1;i<=n;i++){
        for (auto& x : adj[i]){
            if (comp[i] == comp[x]) continue;
            tadj[i].pb(x);
        }
        if (sz[comp[i]] >= 2){
            tadj[i].pb(n + comp[i]);
            tadj[n + comp[i]].pb(i);
        }
    }
    build_lca();
    cin >> q;
    while (q--){
        solve();
    }

    return 0;
}
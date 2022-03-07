#pragma gcc optimize ("O2")
#pragma gcc optimize ("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int n, m, q;
vector<int> adj[N];

int num[N], low[N], counter;
vector<pair<int, int>> edge, bridge, block[N];
int root;
bool artic[N];
int nblock;
int childroot;
int par[N];
int udh[N];

vector<int> bct[N];

void dfs(int v, int bef = -1){
    num[v] = low[v] = counter++;
    for (int u : adj[v]){
        if (num[u] == -1){
            edge.emplace_back(v, u);
            if (v == root) childroot++;
            dfs(u, v);
            if (childroot > 1 && v == root){
                artic[v] = 1;
                nblock++;
                while (edge.size() > 0){
                    auto it = edge.back();
                    edge.pop_back();
                    block[nblock].push_back(it);
                    if (it == make_pair(v, u)) break;
                }
            }
            if (low[u] >= num[v] && v != root){
                artic[v] = 1;
                nblock++;
                while (edge.size() > 0){
                    auto it = edge.back();
                    edge.pop_back();
                    block[nblock].push_back(it);
                    if (it == make_pair(v, u)) break;
                }
            }
            if (low[u] > num[v]) bridge.emplace_back(v, u);
            low[v] = min(low[v], low[u]);
        } else if (bef != u && num[v] > num[u]){
            low[v] = min(low[v], num[u]);
            edge.emplace_back(v, u);
        }
    }
}
void build_bct(){
    fill(num, num + n + 1, -1);
    for (int i=1;i<=n;i++){
        if (num[i] == -1){
            root = i;
            childroot = 0;
            edge.clear();
            dfs(i);
            artic[i] = childroot > 1;
            if (edge.size() > 0){
                nblock++;
                while (edge.size() > 0){
                    auto it = edge.back();
                    edge.pop_back();
                    block[nblock].push_back(it);
                }
            }
        }
    }
    for (int i=1;i<=nblock;i++){
        for (auto& x : block[i]){
            if (artic[x.first]){
                if (udh[nblock + x.first]) continue;
                udh[nblock + x.first] = 1;
                bct[i].push_back(nblock + x.first);
                bct[nblock + x.first].push_back(i);
            } else{
                par[x.first] = i;
            }
        }
        int last = block[i].back().second;
        if (artic[last]){
            if (!udh[nblock + last]){
                bct[i].push_back(nblock + last);
                bct[nblock + last].push_back(i);
            }
        } else{
            par[last] = i;
        }
        for (auto& x : block[i]){
            if (artic[x.first]) udh[nblock + x.first] = 0;
        }
    }
    for (int i=1;i<=n;i++){
        if (artic[i] || par[i] == 0){
            par[i] = nblock + i;
        }
    }
}

const int DEP = 19;

int dp[N];
int tin[N], tout[N], timer;
int up[N][DEP];

void dfs_lca(int v, int bef){
    up[v][0] = bef;
    for (int i=1;i<DEP;i++){
        up[v][i] = up[up[v][i - 1]][i - 1];
    }
    tin[v] = ++timer;
    dp[v] = dp[bef];
    if (v > nblock) dp[v]++;
    for (auto& u : bct[v]){
        if (u != bef){
            dfs_lca(u, v);
        }
    }
    tout[v] = ++timer;
}
bool is_ancestor(int a, int b){ // a anc b
    return tin[a] <= tin[b] && tout[b] <= tout[a];
}
int get_ancestor(int a, int b){
    if (is_ancestor(a, b)) return a;
    if (is_ancestor(b, a)) return b;
    if (!is_ancestor(up[a][DEP - 1], b)) return -1;
    for (int i=DEP - 2;i>=0;i--){
        if (!is_ancestor(up[a][i], b)) a = up[a][i];
    }
    return up[a][0];
}

void solve(){
    int v, u;
    cin >> v >> u;
    int anc = get_ancestor(par[v], par[u]);
    if (anc == -1){
        cout << 2 << '\n';
        return;
    }
    int ans = dp[par[v]] + dp[par[u]] - 2 * dp[anc] + (anc > nblock) - artic[v] - artic[u] + 2;
    cout << ans << '\n';
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    for (int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    build_bct();
    for (int i=1;i<=n;i++){
        if (!tin[par[i]]){
            dfs_lca(par[i], par[i]);
        }
    }
    
    cin >> q;
    while (q--){
        solve();
    }

    return 0;
}
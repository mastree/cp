#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const ll MOD = 1e9 + 7;
const int N = 1e5 + 10, M = 17;

int n;
vector<pii> adj[N];
// int sz[N];

// void dfs_size(int node, int p){
//     sz[node] = 1;
//     for (auto x : adj[node]){
//         if (x.fi == p) continue;
//         dfs_size(x.fi, node);
//         sz[node] += sz[x.fi];
//     }
// }

int tin[N], tout[N], timer;
int dep[N];
int up[N][M];

void dfs_init(int node, int p){
    dep[node] = dep[p] + 1;
    up[node][0] = p;
    for (int i=1;i<M;i++){
        up[node][i] = up[up[node][i - 1]][i - 1];
    }
    tin[node] = ++timer;
    for (auto x : adj[node]){
        if (x.fi == p) continue;
        dfs_init(x.fi, node);
    }
    tout[node] = ++timer;
}
bool is_ancestor(int a, int b){
    return tin[a] <= tin[b] && tout[b] <= tout[a];
}
int LCA(int a, int b){
    if (is_ancestor(a, b)) return a;
    if (is_ancestor(b, a)) return b;
    for (int i=M - 1;i>=0;i--){
        if (!is_ancestor(up[a][i], b)){
            a = up[a][i];
        }
    }
    a = up[a][0];
    return a;
}

ll fpow(ll a, ll b){
    ll ret = 1;
    while (b){
        if (b & 1){
            ret = ret * a % MOD;
        }
        b >>= 1;
        a = a * a % MOD;
    }
    return ret;
}

ll dp[N][2]; // 0: start from 1
void dfs_dp(int node, int p, int dig){
    if (node != p){
        dp[node][0] = (dp[p][0] * 10LL % MOD + (ll)dig) % MOD;
        dp[node][1] = (dp[p][1] + ((ll)dig) * fpow(10, dep[node] - dep[1] - 1) % MOD) % MOD;
    }
    for (auto x : adj[node]){
        if (x.fi == p) continue;
        dfs_dp(x.fi, node, x.se);
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<n;i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].pb(mp(b, c));
        adj[b].pb(mp(a, c));
    }
    dfs_init(1, 1);
    dfs_dp(1, 1, 0);
    

    return 0;
}
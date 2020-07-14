#include <bits/stdc++.h>

#define pb push_back
#define el '\n'

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
const int N = 1e5 + 10;
const int M = 18;

int n, m;
vector<int> adl[N];
vector<int> nadl[N + N];
int q;

int tinn[N];

int tin[N + N], tout[N + N], timer;
int dp[N + N], bnode[N + N];

int up[N + N][M];

void dfs(int node, int p){
    tinn[node] = ++timer;
    for (auto x : adl[node]){
        if (x == p) continue;
        if (tinn[x]){
            if (tinn[x] < tinn[node]){
                bnode[node] = n + x;
            }
            continue;
        }
        dfs(x, node);
    }
    if (bnode[node] == node){
        for (auto x : adl[node]){
            if (x == p) continue;
            if (bnode[x] != x && bnode[x] != n + x){
                bnode[node] = bnode[x];
                break;
            } 
        }
    }
}
void dfsTree(int node, int p){
    tin[node] = ++timer;
    up[node][0] = p;
    for (int i=1;i<M;i++){
        up[node][i] = up[up[node][i - 1]][i - 1];
    }
    dp[node] = dp[p];
    if (node > n) dp[node]++;
    for (auto x : nadl[node]){
        if (x == p) continue;
        dfsTree(x, node);
    }
    tout[node] = ++timer;
}
void buildTree(){
    for (int i=1;i<=n;i++){
        for (int x : adl[i]){
            if (bnode[x] == bnode[i]) continue;
            nadl[bnode[i]].pb(bnode[x]);
        }
    }
    n = n;
    timer = 0;
    dfsTree(bnode[1], bnode[1]);
}
bool is_ancestor(int a, int b){
    return tin[a] <= tin[b] && tout[b] <= tout[a]; 
}
int LCA(int a, int b){
    if (is_ancestor(a, b)) return a;
    if (is_ancestor(b, a)) return b;
    for (int i=M - 1;i>=0;i--){
        if (!is_ancestor(up[a][i], b)) a = up[a][i];
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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i=1;i<=n;i++) bnode[i] = i;
    for (int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        adl[a].pb(b);
        adl[b].pb(a);
    }
    dfs(1, 1);
    buildTree();

    cin >> q;
    while (q--){
        int a, b;
        cin >> a >> b;
        a = bnode[a];
        b = bnode[b];

        int lca = LCA(a, b);
        ll pang = dp[a] + dp[b] - 2 * dp[lca];
        if (lca > n) pang++;
        cout << fpow(2LL, pang) << el;
    }
}
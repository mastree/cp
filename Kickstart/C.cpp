#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using ld = long double;

const int N = 5e5 + 10, M = 19;

int q;
int n, a, b;
vector<int> adj[N];

int dep[N];

int up[N][M];
ll dp1[N], dp2[N];

void dfs_init(int node, int p){
    if (node != p) dep[node] = dep[p] + 1;
    up[node][0] = p;
    for (int i=1;i<M;i++){
        up[node][i] = up[up[node][i - 1]][i - 1];
    }
    for (auto x : adj[node]){
        if (x == p) continue;
        dfs_init(x, node);
    }
}

int nth_ancestor(int node, int x){
    if (dep[node] < x) return -1;
    int cur = node;
    for (int i=M - 1;i>=0;i--){
        int temp = up[cur][i];
        if (dep[node] - dep[temp] > x) continue;
        cur = temp;
    }
    return cur;
}

void dfs1(int node, int p){
    for (auto x : adj[node]){
        if (x == p) continue;
        dfs1(x, node);
    }
    dp1[node] += 1LL;
    int anc = nth_ancestor(node, a);
    if (anc != -1) dp1[anc] += dp1[node];
}

void dfs2(int node, int p){
    for (auto x : adj[node]){
        if (x == p) continue;
        dfs2(x, node);
    }
    dp2[node] += 1LL;
    int anc = nth_ancestor(node, b);
    if (anc != -1) dp2[anc] += dp2[node];
}

void init(){
    fill(dp1, dp1 + n + 2, 0);
    fill(dp2, dp2 + n + 2, 0);
    for (int i=0;i<=n;i++){
        adj[i].clear();
    }
}

void solve(){
    init();
    cin >> n >> a >> b;
    for (int i=2;i<=n;i++){
        int a = i, b;
        cin >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs_init(1, 1);
    dfs1(1, 1);
    dfs2(1, 1);
    ld ans = 0, nn = (ld)n;
    for (int i=1;i<=n;i++){
        ld ca = ((ld)dp1[i]) / nn;
        ld cb = ((ld)dp2[i]) / nn;
        ld cac = ((ld)(n - dp1[i])) / nn;
        ld cbc = ((ld)(n - dp2[i])) / nn;

        ans += ca * cbc + cb * cac + ca * cb;
    }
    cout << ans << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(11);

    cin >> q;
    for (int cas=1;cas<=q;cas++){
        cout << "Case #" << cas << ": ";
        solve();
    }

    return 0;
}
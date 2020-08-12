#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e5 + 10;

int q;
int n, m;
int pep[N], hap[N];
vector<int> adj[N];

int sz[N];
pii dp[N]; // happy, sad

int par[N];

void dfs_size(int node, int p){
    par[node] = p;
    sz[node] = pep[node];
    for (auto x : adj[node]){
        if (x == p) continue;
        dfs_size(x, node);
        sz[node] += sz[x];
    }
}

void init(){
    for (int i=0;i<=n + 2;i++){
        adj[i].clear();
        sz[i] = 0;
        dp[i] = mp(0, 0);
    }
}

void solve(){
    cin >> n >> m;
    init();
    for (int i=1;i<=n;i++){
        cin >> pep[i];
    }
    for (int i=1;i<=n;i++){
        cin >> hap[i];
    }
    for (int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs_size(1, 1);
    bool ok = 1;
    for (int i=1;i<=n;i++){
        if (abs(hap[i]) > sz[i]){
            ok = 0;
            break;
        }
        if ((((int)abs(hap[i])) & 1) != (sz[i] & 1)){
            ok = 0;
            break;
        }
        if (sz[i] & 1){
            dp[i].fi = (sz[i] + 1) / 2 + ((int)abs(hap[i])) / 2;
            dp[i].se = sz[i] - dp[i].fi;
        } else{
            dp[i].fi = sz[i] / 2 + ((int)abs(hap[i])) / 2;
            dp[i].se = sz[i] - dp[i].fi; 
        }
        if (hap[i] < 0) swap(dp[i].fi, dp[i].se);
        assert(dp[i].fi - dp[i].se == hap[i]);
    }
    if (!ok){
        cout << "NO" << el;
        return;
    }
    for (int i=1;i<=n;i++){
        int tot = 0;
        for (auto x : adj[i]){
            if (x == par[i]) continue;
            tot += dp[x].fi;
        }
        if (tot > dp[i].fi){
            ok = 0;
            break;
        }
    }
    if (!ok){
        cout << "NO" << el;
        return;
    }
    cout << "YES" << el;
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
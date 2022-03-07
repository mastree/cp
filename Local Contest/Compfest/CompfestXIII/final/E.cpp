#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int N = 2e5 + 10;
const int MOD = 1e9 + 7;

int n, k;
ll ar[N];
vector<pii> adj[N];

bool vis[N];
int cpar[N];
int sz[N];

vector<int> cadj[N];

void dfsSubtree(int node, int p){
    sz[node] = 1;
    for (auto& x : adj[node]){
        if (x.fi == p || vis[x.fi]) continue;
        dfsSubtree(x.fi, node);
        sz[node] += sz[x.fi];
    }
}

int dfsCentroid(int node, int p, int size){
    for (auto& x : adj[node]){
        if (x.fi == p || vis[x.fi]) continue;
        if (sz[x.fi] + sz[x.fi] > size) return dfsCentroid(x.fi, node, size);
    }
    return node;
}

void decompose(int node, int p){
    dfsSubtree(node, p);
    int ctr = dfsCentroid(node, p, sz[node]);
    if (p == -1) p = ctr;
    else{
        cadj[p].pb(ctr);
    }
    cpar[ctr] = p;
    vis[ctr] = 1;
    for (auto& x : adj[ctr]){
        if (vis[x.fi]) continue;
        decompose(x.fi, ctr);
    }
}

struct DP {
    int dist;
    ll tot;
    int first;
    int fnode;
};

DP dp[N];
vector<int> ids;

void dfs_solve(int node, int p, int last = -1){
    if (node == p){
        dp[node] = {0, ar[node], -1};
    }
    ids.pb(node);
    int fst = dp[node].first;
    for (auto& x : adj[node]){
        if (x.fi == p || vis[x.fi]) continue;
        dp[x.fi].dist = dp[node].dist + (last != -1 && last != x.se);
        dp[x.fi].tot = (dp[node].tot + ar[x.fi]) % MOD;
        if (fst != -1){
            dp[x.fi].first = fst;
            dp[x.fi].fnode = dp[node].fnode;
        }
        else{
            dp[x.fi].first = x.se;
            dp[x.fi].fnode = x.fi;
        } 
        dfs_solve(x.fi, node, x.se);
    }
}

ll ans = 0;
pll pre[N][2]; // precompute, count

pll bit[N][2];

void update(int x, int id, pll val){
    while (x < N){
        bit[x][id].fi = (bit[x][id].fi + val.fi) % MOD;
        bit[x][id].se = (bit[x][id].se + val.se) % MOD;
        if (x == 0) x++;
        else{
            x += (x & (-x)); 
        }
    }
}
pll ask(int x, int id){
    pll ret = {0LL, 0LL};
    while (x >= 0){
        ret.fi = (ret.fi + bit[x][id].fi) % MOD;
        ret.se = (ret.se + bit[x][id].se) % MOD;
        if (x == 0) x--;
        else{
            x -= (x & (-x)); 
        }
    }
    return ret;
}

void dfs_centro(int node){
    dfs_solve(node, node);
    vis[node] = 1;

    cout << node << " => " << el;
    for (auto& x : ids){
        cout << x << " => " << dp[x].dist << " " << dp[x].tot << " " << dp[x].first << " " << dp[x].fnode << el;
    } cout << el;

    int lfnode = -1;
    vector<int> cand;
    for (auto& x : ids){
        if (dp[x].dist > k){
            continue;
        }
        ans = (ans + dp[x].tot) % MOD;
        if (dp[x].first == -1){
            continue;
        }
        if (lfnode != dp[x].fnode){
            for (auto& y : cand){
                update(dp[y].dist, dp[y].first, mp(dp[y].tot, 1LL));
            }
            cand.clear();
            pll temp = ask(0, 0);
            cout << temp.fi << " " << temp.se << ", ";
            temp = ask(0, 1);
            cout << temp.fi << " " << temp.se << el;
        }
        lfnode = dp[x].fnode;
        cand.pb(x);
        {
            pll temp = ask(k - dp[x].dist, dp[x].first);
            ans = (ans + (dp[x].tot * temp.se + temp.fi - dp[node].tot * temp.se) % MOD + MOD) % MOD;
        }
        {
            pll temp = ask(k - dp[x].dist - 1, (dp[x].first ^ 1));
            ans = (ans + (dp[x].tot * temp.se + temp.fi - dp[node].tot * temp.se) % MOD + MOD) % MOD;
        }
        cout << ans << el;
    }
    for (auto& y : cand){
        update(dp[y].dist, dp[y].first, mp(dp[y].tot, 1LL));
    }
    cand.clear();
    for (auto& x : ids){
        if (dp[x].dist > k){
            continue;
        }
        if (dp[x].first == -1){
            continue;
        }
        update(dp[x].dist, dp[x].first, mp(-dp[x].tot, -1LL));
    }

    cout << ans << el << el;

    // cout << node << " => " << el;
    // for (auto& x : ids){
    //     cout << x << " => " << dp[x].dist << " " << dp[x].tot << " " << dp[x].first << " " << dp[x].fnode << el;
    // } cout << el;
    // int mxk = 0;
    // for (auto& x : ids){
    //     if (dp[x].dist > k || dp[x].first == -1) continue;
    //     mxk = max(mxk, dp[x].dist);
    //     pre[dp[x].dist][dp[x].first].fi = (pre[dp[x].dist][dp[x].first].fi + dp[x].tot) % MOD;
    //     pre[dp[x].dist][dp[x].first].se++;
    // }
    // for (int i=1;i<=mxk;i++){
    //     for (int j=0;j<2;j++){
    //         pre[i][j].fi = (pre[i][j].fi + pre[i - 1][j].fi) % MOD;
    //         pre[i][j].se += pre[i - 1][j].se;
    //     }
    // }
    // for (int i=0;i<=mxk;i++){
    //     cout << i << " ";
    //     for (int j=0;j<2;j++){
    //         cout << pre[i][j].fi << ":" << pre[i][j].se << ' ';
    //     }
    //     cout << el;
    // }
    // cout << el;
    // for (auto& x : ids){
    //     if (dp[x].dist <= k){
    //         ans = (ans + dp[x].tot * 2) % MOD;
    //     }
    //     if (dp[x].dist > k || dp[x].first == -1) continue;
        
    //     for (int col=0;col<2;col++){
    //         int fdist = k - dp[x].dist - (col != dp[x].first);
    //         if (fdist >= 0){
    //             if (dp[x].dist <= fdist){
    //                 pre[fdist][dp[x].first].fi = (pre[fdist][dp[x].first].fi - dp[x].tot + MOD) % MOD;
    //                 pre[fdist][dp[x].first].se--;
    //             }
    //             if (pre[fdist][col].se > 0){
    //                 cout << "node: " << x << ", col: " << col << " => " << dp[x].tot << " " << pre[fdist][col].fi << " " << pre[fdist][col].se << el;
    //                 ans = (ans + (dp[x].tot * pre[fdist][col].se + pre[fdist][col].fi - dp[node].tot * pre[fdist][col].se) % MOD + MOD) % MOD;
    //             }
    //             if (dp[x].dist <= fdist){
    //                 pre[fdist][dp[x].first].fi = (pre[fdist][dp[x].first].fi + dp[x].tot + MOD) % MOD;
    //                 pre[fdist][dp[x].first].se++;
    //             }
    //         }
    //     }
    // }
    // cout << ans << el << el;
    // for (int i=0;i<=mxk;i++){
    //     for (int j=0;j<2;j++){
    //         pre[i][j] = mp(0LL, 0LL);
    //     }
    // }

    ids.clear();
    for (auto& x : cadj[node]){
        if (vis[x]) continue;
        dfs_centro(x);
    }
}

ll fpow(ll a, ll b){
    ll ret = 1;
    while (b){
        if (b & 1){
            ret = ret * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return ret;
}
ll inv(ll a){
    return fpow(a, MOD - 2);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    for (int i=1;i<n;i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].pb(mp(b, c));
        adj[b].pb(mp(a, c));
    }
    decompose(1, -1);
    int root;
    fill(vis, vis + n + 1, 0);
    for (int i=1;i<=n;i++){
        if (cpar[i] == i){
            root = i;
            break;
        }
    }
    dfs_centro(root);
    cout << (ans + MOD) % MOD << el;

    return 0;
}
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

const int N = 2e4 + 10;
const int INF = 1e9 + 10;
const int COL = 5;

int q;
int n, m, k;
vector<pii> adj[N]; // node, edge-id
vector<pii> edges; // dist, col

int dp[N][COL];
bool bisa(int cost){
    for (int i=0;i<=n;i++){
        for (int j=0;j<COL;j++){
            dp[i][j] = INF;
        }
    }
    dp[1][0] = 0;
    set<pair<int, pii>> setdah; // dist, node, color
    setdah.insert(mp(0, mp(1, 0)));
    while (!setdah.empty()){
        auto tp = *setdah.begin();
        setdah.erase(tp);
        int cur = tp.fi;
        int node = tp.se.fi;
        int col = tp.se.se;
        for (auto& x : adj[node]){
            int ncol = edges[x.se].se;
            int tam = edges[x.se].fi + (col != ncol ? cost : 0);
            if (tam > k) continue;
            if (dp[x.fi][ncol] > cur + tam){
                setdah.erase(mp(dp[x.fi][ncol], mp(x.fi, ncol)));
                dp[x.fi][ncol] = cur + tam;
                setdah.insert(mp(dp[x.fi][ncol], mp(x.fi, ncol)));
            }
        }
    }
    int mn = INF;
    for (int c=0;c<COL;c++){
        mn = min(mn, dp[n][c]);
    }
    return mn <= k;
}
void reset(){
    for (int i=1;i<=n;i++){
        adj[i].clear();
    }
    edges.clear();
}
void solve(){
    cin >> n >> m >> k;
    reset();
    for (int i=0;i<m;i++){
        int a, b;
        int w, col;
        char c;
        cin >> a >> b >> w >> c;
        col = c - 'a';
        edges.pb(mp(w, col));
        adj[a].pb(mp(b, i));
        adj[b].pb(mp(a, i));
    }
    int l = 1, r = INF;
    int best = -1;
    while (l <= r){
        int m = (l + r) / 2;
        if (bisa(m)){
            l = m + 1;
            best = m;
        } else{
            r = m - 1;
        }
    }
    if (best == -1){
        cout << "impossible" << el;
    } else if (best >= INF){
        cout << "relaxing" << el;
    } else{
        cout << best << el;
    }
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
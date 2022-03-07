#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e3 + 10;
const int INF = 1e9 + 10;

int q;

int x, y, n;
int m, u, s;
vector<int> posu, poss;
vector<vector<pii>> adj; 
vector<pii> info;

void init(){
    posu.clear();
    poss.clear();
    adj.clear();
    info.clear();
}
vector<int> dijkstra(int sz, int forbid = -1){
    vector<int> dp(n + 1, INF);
    set<pii> setdah;
    dp[0] = 0;
    setdah.insert(mp(0, 0));
    while (!setdah.empty()){
        auto temp = *setdah.begin();
        setdah.erase(temp);
        int node = temp.se;
        int cur = temp.fi;
        // cout << node << " " << cur << el;
        for (auto& x : adj[node]){
            int nnode = x.fi;
            int id = x.se;
            if (info[id].se < sz || nnode == forbid) continue;
            if (dp[nnode] > cur + info[id].fi){
                setdah.erase(mp(dp[nnode], nnode));
                dp[nnode] = cur + info[id].fi;
                setdah.insert(mp(dp[nnode], nnode));
            }
        }
    }
    return dp;
}
vector<int> stopping_node(const vector<int>& dp, int sz){
    vector<int> ret;
    for (int i=1;i<n;i++){
        if (dp[i] == INF) continue;
        for (auto& x : adj[i]){
            if (info[x.se].se < sz){
                ret.pb(i);
                break;
            }
        }
    }
    return ret;
}
void solve(){
    init();
    cin >> x >> y >> n;
    cin >> m >> u >> s;
    n++;
    adj.resize(n + 1, vector<pii>());
    for (int i=0;i<u;i++){
        int a;
        cin >> a;
        posu.pb(a);
    }
    for (int i=0;i<s;i++){
        int a;
        cin >> a;
        poss.pb(a);
    }
    info.emplace_back(0, 0);
    for (int i=1;i<=m;i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        info.pb(mp(c, d));
        adj[a].pb(mp(b, i));
        adj[b].pb(mp(a, i));
    }
    {
        int mxid = m;
        for (auto& x : poss){
            info.pb(mp(0, N));
            adj[0].pb(mp(x, ++mxid));
            adj[x].pb(mp(0, mxid));
        }
        for (auto& x : posu){
            info.pb(mp(0, N));
            adj[x].pb(mp(n, ++mxid));
            adj[n].pb(mp(x, mxid));
        }
    }
    auto da = dijkstra(x);
    auto sa = stopping_node(da, x);
    if (da[n] < INF){
        auto db = dijkstra(y);
        auto sb = stopping_node(db, y);
        if (db[n] < INF){
            cout << 2 << " " << da[n] + db[n] << el;
        } else{
            int ans = INF;
            for (auto& x : sb){
                ans = min(ans, da[n] + db[x]);
            }
            cout << 1 << " " << ans << el;
        }
    } else{
        int cnt = 0, dist = INF;
        for (auto& i : sa){
            auto db = dijkstra(y, i);
            if (db[n] < INF){
                cnt = 1;
                dist = min(dist, da[i] + db[n]);
            }
        }
        if (cnt == 0){
            cout << -1 << el;
            return;
        }
        cout << cnt << " " << dist << el;
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
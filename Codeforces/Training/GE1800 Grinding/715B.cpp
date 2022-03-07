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

const int N = 1e3 + 10;
const ll INF = 1e18;

int n, m, s, t;
ll l;
vector<pil> adj[N];
vector<pair<pii, ll>> edges;

ll dpt[N], dps[N];
unordered_map<int, ll> ans[N];

void dismiss(){
    cout << "NO" << el;
    exit(0);
}
void init(){
    fill(dpt, dpt + n + 2, INF);
    set<pli> setdah;
    dpt[t] = 0;
    setdah.insert(mp(0, t));
    while (!setdah.empty()){
        auto tp = *setdah.begin();
        setdah.erase(tp);
        int node = tp.se;
        ll cur = tp.fi;

        for (auto x : adj[node]){
            ll cost = max(max(x.se, 1LL), ans[node][x.fi]);
            if (dpt[x.fi] > cur + cost){
                setdah.erase(mp(dpt[x.fi], x.fi));
                dpt[x.fi] = cur + cost;
                setdah.insert(mp(dpt[x.fi], x.fi));
            }
        }
    }
}
void solve(){
    fill(dps, dps + n + 2, INF);
    set<pli> setdah;
    dps[s] = 0;
    setdah.insert(mp(0, s));
    while (!setdah.empty()){
        auto tp = *setdah.begin();
        setdah.erase(tp);
        int node = tp.se;
        ll cur = tp.fi;
        
        for (auto x : adj[node]){
            ll cost = x.se;
            if (!cost){
                if (ans[node][x.fi]) continue;
                cost = max(1LL, l - cur - dpt[x.fi]);
                ans[x.fi][node] = ans[node][x.fi] = cost;
            }
            if (dps[x.fi] > cur + cost){
                setdah.erase(mp(dps[x.fi], x.fi));
                dps[x.fi] = cur + cost;
                setdah.insert(mp(dps[x.fi], x.fi));
            }
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> l >> s >> t;
    for (int i=1;i<=m;i++){
        int a, b;
        ll w;
        cin >> a >> b >> w;
        adj[a].pb(mp(b, w));
        adj[b].pb(mp(a, w));
        edges.pb(mp(mp(a, b), w));
    }
    init();
    solve();
    init();
    if (dpt[s] != l) dismiss();
    cout << "YES" << el;
    for (auto x : edges){
        if (x.se) cout << x.fi.fi << " " << x.fi.se << " " << x.se << el;
        else cout << x.fi.fi << " " << x.fi.se << " " << ans[x.fi.fi][x.fi.se] << el;
    }

    return 0;
}
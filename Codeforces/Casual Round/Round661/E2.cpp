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
using pll = pair<ll, ll>;

const int N = 1e5 + 10;
const ll INF = 1e18;

int q;
int n;
ll s;
vector<pair<int, pli>> adj[N];

ll sz[N];
ll cost[N];
int fac[N];
ll tot;

void init(){
    for (int i=1;i<=n;i++){
        adj[i].clear();
        sz[i] = 0;
        cost[i] = 0;
    }
    tot = 0;
}

void dfs_size(int node, int p, ll cc, int cc2){
    bool isl = 1;
    cost[node] = cc;
    fac[node] = cc2;
    sz[node] = 0;
    for (auto x : adj[node]){
        if (x.fi == p) continue;
        dfs_size(x.fi, node, x.se.fi, x.se.se);
        sz[node] += sz[x.fi];
        isl = 0;
    }
    if (isl){
        sz[node] = 1;
    }
}

void solve(){
    cin >> n >> s;
    init();
    for (int i=1;i<n;i++){
        int a, b;
        ll w, cc;
        cin >> a >> b >> w >> cc;
        adj[a].pb(mp(b, mp(w, cc)));
        adj[b].pb(mp(a, mp(w, cc)));
    }
    dfs_size(1, 1, 0, 0);
    for (int i=2;i<=n;i++){
        tot += cost[i] * sz[i];
    }
    tot -= s;

    set<pli> setdah[2];
    setdah[0].insert(mp(0, 0));
    setdah[1].insert(mp(0, 0));
    for (int i=2;i<=n;i++){
        ll temp = (cost[i] + 1LL) / 2LL;
        setdah[fac[i] - 1].insert(mp(temp * sz[i], i));
    }
    vector<ll> vec[2];
    ll move = INF;
    for (int i=0;i<2;i++){
        vec[i].pb(0);
        while (1){
            auto tp = *setdah[i].rbegin();
            vec[i].pb(tp.fi);
            if (tp.fi == 0) break;
            cost[tp.se] /= 2LL;
            setdah[i].erase(tp);
            ll temp = (cost[tp.se] + 1LL) / 2LL;
            setdah[i].insert(mp(temp * sz[tp.se], tp.se));
        }
    }
    int len0 = vec[0].size();
    int len1 = vec[1].size();
    for (int i=1;i<len0;i++){
        vec[0][i] += vec[0][i - 1];
    }
    for (int i=1;i<len1;i++){
        vec[1][i] += vec[1][i - 1];
    }
    int pos = 0;
    while (pos < len1 - 1 && vec[1][pos] < tot) pos++;

    for (int i=0;i<len0;i++){
        while (pos > 0 && vec[1][pos - 1] + vec[0][i] >= tot) pos--;
        if (vec[1][pos] + vec[0][i] >= tot) move = min(move, (ll)(pos * 2 + i));
    }
    cout << move << el;
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
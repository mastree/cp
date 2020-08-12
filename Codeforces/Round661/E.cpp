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

const int N = 1e5 + 10;

int q;
int n;
ll s;
vector<pil> adj[N];

ll sz[N];
ll cost[N];
ll tot;

void init(){
    for (int i=1;i<=n;i++){
        adj[i].clear();
        sz[i] = 0;
        cost[i] = 0;
    }
    tot = 0;
}

void dfs_size(int node, int p, ll cc){
    bool isl = 1;
    cost[node] = cc;
    sz[node] = 0;
    for (auto x : adj[node]){
        if (x.fi == p) continue;
        dfs_size(x.fi, node, x.se);
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
        ll w;
        cin >> a >> b >> w;
        adj[a].pb(mp(b, w));
        adj[b].pb(mp(a, w));
    }
    dfs_size(1, 1, 0);
    for (int i=2;i<=n;i++){
        tot += cost[i] * sz[i];
    }

    set<pli> setdah;
    for (int i=2;i<=n;i++){
        ll temp = (cost[i] + 1LL) / 2;
        setdah.insert(mp(temp * sz[i], i));
    }

    int move = 0;
    while (tot > s){
        move++;
        auto tp = *setdah.rbegin();
        tot -= tp.fi;
        cost[tp.se] /= 2;
        setdah.erase(tp);
        ll temp = (cost[tp.se] + 1LL) / 2;
        setdah.insert(mp(temp * sz[tp.se], tp.se));
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
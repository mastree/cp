#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const ll MOD = 1e9 + 9, MOD2 = 1e9 + 7;
const ll p = 31, p2 = 131;
const int N = 1e5 + 10;

int q;
int n;
vector<int> diam[2];
vector<int> adj[2][N];

ll ppow[N];
ll ppow2[N];

void init(){
    for (int i=0;i<2;i++){
        diam[i].clear();
        for (int j=1;j<=n;j++){
            adj[i][j].clear();
        }
    }
}

pii furthest(int id, int node, int p, int dist){
    pii ret = mp(node, dist);
    for (auto x : adj[id][node]){
        if (x == p) continue;
        pii temp = furthest(id, x, node, dist + 1);
        if (temp.se > ret.se) ret = temp;
    }
    return ret;
}

bool dfs_path(int id, int node, int p, int target){
    bool ret = 0;
    if (node == target){
        ret = 1;
    }
    for (auto x : adj[id][node]){
        if (x == p) continue;
        ret |= dfs_path(id, x, node, target);
    }
    if (ret){
        diam[id].pb(node);
    }
    return ret;
}

void find_path(int id){
    pii sa = furthest(id, 1, 1, 0);
    pii sb = furthest(id, sa.fi, sa.fi, 0);
    dfs_path(id, sa.fi, sa.fi, sb.fi);
}

// size, hash
pair<int, ll> get_hash(int id, int node, int p){
    vector<pair<int, ll>> ch;
    for (auto x : adj[id][node]){
        if (x == p) continue;
        ch.pb(get_hash(id, x, node));
    }
    sort(ch.begin(), ch.end());
    int sz = 1;
    ll ret1 = 1, ret2 = 1;
    for (auto x : ch){
        ll x1 = (x.se & ((1LL << 31) - 1LL)), x2 = x.se - x1;
        ret1 = (ret1 + x1 * ppow[sz] % MOD) % MOD;
        ret2 = (ret2 + x2 * ppow2[sz] % MOD2) % MOD2;
        sz += x.fi;
    }
    ret1 = (ret1 + 2LL * ppow[sz] % MOD) % MOD;
    ret2 = (ret2 + 2LL * ppow2[sz] % MOD2) % MOD2;
    sz++;
    return mp(sz, ret1 + (ret2 << 31));
}

void solve(){
    cin >> n;
    init();
    for (int i=0;i<2;i++){
        for (int j=1;j<n;j++){
            int a, b;
            cin >> a >> b;
            adj[i][a].pb(b);
            adj[i][b].pb(a);
        }
    }
    find_path(0);
    find_path(1);
    int len[2] = {(int)diam[0].size(), (int)diam[1].size()};
    if (len[0] != len[1]){
        cout << "NO" << el;
        return;
    }
    if (len[0] & 1){
        auto hh1 = get_hash(0, diam[0][len[0] / 2], diam[0][len[0] / 2]);
        auto hh2 = get_hash(1, diam[1][len[1] / 2], diam[1][len[1] / 2]);

        if (hh1 == hh2) cout << "YES" << el;
        else cout << "NO" << el;
    } else{
        auto hh1 = get_hash(0, diam[0][len[0] / 2], diam[0][len[0] / 2]);
        auto hh2 = get_hash(1, diam[1][len[1] / 2], diam[1][len[1] / 2]);
        auto hh3 = get_hash(0, diam[0][(len[0] - 1) / 2], diam[0][(len[0] - 1) / 2]);

        if (hh1 == hh2 || hh3 == hh2) cout << "YES" << el;
        else cout << "NO" << el;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ppow[0] = 1;
    ppow2[0] = 1;
    for (int i=1;i<N;i++){
        ppow[i] = ppow[i - 1] * p % MOD;
        ppow2[i] = ppow2[i - 1] * p2 % MOD2;
    }

    cin >> q;
    while (q--){
        solve();
    }

    return 0;
}
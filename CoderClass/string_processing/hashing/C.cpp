#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const ll MOD = 1e9 + 7, MOD2 = 1e9 + 9;
const ll p = 31, p2 = 131;
const int N = 2e5 + 10;

ll ppow[N];
ll ppow2[N];

int n, m;
vector<int> adj[N];

map<ll, ll> cekod; // odd sized and even sized
map<pair<ll, ll>, ll> cekev;

int par[N], sz[N], edges[N];
int find(int a){
    if (par[a] == a) return a;
    return par[a] = find(par[a]);
}
void make(int a, int b){
    a = find(a);
    b = find(b);
    if (a == b){
        edges[a]++;
        return;
    }
    if (sz[a] < sz[b]) swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
    edges[a] += edges[b] + 1;
}
void init(){
    for (int i=1;i<=n;i++){
        par[i] = i;
        sz[i] = 1;
    }
    ppow[0] = ppow2[0] = 1;
    for (int i=1;i<N;i++){
        ppow[i] = ppow[i - 1] * p % MOD;
        ppow2[i] = ppow2[i - 1] * p2 % MOD2;
    }
}

vector<int> path;
void clear_process(){
    path.clear();
}

pii furthest(int node, int p, int dist){
    pii ret = mp(node, dist);
    for (auto x : adj[node]){
        if (x == p) continue;
        pii temp = furthest(x, node, dist + 1);
        if (temp.se > ret.se) ret = temp;
    }
    return ret;
}
bool get_path(int node, int p, int target){
    bool ret = 0;
    if (node == target) ret = 1;
    for (auto x : adj[node]){
        if (x == p) continue;
        ret |= get_path(x, node, target);
    }
    if (ret){
        path.pb(node);
    }
    return ret;
}
// size, hash
pair<int, ll> get_hash(int node, int p){
    vector<pair<int, ll>> vec;
    for (auto x : adj[node]){
        if (x == p) continue;
        vec.pb(get_hash(x, node));
    }
    sort(vec.begin(), vec.end());
    ll ret = 1, ret2 = 1;
    int sz = 1;
    for (auto y : vec){
        ll x = (y.se & ((1LL << 31) - 1)), x2 = y.se - x;
        ret = (ret + x * ppow[sz] % MOD) % MOD;
        ret2 = (ret2 + x2 * ppow2[sz] % MOD2) % MOD2;
        sz += y.fi;
    }
    ret = (ret + 2LL * ppow[sz] % MOD) % MOD;
    ret2 = (ret2 + 2LL * ppow2[sz] % MOD2) % MOD2;
    sz++;
    return mp(sz, ret + (ret2 << 31));
}

void process(int id){
    clear_process();
    pii na = furthest(id, id, 0);
    pii nb = furthest(na.fi, na.fi, 0);
    get_path(na.fi, na.fi, nb.fi);

    int len = path.size();
    if (len & 1){
        auto hh = get_hash(path[len / 2], path[len / 2]);
        cekod[hh.se]++;
    } else{
        auto hh1 = get_hash(path[len / 2], path[len / 2]);
        auto hh2 = get_hash(path[(len - 1) / 2], path[(len - 1) / 2]);
        if (hh1 > hh2) swap(hh1, hh2);
        cekev[mp(hh1.se, hh2.se)]++;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    init();
    for (int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
        make(a, b);
    }
    for (int i=1;i<=n;i++){
        if (par[i] == i && sz[i] == edges[i] + 1){
            process(i);
        }
    }
    ll ans = 0;
    for (auto x : cekod){
        ans += x.se * (x.se - 1LL) / 2LL;
    }
    for (auto x : cekev){
        ans += x.se * (x.se - 1LL) / 2LL;
    }
    cout << ans << el;

    return 0;
}
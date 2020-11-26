#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e5 + 10;
const ll MOD = 1e9 + 7;

int q;
int n, m;
vector<int> adj[N];
vector<ll> fac;

ll sz[N];
vector<ll> hub;

void init(){
    for (int i=1;i<=n;i++){
        adj[i].clear();
    }
    fac.clear();
    hub.clear();
    fill(sz, sz + n + 2, 0);
}
void dfs_init(int node, int p){
    sz[node] = 1;
    for (auto x : adj[node]){
        if (x == p) continue;
        dfs_init(x, node);
        sz[node] += sz[x];
    }
}
void dfs_solve(int node, int p){
    if (node != p){
        ll atas = n - sz[node];
        hub.pb(atas * sz[node]);
    }
    for (auto x : adj[node]){
        if (x == p) continue;
        dfs_solve(x, node);
    }
}

void solve(){
    cin >> n;
    init();
    for (int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    cin >> m;
    for (int i=1;i<=m;i++){
        ll a;
        cin >> a;
        fac.pb(a);
    }
    if (m < n){
        while (m < n - 1){
            fac.pb(1);
            m++;
        }
        sort(fac.begin(), fac.end());
    } else{
        sort(fac.begin(), fac.end());
        ll cum = 1;
        while (m > n - 1){
            cum = cum * fac.back() % MOD;
            fac.pop_back();
            m--;
        }
        fac.back() = fac.back() * cum % MOD;
    }
    dfs_init(1, 1);
    dfs_solve(1, 1);
    sort(hub.begin(), hub.end());
    ll ans = 0;
    for (int i=0;i<n - 1;i++){
        hub[i] %= MOD;
        ans = (ans + fac[i] * hub[i]) % MOD;
    }
    cout << ans << el;
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
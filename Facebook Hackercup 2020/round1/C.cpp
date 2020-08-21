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

const int N = 1e6 + 100;

int q;
int n, k;
bool safe[N];
vector<int> adj[N];
int p[N];
ll pr[4];

int dp[N], sz[N];
int dpmx[N], dpmn[N];
int lazy[N];

void init(){
    fill(dp, dp + n + 2, 0);
    fill(sz, sz + n + 2, 0);
    fill(dpmx, dpmx + n + 2, 0);
    fill(dpmn, dpmn + n + 2, 0);
    fill(lazy, lazy + n + 2, 0);
    for (int i=1;i<=n;i++){
        adj[i].clear();
    }
    for (int i=k + 2;i<=n;i++){
        p[i] = (1LL * pr[1] * p[i - 2] + 1LL * pr[2] * p[i - 1] + (ll)pr[3]) % ((ll)(i - 1)) + 1;
    }

    for (int i=2;i<=n;i++){
        adj[i].pb(p[i]);
        adj[p[i]].pb(i);
    }
    int cnt = 0;
    for (int i=1;i<=n;i++){
        cnt += adj[i].size();
    }
}
void dfs_dp(int node){
    if (safe[node]) dp[node] = 1;
    sz[node] = 1;
    if (node != 1) assert(p[node] != 0 && p[node] < node);
    for (auto x : adj[node]){
        if (x == p[node]) continue;
        dfs_dp(x);
        if (safe[node] && safe[x]) dp[node] += dp[x];
        sz[node] += sz[x];
    }
}
void dfs_mx(int node, int mx){
    if (dp[node] == mx){
        dpmx[node] = 1;
    } else dpmx[node] = 0;
    for (auto x : adj[node]){
        if (x == p[node]) continue;
        dfs_mx(x, mx);
        dpmx[node] += dpmx[x];
    }
}
void dfs_mn(int node, int mn){
    if (!safe[p[node]] && dp[node] == mn){
        dpmn[node] = 1;
    } else dpmn[node] = 0;
    for (auto x : adj[node]){
        if (x == p[node]) continue;
        dfs_mn(x, mn);
        dpmn[node] += dpmn[x];
    }
}
void push_down(int node){
    lazy[node] = dp[node];
    for (auto x : adj[node]){
        if (x == p[node]){
            if (safe[node]) lazy[node] = max(lazy[node], lazy[x]);
            continue;
        }
        push_down(x);
    }
}
ll dfs_solve(int node, ll mx, ll mn, ll remx, ll remn){
    if (lazy[p[node]] == mx && !safe[node]) remx++;
    if (lazy[p[node]] == mn && !safe[node]) remn++;
    ll ret = 0;
    if (safe[node] != safe[p[node]] || !safe[node]){
        ret += 1LL * remx * mx * dpmn[node] * mn;
        if (mx != mn) ret += 1LL * remn * mn * dpmx[node] * mx;
    }

    for (auto x : adj[node]){
        if (x == p[node]) continue;
        remx += dpmx[x];
        remn += dpmn[x];
    }
    for (auto x : adj[node]){
        if (x == p[node]) continue;
        ret += dfs_solve(x, mx, mn, remx - dpmx[x], remn - dpmn[x]);
    }
    return ret;
}
string s;
void solve(){
    cin >> n >> k;
    cin >> s;
    for (int i=1;i<=n;i++){
        safe[i] = (s[i - 1] == '*');
    }
    safe[0] = !safe[1];
    for (int i=2;i<=k + 1;i++){
        cin >> p[i];
    }
    for (int i=1;i<=3;i++){
        cin >> pr[i];
    }
    init();
    dfs_dp(1);
    vector<pii> v;
    for (int i=1;i<=n;i++){
        if (safe[i] && !safe[p[i]]){
            v.pb(mp(dp[i], i));
        }
    }
    sort(v.begin(), v.end());
    if (v.size() <= 1){
        ll ans = 0;
        ll cnt = 0;
        ll none = 0;
        if (v.size()) ans = 1LL * v[0].fi * (v[0].fi - 1) / 2LL;
        for (int i=2;i<=n;i++){
            if (safe[i] && safe[i] == safe[p[i]]){
                cnt += 1LL * dp[i] * (v[0].fi - dp[i]);
            }
        }
        for (int i=2;i<=n;i++){
            if (safe[i] != safe[p[i]] || !safe[i]){
                cnt += 1LL * sz[i] * (n - sz[i]);
            }
        }
        cout << ans << " " << cnt << el;
        return;
    } 
    ll ans = 0;
    ll cnt = 0;
    ll mx = v.back().fi;
    v.pop_back();

    ll mn = v.back().fi;
    vector<ll> hit;
    for (auto x : v){
        hit.pb(x.fi);
    }
    hit.back() += mx;
    for (auto x : hit){
        ans += x * (x - 1LL) / 2LL;
    }
    dfs_mx(1, mx);
    dfs_mn(1, mn);
    push_down(1);

    cnt = dfs_solve(1, mx, mn, 0, 0);
    cout << ans << " " << cnt << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("quarantine_input.txt", "r", stdin);
    freopen("C.out", "w", stdout);

    cin >> q;
    for (int i=1;i<=q;i++){
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}
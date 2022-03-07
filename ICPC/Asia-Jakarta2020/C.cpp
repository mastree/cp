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
using pll = pair<ll, ll>;

const int N = 1e5 + 10;

int n;
vector<pil> adj[N];
pll dp[N]; // naik, nope

void dfs(int node, int p){
    dp[node] = mp(0, 0);
    vector<pll> vec;
    ll base = 0;
    for (auto& x : adj[node]){
        if (x.fi == p) continue;
        dfs(x.fi, node);
        vec.pb(mp(dp[x.fi].fi + x.se, dp[x.fi].se));
        base += dp[x.fi].se;
    }
    if (vec.empty()) return;
    vector<ll> d, pre;
    for (auto& x : vec){
        d.pb(x.fi - x.se);
    }
    sort(d.begin(), d.end(), greater<ll>());
    int len = d.size();
    pre.resize(len + 1, 0);
    for (int i=1;i<=len;i++) pre[i] = pre[i - 1] + d[i - 1];
    // naik
    for (int i=1;i<=len;i+=2){
        dp[node].fi = max(dp[node].fi, base + pre[i]);
    }
    // nope
    for (int i=0;i<=len;i+=2){
        dp[node].se = max(dp[node].se, base + pre[i]);
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<n;i++){
        int a, b;
        ll c;
        cin >> a >> b >> c;
        adj[a].pb(mp(b, c));
        adj[b].pb(mp(a, c));
    }
    dfs(1, 1);
    ll ans = dp[1].se;
    if (adj[1].size() <= 1) ans = max(ans, dp[1].fi);
    cout << ans << el;

    return 0;
}
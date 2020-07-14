#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
// #define MOD 1000000007
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'

using namespace std;

const int N = 2e5 + 10;
const ll MOD = 1e9 + 7;

int n;
vector <int> adl[N];
pair<ll, ll> dp[N]; // chance, count
pair<ll, ll> prop[N];
ll ans[N];

ll perm[N];

ll fpow(ll a, ll b){
    if (b == 0) return 1;
    ll temp = fpow(a, b / 2);
    temp = temp * temp % MOD;
    if (b & 1) temp = temp * a % MOD;
    return temp;
}

ll inv(ll a){
    return fpow(a, MOD - 2);
}

void dfs1(int node, int p){
    dp[node] = mp(1, 1);

    vector <ll> v;
    ll tot = 0;
    for (auto x : adl[node]){
        if (x == p) continue;
        dfs1(x, node);
        dp[node].fi = dp[node].fi * dp[x].fi % MOD;
        dp[node].se += dp[x].se;
        v.pb(dp[x].se);
        tot += dp[x].se;
    }
    ll temp = perm[tot];
    for (auto x : v){
        temp = temp * inv(perm[x]) % MOD;
    }
    dp[node].fi = dp[node].fi * temp % MOD;
}

void dfs(int node, int p){
    ans[node] = 1;
    vector <ll> v;
    ll tot = 0;

    if (node != p){
        prop[p] = mp(ans[p] * inv(dp[node].fi) % MOD , (n - dp[node].se) % MOD);
        prop[p].fi = ((prop[p].fi * inv(perm[n - 1]) % MOD) * perm[n - 1 - dp[node].se] % MOD) * perm[dp[node].se] % MOD;
    } else{
        prop[node].fi = 1;
        prop[node].se = n - dp[node].se + 1LL;
    }
    for (auto x : adl[node]){
        if (x == p){
            ans[node] = ans[node] * prop[x].fi % MOD;
            tot += prop[x].se;
            v.pb(prop[x].se);
        } else{
            ans[node] = ans[node] * dp[x].fi % MOD;
            tot += dp[x].se;
            v.pb(dp[x].se);
        }
    }
    ll temp = perm[tot];
    for (auto x : v){
        temp = temp * inv(perm[x]) % MOD;
    }
    ans[node] = ans[node] * temp % MOD;

    for (auto x : adl[node]){
        if (x != p) dfs(x, node);
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adl[a].pb(b);
        adl[b].pb(a);
    }

    perm[0] = 1;
    for (ll i=1;i<=n;i++){
        perm[i] = perm[i - 1] * i % MOD;
    }

    dfs1(1, 1);
    dfs(1, 1);

    for (int i=1;i<=n;i++){
        cout << ans[i] << el;
    }

    return 0;
}
#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const ll MOD = 1e9 + 7;
const int N = 30000;

ll n, fmark;
ll fac[N];

ll fpow(ll a, ll b){
    ll ret = 1;
    while (b){
        if (b & 1){
            ret = ret * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return ret;
}
ll inv(ll a){
    return fpow(a, MOD - 2);
}
ll comb(ll a, ll b){
    return fac[a] * inv(fac[a - b] * fac[b] % MOD) % MOD;
}
ll calc(ll n, ll tot, ll mx){ // stars and bars
    ll ret = 0;

    for (ll i=0;i<=n;i++){
        ll sisa = tot - (mx + 1) * i;
        if (sisa < 0) break;
        ll cur = comb(n, i);

        cur = cur * comb(n + sisa - 1, n - 1) % MOD;
        if (i & 1) ret = (ret - cur + MOD) % MOD;
        else ret = (ret + cur) % MOD;
    }
    return ret;
}


void solve(){
    ll ans = 0;
    for (ll i=0;i<=fmark;i++){
        ll tot = i * n - i;
        ll cur = n;

        cur = cur * calc(n - 1, tot, fmark) % MOD;
        ans = (ans + cur) % MOD;
    }
    cout << ans << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    fac[0] = 1;
    for (ll i=1;i<N;i++){
        fac[i] = fac[i - 1] * i % MOD;
    }

    while (cin >> n){
        cin >> fmark;
        if (n == 0 && fmark == 0) break;
        solve();
    }

    return 0;
}
#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int BIT = 20;
const int MASK = (1 << BIT);
const int MOD = 1e9 + 7;

int n;
ll s;
ll ar[BIT];

ll fpow(ll a, ll b){
    ll ret = 1;
    while (b){
        if (b & 1){
            ret = ret * a % MOD;
        }
        b >>= 1;
        a = a * a % MOD;
    }
    return ret;
}
ll fac[BIT + 1], rfac[BIT + 1];
ll comb(ll n, ll k){
    ll ret = 1;
    for (ll i=0;i<k;i++){
        ret = ret * ((n - i) % MOD) % MOD;
    }
    ret = ret * rfac[k] % MOD;
    return ret;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;
    for (int i=0;i<n;i++){
        cin >> ar[i];
    }
    fac[0] = 1;
    rfac[0] = 1;
    for (int i=1;i<=BIT;i++){
        fac[i] = fac[i - 1] * i % MOD;
        rfac[i] = fpow(fac[i], MOD - 2);
    }
    ll ans = 0;
    for (int mask=0;mask<(1 << n);mask++){
        ll nn = s;
        int bcnt = __builtin_popcount(mask);
        for (int i=0;i<n;i++){
            if (mask & (1 << i)){
                nn -= ar[i] + 1;
            }
        }
        if (nn < 0) continue;
        if (bcnt & 1){
            ans = (ans - comb(nn + n - 1, 1LL * (n - 1)) + MOD) % MOD;
        } else{
            ans = (ans + comb(nn + n - 1, 1LL * (n - 1))) % MOD;
        }
    }
    cout << ans << el;

    return 0;
}
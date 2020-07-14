#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'

using namespace std;

const int N = 2e6 + 10;
const ll MOD = 1e9 + 7;

ll n, k;
string s;
ll fac[N];

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
ll inv(ll a){
    return fpow(a, MOD - 2);
}
ll comb(ll n, ll k){
    return fac[n] * inv(fac[n - k] * fac[k] % MOD) % MOD;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    fac[0] = 1;
    for (ll i=1;i<N;i++){
        fac[i] = fac[i - 1] * i % MOD;
    }

    cin >> k;
    cin >> s;
    n = (ll) s.length();
    s = "*" + s;
    ll ans = 0;
    for (ll i=0;i<=k;i++){
        ll temp = (fpow(26, i) * fpow(25, k - i) % MOD) * comb(n + (k - i) - 1, (k - i)) % MOD;
        ans = (ans + temp) % MOD;
    }
    cout << ans << el;

    return 0;
}
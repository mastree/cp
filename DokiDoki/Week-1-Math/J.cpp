#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 4e5 + 10;
const ll MOD = 1e9 + 7;

ll n, m;
ll last;

ll ans = 0;

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

ll calc(ll n, ll m){
    if (n == 0){
        return (m > 1);
    } 
    if (m == 0){
        return ((n & 1) == 1);
    }
    ll ret = comb(n + m - 1, m - 1);
    return (ret + (comb(n + m - 1, n - 1) - calc(n - 1, m) + MOD)) % MOD;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    fac[0] = 1;
    for (ll i=1;i<N;i++){
        fac[i] = fac[i - 1] * i % MOD;
    }

    cin >> n >> m >> last;
    ans = calc(n, m);
    if (last == 1) ans = (comb(n + m, n) - ans + MOD) % MOD;
    cout << ans << el; 

    return 0;
}
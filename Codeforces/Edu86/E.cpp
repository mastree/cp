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

const ll N = 2e5 + 10;
const ll MOD = 998244353;

ll n, k;
ll fac[2 * N];
ll der[2 * N];

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

ll comb(ll a, ll b){
    return fac[a] * inv(fac[a - b] * fac[b] % MOD) % MOD;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    fac[0] = 1;
    for (ll i=1;i<2 * N;i++){
        fac[i] = fac[i - 1] * i % MOD;
    }
    der[0] = 1;
    der[1] = 0;
    der[2] = 1;
    for (ll i=3;i<2 * N;i++){
        der[i] = (der[i - 1] + der[i - 2]) * (i - 1) % MOD;
    }
    if (k == 0){
        cout << fac[n] << el;
        return 0;
    } else if (k >= n){
        cout << 0 << el;
        return 0;
    }
    ll choose = n - k;
    ll ans = 2LL * comb(n, choose) % MOD;
    ll dist = 0;
    for (ll i=0;i<choose;i++){
        if (i & 1){
            dist = (dist - comb(choose, choose - i) * fpow(choose - i, n) % MOD + MOD) % MOD;
        } else{
            dist = (dist + comb(choose, choose - i) * fpow(choose - i, n) % MOD) % MOD;
        }
    }
    cout << ans * dist % MOD << el;

    return 0;
}
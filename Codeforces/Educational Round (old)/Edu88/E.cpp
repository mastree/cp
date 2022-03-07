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

const ll MOD = 998244353;
const int N = 5e5 + 10;

ll n, k;
ll fac[N + N];

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
    for (ll i=1;i<=n;i++){
        fac[i] = fac[i - 1] * i % MOD;
    }
    ll ans = 0;
    for (ll i=1;i<=n;i++){
        ll choice = n / i;
        if (choice < k) break;
        ll temp = comb(choice - 1, k - 1);
        ans = (ans + temp) % MOD;
    }
    cout << ans << el;

    return 0;
}
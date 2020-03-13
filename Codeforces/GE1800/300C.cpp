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

const ll MOD = 1e9 + 7;
const int N = 1e6 + 10;

ll a, b, n;
ll ans;
ll per[N];

bool gud(ll x){
    while (x > 0){
        if (x % 10 != a && x % 10 != b) return 0;
        x /= 10;
    }
    return 1;
}

ll fpow(ll a, ll b){
    if (b == 0) return 1;
    ll tm = fpow(a, b/2);
    tm = (tm * tm) % MOD;
    if (b & 1) tm = tm * a % MOD;
    return tm;
}

ll comb(ll n, ll k){
    ll res = per[n];
    res = (res * fpow(per[k], MOD - 2) % MOD) * fpow(per[n - k], MOD - 2) % MOD;
    return res;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b >> n;
    per[0] = 1;

    for (ll i=1;i<=n;i++){
        per[i] = (per[i-1] * i) % MOD;
    }
    for (ll i=0;i<=n;i++){
        ll tot = a * i + b * (n - i);
        if (gud(tot)){
            ans = (ans + comb(n, i)) % MOD;
        }
    }
    cout << ans << el;

    return 0;
}
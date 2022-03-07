#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;

ll n, s;

ll fpow(ll a, ll b){
    ll ret = 1;
    while (b){
        if (b & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ret;
}
ll inv(ll a){
    return fpow(a, MOD - 2);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;
    n %= MOD;
    s %= MOD;
    ll a = n, b = s * n;
    ll ans = (((a + b) % MOD) * ((b - a + 1 + MOD) % MOD) % MOD) * inv(2) % MOD;
    cout << ans << el;

    return 0;
}
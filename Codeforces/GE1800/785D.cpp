#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e5 + 10;
const ll MOD = 1e9 + 7;

string s;
ll fac[2 * N];

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
ll comb(ll a, ll b){
    return fac[a] * inv(fac[a - b] * fac[b] % MOD) % MOD;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    fac[0] = 1;
    for (ll i=1;i<2 * N;i++){
        fac[i] = fac[i - 1] * i % MOD;
    }

    cin >> s;
    ll ans = 0;

    ll le = 0, ri = 0;
    for (auto x : s) if (x == ')') ri++;
    for (auto x : s){
        if (x == '('){
            le++;
            ans = (ans + comb(le + ri, ri) - (le > 0 ? comb(le + ri - 1, ri) : 0) + MOD) % MOD;
        } else ri--;
    }
    cout << ans << el;

    return 0;
}
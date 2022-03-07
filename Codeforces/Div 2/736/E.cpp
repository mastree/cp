#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 3e6 + 10;
const int MOD = 1e9 + 7;

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

int n, q;
ll fac[N], rfac[N];

ll comb(int a, int b){
    if (b > a) return 0;
    return (fac[a] * rfac[a - b] % MOD) * rfac[b] % MOD;
}

void solve(){
    ll ans = 0;
    int x;
    cin >> x;
    for (int i=(x + 2) / 3;i<=n;i++){
        ans = (ans + fac[i * 3] * rfac[i * 3 - x]) % MOD;
    }
    cout << ans * rfac[x] % MOD << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    fac[0] = 1;
    rfac[0] = 1;
    for (int i=1;i<N;i++){
        fac[i] = fac[i - 1] * i % MOD;
        rfac[i] = fpow(fac[i], MOD - 2);
    }
    for (int i=2;i<=100;i++){
        ll temp = comb(i, 2);
        if (temp == 225){
            cout << i << " " << temp << el;
        }
    }
    cin >> n >> q;
    while (q--){
        solve();
    }    

    return 0;
}
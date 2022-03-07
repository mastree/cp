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
const ll MOD = 998244353;

ll fac[N];
ll fpow(ll a, ll b){
    a %= MOD;
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

int n, m;
ll d[N], ar[N], br[N];
ll ans[N];

ll under(ll def){
    int l = 0, r = n;
    while (l < r){
        int m = (l + r + 1) / 2;
        if (d[m] < def){
            l = m;
        } else{
            r = m - 1;
        }
    }
    return l;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    fac[0] = 1;
    for (int i=1;i<N;i++){
        fac[i] = fac[i - 1] * i % MOD;
    }

    cin >> n >> m;
    for (int i=1;i<=n;i++){
        cin >> d[i];
    }
    sort(d + 1, d + n + 1);
    for (int i=1;i<=m;i++){
        cin >> ar[i] >> br[i];
    }
    for (int i=1;i<=m;i++){
        ll a = under(br[i]);
        ll b = n - a;
        if (a == n){
            ans[i] = 0;
            continue;
        } else if (ar[i] > b){
            ans[i] = 0;
            continue;
        } else if (ar[i] == 0){
            ans[i] = n;
            continue;
        }
        for (int j=1;j<=n;j++){
            if (ar[i] > j || b < ar[i] || a < j - ar[i]) continue;
            ll temp = (((b * comb(b - 1, ar[i] - 1) % MOD) * comb(a, j - ar[i]) % MOD) * comb(j - 1, ar[i] - 1) % MOD) * comb(n - j, b - ar[i]) % MOD;
            cout << i << ":" << temp << ":" << n - j << " ";
            ans[i] = (ans[i] + temp * (n - j)) % MOD;
        }
        cout << el;
        ans[i] = ans[i] * inv(fac[m]) % MOD;
    }
    for (int i=1;i<=m;i++){
        cout << ans[i] << el;
    }

    return 0;
}
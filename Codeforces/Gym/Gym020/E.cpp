#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int K = 20, N = (1 << K);
const ll MOD = 1e9 + 7;

int n, k;
ll ar[N];
ll dp[N][K];
ll pre[N][K];

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

ll invmod = inv(MOD);

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> k;
    n = (1 << k);
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    if (1){
        ll temp = inv((1LL << (k + 1)));
        for (int i=1;i<=n;i++){
            dp[i][k + 1] = temp;
        }
    }
    for (int i=k;i>=0;i--){
        dp[1][i] = 2LL * dp[1][i + 1] % MOD;
    }
    for (int i=2;i<=n;i++){
        for (int j=0;j<=k;j++){
            pre[i - 1][j] = (pre[i - 2][j] + dp[i - 1][j]) % MOD;
        }
        for (int j=k;j>=0;j--){
            ll cur = 2LL * dp[i][j + 1] % MOD;
            dp[i][j] = cur * (1LL - pre[i - 1][j] + MOD) % MOD;
        }
    }
    for (int j=0;j<=k;j++){
        pre[n][j] = (pre[n - 1][j] + dp[n][j]) % MOD;
    }

    ll ans = 0;
    for (int i=k - 1;i>=0;i--){ // dep
        for (int j=1;j<=n;j++){
            for (int kk=j + 1;kk<=n;kk++){
                cout << (1LL << i) * dp[j][i] % MOD << " " << 2LL * dp[kk][i + 1] % MOD << el;
                // ans = (ans + (1LL << (i + 1)) * ((dp[j][i] * (2LL * dp[kk][i + 1] % MOD) % MOD) * (ar[j] * ar[kk] % MOD)) % MOD) % MOD;
                ans = (ans + ((1LL << i) * (dp[j][i] * (2LL * dp[kk][i + 1]) % MOD) % MOD) * (ar[j] * ar[kk] % MOD)) % MOD;
            }
        }
    }
    cout << ans << el;

    return 0;
}
#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int N = 110;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

int n;
ll ar[N];

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
ll comb(ll a, ll b){
    return fac[a] * inv(fac[a - b] * fac[b] % MOD) % MOD;
}

pll dp[N][N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            dp[i][j] = mp(INF, 0LL);
        }
    }

    cin >> n;
    n++;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    fac[0] = 1;
    for (ll i=1;i<N;i++){
        fac[i] = fac[i - 1] * i;
    }

    for (int i=1;i<=n;i++){
        dp[i][i] = mp(0, 1LL);
        if (i != n) dp[i][i + 1] = mp(0, 1LL);
    }

    for (int len=3;len<=n;len++){
        for (int i=1;i + len - 1<=n;i++){
            int j = i + len - 1;
            ll mn = INF;
            for (int m=i + 1;m<j;m++){
                ll temp = dp[i][m].fi + dp[m][j].fi + ar[i] * ar[m] * ar[j];
                mn = min(mn, temp);
            }
            dp[i][j].fi = mn;
            for (int m=i + 1;m<j;m++){
                if (dp[i][m].fi + dp[m][j].fi + ar[i] * ar[m] * ar[j] == mn){
                    ll llen = m - i - 1;
                    ll rlen = j - m - 1;

                    dp[i][j].se = (dp[i][j].se + (dp[i][m].se * dp[m][j].se % MOD)) % MOD;
                }
            }
        }
    }
    cout << dp[1][n].fi << " " << dp[1][n].se << el;

    return 0;
}
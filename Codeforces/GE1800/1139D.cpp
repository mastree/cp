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

const ll MOD = 1e9 + 7;
const int N = 1e5 + 10;

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

int m;
ll dp[N];
ll cnt[N];
vector<int> fac[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> m;
    for (int i=1;i<=m;i++){
        cnt[i] = m / i;
        for (int j=i;j<=m;j+=i){
            fac[j].pb(i);
        }
    }

    ll tempinv = inv(m);
    dp[1] = 0;
    for (int i=2;i<=m;i++){
        int len = fac[i].size();
        dp[i] = 1;
        ll a, b;
        for (int j=len - 1;j>=0;j--){
            ll gcc = fac[i][j];
            if (j == len - 1){
                a = m;
                b = m - cnt[gcc];
                ll temp = __gcd(a, b);
                a /= temp;
                b /= temp;
            } else{
                ll byk = cnt[gcc];
                dp[i] = (dp[i] + (dp[gcc] * tempinv % MOD) * byk % MOD) % MOD;
            } 
            for (int wk : fac[gcc]){
                if (wk == gcc) continue;
                cnt[wk] -= cnt[gcc];
            }
        }
        for (int j=0;j<len;j++){
            ll gcc = fac[i][j];
            for (int wk : fac[gcc]){
                if (wk == gcc) continue;
                cnt[wk] += cnt[gcc];
            }
        }
        dp[i] = (dp[i] * a % MOD) * inv(b) % MOD;
    }
    ll ans = 0;
    for (int i=1;i<=m;i++){
        ans = (ans + dp[i] + 1) % MOD;
    }
    ans = ans * tempinv % MOD;
    cout << ans << el;

    return 0;
}
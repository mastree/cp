#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e6 + 10;
const int M = 20;
const int MOD = 1e9 + 7;

int n, m;
pii ar[M];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=m;i++){
        cin >> ar[i].fi >> ar[i].se;
    }    
    vector<ll> dp(n + 1, 0), ndp(n + 1, 0);
    dp[0] = 1;
    for (int i=1;i<=m;i++){
        fill(ndp.begin(), ndp.end(), 0);
        for (int j=0;j<=n;j++){
            if (dp[j] == 0) continue;
            int a = j + ar[i].fi;
            int b = j + ar[i].se + 1;
            if (a <= n) ndp[a] = (ndp[a] + dp[j]) % MOD;
            if (b <= n) ndp[b] = (ndp[b] - dp[j] + MOD) % MOD;
        }
        ll cur = 0;
        for (int j=0;j<=n;j++){
            cur = (cur + ndp[j]) % MOD;
            ndp[j] = cur;
        }
        dp.swap(ndp);
    }
    cout << dp[n] << el;

    return 0;
}
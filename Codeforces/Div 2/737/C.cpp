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
const int MOD = 1e9 + 7;

int q;
int n, k;

ll fpow(ll a, ll b){
    ll ret = 1;
    while (b){
        if (b & 1){
            ret = ret * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return ret;
}

ll dp[N][2]; // draw, win

void solve(){
    cin >> n >> k;
    ll fpm = fpow(2, n - 1);
    ll fp = fpow(2, n);
    for (int i=1;i<=k;i++){
        if (n & 1){
            dp[i][0] = dp[i - 1][0] * (fpm + 1) % MOD;
            dp[i][1] = dp[i - 1][1] % MOD;
        } else{
            dp[i][0] = dp[i - 1][0] * (fpm - 1 + MOD) % MOD;
            dp[i][1] = (dp[i - 1][1] * fp + dp[i - 1][0]) % MOD;
        }
    }
    cout << (dp[k][0] + dp[k][1]) % MOD << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    dp[0][0] = 1;
    dp[0][1] = 0;

    cin >> q;
    while (q--){
        solve();
    }

    return 0;
}
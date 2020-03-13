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

const int N = 5e3 + 3;
const ll MOD = 1e9 + 7;

int n, a, b, k;
ll dp[N][N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> a >> b >> k;
    dp[a][0] = 1;

    for (int j=1;j<=k;j++){
        vector <ll> temp(n + 3, 0);
        for (int i=1;i<=n;i++){
            int jarak = abs(b - i) - 1;
            int a = max(i-jarak, 1);
            int b = min(i+jarak, n);
            temp[a] = (temp[a] + dp[i][j-1]) % MOD;
            temp[i] = (temp[i] - dp[i][j-1] + MOD) % MOD;
            temp[i+1] = (temp[i+1] + dp[i][j-1]) % MOD;
            temp[b+1] = (temp[b+1] - dp[i][j-1] + MOD) % MOD;
        }
        ll cur = 0;
        for (int i=1;i<=n;i++){
            cur = (cur + temp[i] + MOD) % MOD;
            dp[i][j] = cur;
        }
    }

    ll ans = 0;
    for (int i=1;i<=n;i++){
        ans=(ans + dp[i][k]) % MOD;
        // cout << dp[i][k] << el;
    }
    cout << ans << el;

    return 0;
}
#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e3 + 10;
const ll MOD = 1e9 + 7;

ll n, m;
ll dp[N][2];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    dp[0][0] = 1;

    ll pus = 1;
    for (int i=1;i<=n;i++){
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) * (m - 1) % MOD;
        dp[i][1] = dp[i - 1][0];
        pus = pus * (m - 1) % MOD;
    }
    cout << (dp[n][0] + dp[n][1] - pus + MOD) % MOD << el;

    return 0;
}
#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e3 + 10, TOT = 1e4;
const ll MOD = 1e9 + 7;

int n;
int ar[N];
ll dp[TOT + N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    dp[ar[1]] = 2;
    ll ans = 0;
    for (int i=2;i<=n;i++){
        ll ndp[TOT + N];
        fill(ndp, ndp + TOT + N, 0);
        ndp[ar[i]] = 2;
        for (int j=0;j<=TOT;j++){
            ndp[j + ar[i]] = (ndp[j + ar[i]] + dp[j]) % MOD;
            ndp[abs(j - ar[i])] = (ndp[abs(j - ar[i])] + dp[j]) % MOD;
        }
        for (int j=0;j<TOT + N;j++){
            dp[j] = ndp[j];
        }
        ans = (ans + dp[0]) % MOD;
    }
    cout << ans << el;

    return 0;
}
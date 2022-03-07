#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

// f(x) = 
// if x > n for every i (1 <= i <= n) min(f(x - i) + A[i])
// else A[i]

const int N = 110;
const int MX = 1e4 + 10;
const ll INF = 1e18 + 10;

int n, q;
ll ar[N];
ll dp[MX];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        dp[i] = ar[i];
    }
    for (int i=n + 1;i<MX;i++){
        dp[i] = dp[i - 1] + ar[1];
        for (int j=2;j<=n;j++){
            dp[i] = min(dp[i], dp[i - j] + ar[j]);
        }
    }
    while (q--){
        int k;
        cin >> k;
        if (k < MX){
            cout << dp[k] << el;
            continue;
        }
        int sisa = k - (MX - 1);
        ll ans = INF;
        for (int i=1;i<=n;i++){
            int kali = (sisa + i - 1) / i;
            ll cur = ar[i] * kali + dp[k - i * kali];
            ans = min(ans, cur);
        }
        cout << ans << el;
    }

    return 0;
}
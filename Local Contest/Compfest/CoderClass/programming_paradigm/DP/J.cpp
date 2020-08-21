#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 110, TOTV = 1e5 + 10;
const int INF = 1e9 + 100;

int n, m;
pii ar[N];
int dp[TOTV]; // dp[total-value] = min weight

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    fill(dp, dp + TOTV, INF);
    dp[0] = 0;
    cin >> n >> m;
    for (int i=1;i<=n;i++){
        cin >> ar[i].fi;
    }
    for (int i=1;i<=n;i++){
        cin >> ar[i].se;
    }
    for (int i=1;i<=n;i++){
        for (int j=TOTV - 2;j - ar[i].se>=0;j--){
            dp[j] = min(dp[j], dp[j - ar[i].se] + ar[i].fi);
            dp[j] = min(dp[j], dp[j + 1]);
        }
    }
    int ans = 0;
    for (int i=1;i<TOTV;i++){
        if (dp[i] <= m) ans = i;
    }
    cout << ans << el;

    return 0;
}
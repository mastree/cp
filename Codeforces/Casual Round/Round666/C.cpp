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
const ll INF = 1e18;

int n;
ll rel[4], d;
ll ar[N];

ll dp[N], best[N]; 

ll get(int l){
    return best[n] - best[l - 1] + (n - l) * d;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=3;i++){
        cin >> rel[i];
    }
    cin >> d;
    rel[1] = min(rel[1], rel[3]);
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        if (i != n){
            best[i] = min(ar[i] * rel[1] + min(rel[3], min(rel[1], rel[2]) * 2LL) + d, rel[2] + d + min(rel[1], rel[2]));
        } else{
            best[i] = min(ar[i] * rel[1] + min(rel[3], min(rel[1], rel[2]) * 2LL + d * 2), rel[2] + d * 2 + min(rel[1], rel[2]));
        }
        best[i] += best[i - 1];
    }
    fill(dp, dp + n + 2, INF);
    ll ans = INF;
    dp[0] = 0;
    for (int i=1;i<=n;i++){
        ans = min(ans, dp[i - 1] + get(i));
        dp[i] = min(ar[i] * rel[1] + min(rel[3], min(rel[1], rel[2]) * 2LL + d * 2) + d, rel[2] + d * 2 + min(rel[1], rel[2]) + d) + dp[i - 1];
        if (i >= 2){
            dp[i] = min(dp[i], dp[i - 2] + rel[2] + d + best[i - 1] - best[i - 2] + min(rel[1], rel[2]) + d + d);
        }
    }
    ans = min(ans, dp[n]);
    cout << ans << el;

    return 0;
}
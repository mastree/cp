#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;

const int N = 5e3 + 10;
const ll MOD = 1e9 + 7;

int n;
int ar[N];
pil dp[N]; // dp[last-picked] = len, count

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i=0;i<N;i++) dp[i] = mp(0, 0LL);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    dp[0] = mp(0, 1LL);
    for (int i=1;i<=n;i++){
        int mx = -1;
        for (int j=0;j<ar[i];j++){
            mx = max(mx, dp[j].fi);
        }
        ll cnt = 0;
        for (int j=0;j<ar[i];j++){
            if (dp[j].fi == mx){
                cnt = (cnt + dp[j].se) % MOD;
            }
        }
        mx++;
        if (cnt == 0) continue;
        if (mx > dp[ar[i]].fi){
            dp[ar[i]] = mp(mx, cnt);
        } else if (mx == dp[ar[i]].fi){
            dp[ar[i]].se = (dp[ar[i]].se + cnt) % MOD;
        }
    }
    int mx = -1;
    for (int i=0;i<N;i++){
        mx = max(mx, dp[i].fi);
    }
    ll ans = 0;
    for (int i=0;i<N;i++){
        if (dp[i].fi == mx) ans = (ans + dp[i].se) % MOD;
    }
    cout << mx << " " << ans << el;

    return 0;
}
#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const ll INF = 1e18 + 10;

int q;
int n;

void solve(){
    cin >> n;
    vector<ll> vec(n + 1);
    ll tot = 0;
    for (int i=1;i<=n;i++){
        cin >> vec[i];
        tot += vec[i];
    }
    // part 1
    vector<vector<ll>> dp[2];
    dp[0].resize(n + 2, vector<ll>(n + 2, INF)); // min
    dp[1].resize(n + 2, vector<ll>(n + 2, -INF)); // max
    for (int len=1;len<=n;len++){
        for (int i=1;i + len - 1<=n;i++){
            int j = i + len - 1;
            if (i == j){
                dp[0][i][j] = 0;
                dp[1][i][j] = vec[i];
                // cout << 0 << " " << i << " " << j << " " << dp[0][i][j] << el;
                // cout << 1 << " " << i << " " << j << " " << dp[1][i][j] << el;
                continue;
            }
            int bi = i + 1;
            int bj = j - 1;
            // 0
            dp[0][i][j] = dp[1][bi][j];
            dp[0][i][j] = min(dp[0][i][j], dp[1][i][bj]);
            // 1
            dp[1][i][j] = dp[0][bi][j] + vec[i];
            dp[1][i][j] = max(dp[1][i][j], dp[0][i][bj] + vec[j]);
            // cout << 0 << " " << i << " " << j << " " << dp[0][i][j] << el;
            // cout << 1 << " " << i << " " << j << " " << dp[1][i][j] << el;
        }
    }
    vector<string> ans;
    {
        int red = dp[1][1][n];
        int green = tot - red;
        if (red > green){
            ans.pb("Red");
        } else if (green > red){
            ans.pb("Green");
        } else{
            ans.pb("Tie");
        }
    }
    dp[0].resize(n + 2, vector<ll>(n + 2, INF)); // min
    dp[1].resize(n + 2, vector<ll>(n + 2, -INF)); // max
    for (int len=1;len<=n;len++){
        for (int i=1;i + len - 1<=n;i++){
            int j = i + len - 1;
            if (i == j){
                dp[0][i][j] = 0;
                dp[1][i][j] = vec[i];
                continue;
            }
            int bi = i + 1;
            int bj = j - 1;
            // 0
            dp[0][i][j] = dp[1][bi][j];
            dp[0][i][j] = min(dp[0][i][j], dp[1][i][bj]);
            // 1
            dp[1][i][j] = dp[0][bi][j] + vec[i];
            dp[1][i][j] = max(dp[1][i][j], dp[0][i][bj] + vec[j]);

            if (vec[i] == vec[j]){
                if (len > 2){
                    dp[0][i][j] = min(dp[0][i][j], dp[1][bi][bj]);
                    dp[1][i][j] = max(dp[1][i][j], dp[0][bi][bj] + vec[i] + vec[j]);
                } else{
                    dp[0][i][j] = 0;
                    dp[1][i][j] = max(dp[1][i][j], vec[i] + vec[j]);
                }
            }
        }
    }
    {
        int red = dp[1][1][n];
        int green = tot - red;
        if (red > green){
            ans.pb("Red");
        } else if (green > red){
            ans.pb("Green");
        } else{
            ans.pb("Tie");
        }
    }
    cout << ans[0] << ' ' << ans[1] << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        solve();
    }

    return 0;
}
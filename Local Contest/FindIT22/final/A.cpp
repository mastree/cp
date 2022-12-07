#pragma gcc optimize ("O2")
#pragma gcc optimize ("unroll-loop")

#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int INF = 1e9 + 10;
const int MAXVEC = 1e9;

int n;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    vector<int> vec(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> vec[i];
    }
    vector<vector<pii>> dp(n + 1, vector<pii>(n + 1, make_pair(0, 0))); // max, min
    vector<int> ans(n, -INF);
    for (int i = 1; i <= n; i++) {
        dp[i][i] = {vec[i], vec[i]};
        ans[n - 1] = max(ans[n - 1], dp[i][i].first);
    }
    for (int len = 2; len <= n; len++) {
        for (int l = 1; l + len - 1 <= n; l++) {
            int r = l + len - 1;
            dp[l][r].first = max(dp[l + 1][r].second, dp[l][r - 1].second);
            dp[l][r].second = min(dp[l + 1][r].first, dp[l][r - 1].first);
            ans[n - len] = max(ans[n - len], dp[l][r].first);
        }
    }
    for (auto& x : ans) cout << x << ' '; cout << '\n';

    return 0;
}
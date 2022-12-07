#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

// bottom-up 1 = nyari nilai sekarang
int solve(int n, const vector<int>& vec) {
    // dp[posisi] = total cost
    vector<int> dp(n, 0);
    if (n > 1) dp[1] = dp[0] + abs(vec[1] - vec[0]);
    for (int i = 2; i < n; i++) {
        dp[i] = min(dp[i - 1] + abs(vec[i] - vec[i - 1]), dp[i - 2] + abs(vec[i] - vec[i - 2]));
    }
    return dp[n - 1];
}

// transisi
// dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), 
//              dp[i - 2] + abs(h[i] - h[i - 2]))

// bottom-up 2 = update nilai di depan
int solve2(int n, const vector<int>& vec) {
    const int INF = 2e9;

    // dp[posisi] = total cost
    vector<int> dp(n, INF);
    dp[0] = 0;
    for (int pos = 0; pos < n - 1; pos++) {
        for (int next = pos + 1; next <= min(pos + 2, n - 1); next++) {
            dp[next] = min(dp[next], dp[pos] + abs(vec[next] - vec[pos]));
        }
    }
    return dp[n - 1];
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> vec(n);
    for (auto& x : vec) {
        cin >> x;
    }
    cout << solve2(n, vec) << '\n';

    return 0;
}

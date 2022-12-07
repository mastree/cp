#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const ll INF = 1e18;

int n, m, d;
vector<pair<int, pii>> vec; // t, (a, b)

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> d;
    for (int i = 1; i <= m; i++) {
        int a, b, t;
        cin >> a >> b >> t;
        vec.emplace_back(t, mp(a, b));
    }

    // dp[n][m] = max coins

    vector<ll> dp(n + 1, 0), ndp(n + 1, -INF); 
    int lastt = vec[0].first;
    for (auto& firework : vec) {
        int t = firework.first;
        int a = firework.second.first;
        int b = firework.second.second;


    }

    return 0;
}
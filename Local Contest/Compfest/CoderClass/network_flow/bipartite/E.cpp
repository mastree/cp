#pragma gcc optimize ("O2")
#pragma gcc optimize ("unroll-loops")

#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 20;
const double INF = 1e18;

int n, m;
double ar[N][N];
double dp[(1 << N)];

int bcnt[(1 << N)];
vector<int> maskgroup[N + 2];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin >> ar[i][j];
        }
    }
    for (int i=0;i<(1 << m);i++){
        bcnt[i] = __builtin_popcount(i);
        maskgroup[bcnt[i]].pb(i);
    }
    fill(dp, dp + (1 << N), INF);
    dp[0] = 0.0;
    for (int i=0;i<n;i++){
        for (auto& mask : maskgroup[i]){
            for (int j=0;j<m;j++){
                int nmask = (mask | (1 << j));
                if (nmask == mask) continue;
                dp[nmask] = min(dp[nmask], dp[mask] + ar[i][j]);
            }
        }
    }
    double ans = INF;
    for (auto& mask : maskgroup[n]) ans = min(ans, dp[mask]);
    cout << fixed << setprecision(11) << ans / n << el;

    return 0;
}
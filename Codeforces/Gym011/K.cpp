#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 3e3 + 10;
const ll MOD = 1e9 + 7;

int n, k;
vector<int> adj[N];
ll dp[N][N];
ll c;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i=2;i<=n;i++){
        int p;
        cin >> p;
        p++;
        adj[p].pb(i);
        adj[i].pb(p);
    }
    c = k;
    dp[1][1] = c;
    for (int i=1;i<n;i++){
        for (ll j=1;j<=c;j++){
            dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j] * (c - j)) % MOD;
            dp[i + 1][j] = (dp[i + 1][j] + dp[i][j] * (j - 1LL)) % MOD;
        }
    }
    cout << dp[n][c] << el;

    return 0;
}
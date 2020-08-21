#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 110, M = 1e4 + 10;
const ll MOD = 1e9 + 7;

int q;
int n, m;
int ar[N];
ll dp[N][M];

void init(){
    for (int i=0;i<=n;i++){
        for (int j=0;j<=m;j++){
            dp[i][j] = 0;
        }
    }
}

void solve(){
    cin >> n >> m;
    init();
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    dp[0][0] = 1;
    for (int i=1;i<=n;i++){
        for (int j=0;j<=m;j++){
            dp[i][j] = dp[i - 1][j];
        }
        for (int j=ar[i];j<=m;j++){
            dp[i][j] = (dp[i][j] + dp[i][j - ar[i]]) % MOD;
        }
    }
    cout << dp[n][m] << el;
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
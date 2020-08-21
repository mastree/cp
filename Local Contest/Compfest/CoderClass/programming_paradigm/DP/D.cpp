#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e3 + 10;
const ll MOD = 1e9 + 7;

int r, c, n;
bool jebak[N][N];
ll dp[N][N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> r >> c >> n;
    for (int i=1;i<=n;i++){
        int a, b;
        cin >> a >> b;
        jebak[a][b] = 1;
    }
    dp[1][1] = 1;
    for (int i=1;i<=r;i++){
        for (int j=1;j<=c;j++){
            if (i == j && i == 1) continue;
            if (jebak[i][j]) continue;
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
        }
    }
    cout << dp[r][c] << el;

    return 0;
}
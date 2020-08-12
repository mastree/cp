#pragma gcc optimize ("O3")
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

const int N = 510;

int n, m, k;
bool ar[N][N];
int le[N][N], ri[N][N];
ll dp[N][N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    for (int lup=1;lup<=k;lup++){
        int ia, ja, ib, jb;
        cin >> ia >> ja >> ib >> jb;
        for (int i=ia;i<=ib;i++){
            for (int j=ja;j<=jb;j++){
                ar[i][j] = 1;
            }
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (ar[i][j]) le[i][j] = le[i][j - 1];
            else le[i][j] = j;
        }
        ri[i][m + 1] = m + 1;
        for (int j=m;j>=1;j--){
            if (ar[i][j]) ri[i][j] = ri[i][j + 1];
            else ri[i][j] = j;
        }
    }
    for (int i=n;i>=0;i--){
        for (int j=1;j<=m;j++){
            if (ar[i][j]) continue;
            if (ar[i + 1][j]){
                dp[i][j] = 1LL + dp[i + 1][le[i + 1][j]] + dp[i + 1][ri[i + 1][j]];
            } else{
                dp[i][j] = dp[i + 1][j];
            }
        }
    }
    ll ans = 0;
    for (int i=1;i<=m;i++){
        ans = max(ans, dp[0][i]);
    }
    cout << ans << el;

    return 0;
}
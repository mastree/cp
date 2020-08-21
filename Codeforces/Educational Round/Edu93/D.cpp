#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 210;

int rlen, glen, blen;
int r[N], g[N], b[N];
int dp[N][N][N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> rlen >> glen >> blen;
    for (int i=1;i<=rlen;i++){
        cin >> r[i];
    }
    for (int i=1;i<=glen;i++){
        cin >> g[i];
    }
    for (int i=1;i<=blen;i++){
        cin >> b[i];
    }
    sort(r + 1, r + 1 + rlen, greater<int>());
    sort(g + 1, g + 1 + glen, greater<int>());
    sort(b + 1, b + 1 + blen, greater<int>());
    int ans = 0;
    for (int i=0;i<=rlen;i++){
        for (int j=0;j<=glen;j++){
            for (int k=0;k<=blen;k++){
                int ni = i + 1, nj = j + 1, nk = k + 1;
                // ij
                if (ni <= rlen && nj <= glen){
                    dp[ni][nj][k] = max(dp[ni][nj][k], dp[i][j][k] + r[ni] * g[nj]);
                }
                // ik
                if (ni <= rlen && nk <= blen){
                    dp[ni][j][nk] = max(dp[ni][j][nk], dp[i][j][k] + r[ni] * b[nk]);
                }
                // jk
                if (nj <= glen && nk <= blen){
                    dp[i][nj][nk] = max(dp[i][nj][nk], dp[i][j][k] + g[nj] * b[nk]);
                }
                ans = max(ans, dp[i][j][k]);
            }
        }
    }
    cout << ans << el;

    return 0;
}
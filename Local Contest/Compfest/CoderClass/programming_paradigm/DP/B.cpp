#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 15;
const int INF = 1e9;

int n;
int mat[N][N];
int dp[(1 << N)][N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin >> mat[i][j];
        }
    }
    // for (int i=0;i<n;i++){
    //     for (int j=0;j<n;j++){
    //         mat[i][j] = min(mat[i][j], mat[j][i]);
    //     }
    // }
    for (int i=0;i<(1 << n);i++){
        for (int j=0;j<n;j++){
            dp[i][j] = INF;
        }
    }
    dp[1][0] = 0;
    for (int i=1;i<(1 << n);i++){
        for (int j=0;j<n;j++){
            if (dp[i][j] >= INF || ((1 << j) & i) == 0) continue;
            for (int k=0;k<n;k++){
                if ((1 << k) & i) continue;
                dp[(i + (1 << k))][k] = min(dp[(i + (1 << k))][k], dp[i][j] + mat[j][k]);
            }
        }
    }
    int ans = INF;
    for (int i=0;i<n;i++){
        ans = min(ans, dp[(1 << n) - 1][i] + mat[i][0]);
    }
    cout << ans << el;

    return 0;
}
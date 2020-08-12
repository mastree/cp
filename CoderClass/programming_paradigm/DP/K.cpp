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
const int INF = 1e9;

int n, m;
int ar[N];
int dp[N][N];

bool bisa[N][N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i=0;i<N;i++){
        fill(dp[i], dp[i] + N, INF);
    }
    dp[0][0] = 0;
    cin >> n >> m;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    for (int i=1;i<=n;i++){
        for (int j=0;j<=m;j++){
            dp[i][j] = dp[i - 1][j];
        }
        for (int j=ar[i];j<=m;j++){
            if (dp[i - 1][j - ar[i]] + 1 < dp[i][j]){
                dp[i][j] = dp[i - 1][j - ar[i]] + 1;
            }
        }
    }
    if (dp[n][m] >= INF){
        cout << -1 << el;
        return 0;
    }
    cout << dp[n][m] << el;
    bisa[n][m] = 1;
    for (int i=n;i>=1;i--){
        for (int j=m;j>=0;j--){
            if (bisa[i][j]){
                if (dp[i - 1][j] == dp[i][j]){
                    bisa[i - 1][j] = 1;
                }
                if (j - ar[i] >= 0){
                    if (dp[i - 1][j - ar[i]] + 1 == dp[i][j]){
                        bisa[i - 1][j - ar[i]] = 1;
                    }
                }
            }
        }
    }
    int cur = 0;
    vector<int> ans;
    for (int i=1;i<=n;i++){
        if (cur + ar[i] <= m && bisa[i][cur + ar[i]] && dp[i - 1][cur] + 1 == dp[i][cur + ar[i]]){
            ans.pb(i);
            cur += ar[i];
        }
    }
    for (int i=0;i<dp[n][m];i++){
        cout << ans[i];
        if (i != dp[n][m] - 1) cout << " ";
    }
    cout << el;

    return 0;
}
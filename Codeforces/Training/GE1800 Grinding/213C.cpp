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

const int N = 310, MN = 1000;
const int INF = 1e9;

int n;
int ar[N][N], dp[N][N];
int ans;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cin >> ar[i][j];
        }
    }
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            dp[i][j] = -INF;
        }
    }
    dp[1][1] = ar[1][1];
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            for (int k=j;k<=n;k++){
                if (j == k) dp[j][k] = max(dp[j][k], dp[j - 1][k]);
                else dp[j][k] = max(dp[j][k], dp[j - 1][k] + ar[i][j]);
            }
        }
        for (int j=1;j<=n;j++){
            for (int k=j;k<=n;k++){
                if (j == k){
                    dp[j][k] = max(dp[j][k], dp[j][k - 1]);
                    dp[j][k] = max(dp[j][k], dp[j - 1][k]);
                } else{
                    dp[j][k] = max(dp[j][k], dp[j][k - 1] + ar[i][k]);
                }
            }
        }
        if (i < n){
            for (int j=1;j<=n;j++){
                for (int k=j;k<=n;k++){
                    if (j == k) dp[j][k] += ar[i + 1][j];
                    else dp[j][k] += ar[i + 1][j] + ar[i + 1][k];
                }
            }
        }
    }
    cout << dp[n][n] << el;

    return 0;
}
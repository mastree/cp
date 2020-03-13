#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'

using namespace std;

const int N = 2e3 + 10;

int n, t;
double p, pcomp;
double dp[N][N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> p >> t;
    pcomp = (double)1 - p;
    dp[0][0] = 1;
    for (int i=1;i<=t;i++){
        dp[i][0] = dp[i-1][0] * pcomp;
        // cout << i << "=>" << el;
        // cout << dp[i][0] << " ";
        for (int j=1;j<=min(i, n);j++){
            if (j == n){
                dp[i][j] = dp[i-1][j-1] * p + dp[i-1][j];
            } else{
                dp[i][j] = dp[i-1][j-1] * p + dp[i-1][j] * pcomp;
            }
            // cout << dp[i][j] << " ";
        }
        // cout << el;
    }

    double ans = 0;
    for (int i=1;i<=n;i++){ 
        ans += dp[t][i] * (double)(i);
    }
    cout << fixed << setprecision(10) << ans << el;

    return 0;
}
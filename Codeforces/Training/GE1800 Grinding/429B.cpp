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

const int N = 1e3 + 5;

int n, m;
int ar[N][N], dp[4][N][N]; // arah 0=kiri-atas, 1=kanan-atas, 2=kiri-bawah, 3=kanan-bawah;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cin >> ar[i][j];
        }
    }

    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            dp[0][i][j] = max(dp[0][i-1][j], dp[0][i][j-1]) + ar[i][j];
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=m;j>=1;j--){
            dp[1][i][j] = max(dp[1][i-1][j], dp[1][i][j+1]) + ar[i][j];
        }
    }
    for (int i=n;i>=1;i--){
        for (int j=1;j<=m;j++){
            dp[2][i][j] = max(dp[2][i+1][j], dp[2][i][j-1]) + ar[i][j];
        }
    }
    for (int i=n;i>=1;i--){
        for (int j=m;j>=1;j--){
            dp[3][i][j] = max(dp[3][i+1][j], dp[3][i][j+1]) + ar[i][j];
        }
    }

    int ans = 0;
    for (int i=2;i<n;i++){
        for (int j=2;j<m;j++){
            int cur1 = 0, cur2 = 0;
            cur1 += dp[0][i-1][j] + dp[3][i+1][j];
            cur1 += dp[1][i][j+1] + dp[2][i][j-1];
            cur2 += dp[0][i][j-1] + dp[3][i][j+1];
            cur2 += dp[1][i-1][j] + dp[2][i+1][j];
            ans = max(ans, max(cur1, cur2));
        }
    }
    cout << ans << el;

    return 0;
}
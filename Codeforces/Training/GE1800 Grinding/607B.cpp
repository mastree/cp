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

const int N = 507;
int n;
int ar[N];
int dp[N][N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }

    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if (j<i) continue;
            if (j==i) dp[i][i] = 1;
            else {
                dp[i][j] = N;
            }
        }
    }

    for (int j=2;j<=n;j++){
        for (int i=j-1;i>=1;i--){
            dp[i][j] = min(dp[i][j], dp[i+1][j] + 1);
            if (ar[i]==ar[i+1]){
                dp[i][j] = min(dp[i][j], dp[i+2][j] + 1);
            }

            for (int k=j;k>i+1;k--){
                if (ar[i]==ar[k]){
                    dp[i][j] = min(dp[i][j], dp[i+1][k-1] + dp[k+1][j]);
                }
            }
        }
    }

    cout << dp[1][n] << el;

    return 0;
}
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

const int N = 5e3 + 3;

int n, m;
int ar[N];
int dp[N][N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=n;i++){
        double dummy;
        cin >> ar[i] >> dummy;
    }

    for (int i=0;i<=n;i++){
        for (int j=0;j<=m;j++){
            if (i==0){
                dp[i][j] = 0;
            } else{
                dp[i][j] = N;
            }
        }
    }

    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (ar[i]==j){
                dp[i][j] = dp[i-1][j];
            } else{
                dp[i][j] = 1 + dp[i-1][j];
            }
        }

        for (int j=2;j<=m;j++){
            dp[i][j] = min(dp[i][j], dp[i][j-1]);
        }
    }

    cout << dp[n][m] << el;

    return 0;
}
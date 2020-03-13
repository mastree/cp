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

const int N = 1e3 + 10;
const int INF = 1e9 + 7;

int n, m, x, y;
string s[N];
int ar[N][N];
int dp[N][N][2];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> x >> y;
    for (int i=1;i<=n;i++){
        cin >> s[i];
    }

    for (int i=0;i<=m;i++){
        for (int j=0;j<=y;j++){
            for (int k=0;k<2;k++){
                dp[i][j][k] = INF;
            }
        }
    }
    dp[0][0][0] = 0;
    dp[0][0][1] = 0;

    for (int i=1;i<=m;i++){
        int plus = 0;
        for (int j=1;j<=n;j++){
            if (s[j][i-1] == '.') plus++;
        }
        for (int j=1;j<=y;j++){
            for (int k=0;k<2;k++){
                if (k){
                    dp[i][j][k] = dp[i-1][j-1][k] + plus;
                } else{
                    dp[i][j][k] = dp[i-1][j-1][k] + n - plus;
                }
            }
        }
        
        for (int j=x;j<=y;j++){
            dp[i][0][0] = min(dp[i][0][0], dp[i][j][1]);
            dp[i][0][1] = min(dp[i][0][1], dp[i][j][0]);
            
        }
    }

    cout << min(dp[m][0][0], dp[m][0][1]) << el;

    return 0;
}
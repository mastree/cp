#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 5e3 + 10;
const int INF = 1e9;

int n, m;
string a, b;

int dp[N][N];


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    cin >> a >> b;
    a = '*' + a;
    b = '*' + b;
    for (int i=0;i<=n;i++){
        for (int j=0;j<=m;j++){
            if (i + 1 <= n) dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] - 1); 
            if (j + 1 <= m) dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] - 1); 
            if (i + 1 <= n && j + 1 <= m){
                if (a[i + 1] == b[j + 1]){
                    dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 2);
                } else{
                    dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] - 2);
                }
            }
        }
    }
    int ans = 0;
    for (int i=0;i<=n;i++){
        for (int j=0;j<=m;j++){
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << el;

    return 0;
}
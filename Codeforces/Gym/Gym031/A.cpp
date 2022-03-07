#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using ld = long double;

const int N = 52;

int q;
ld p;
int n, x, y, k;
ld dp[N][N];
ld dp1[N];
ld satu = (ld)1;

void solve(){
    {
        double tempp;
        cin >> n >> tempp >> x >> y >> k;
        p = tempp;
    }
    x++;
    y++;
    if (n == 1){
        cout << satu << el;
        return;
    }
    if (x == y){
        for (int i=1;i<=n;i++){
            dp1[i] = 0;
        }
        dp1[x] = 1;
        for (int rd=1;rd<=k;rd++){
            ld bdp[N];
            for (int i=1;i<=n;i++){
                bdp[i] = dp1[i];
                if (1 == i || i == n){
                    dp1[i] = bdp[i] * p * (n - 2);
                } else{
                    dp1[i] = bdp[i] * p * (n - 3);
                }
            }
            int tot = 0;
            for (int i=1;i<=n;i++){
                int j = i + 1;
                if (1 <= j && j <= n){
                    dp1[i] += bdp[j] * p;
                    dp1[j] += bdp[i] * p;
                }
            }
            for (int i=1;i<=n;i++){
                dp1[i] = dp1[i] / (n - 1) + bdp[i] * (1 - p);
            }
        }
        cout << dp1[x] << el;
        return;
    }
    for (int i=0;i<=n + 1;i++){
        for (int j=0;j<=n + 1;j++){
            dp[i][j] = 0;
        }
    }
    dp[x][y] = 1;
    for (int rd=1;rd<=k;rd++){
        ld cntx[n + 2], cnty[n + 2];
        ld bdp[n + 2][n + 2];
        fill(cntx, cntx + n + 2, 0);
        fill(cnty, cnty + n + 2, 0);
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                bdp[i][j] = dp[i][j];
                dp[i][j] = 0;
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                if (i == j) continue;
                for (int a=1;a<=n;a++){
                    int b = a + 1;
                    if (1 <= b && b <= n){
                        if (a == i && j == b){
                            dp[j][i] += bdp[i][j];
                        } else if (i == a){
                            dp[i + 1][j] += bdp[i][j];
                        } else if (i == b){
                            dp[i - 1][j] += bdp[i][j];
                        } else if (j == a){
                            dp[i][j + 1] += bdp[i][j];
                        } else if (j == b){
                            dp[i][j - 1] += bdp[i][j];
                        } else{
                            dp[i][j] += bdp[i][j];
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                if (i == j) continue;
                dp[i][j] = dp[i][j] * (p / (n - 1)) + bdp[i][j] * (satu - p);
            }
        }
    }
    cout << dp[y][x] << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("assessment.in", "r", stdin); 
    cout << fixed << setprecision(5);

    cin >> q;
    for (int i=1;i<=q;i++){
        cout << "Case " << i << ": ";
        solve(); 
    }

    return 0;
}
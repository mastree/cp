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

const int N = 52;

int n;
bool mat[N][N];
int dp[N][N][N][N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            char c;
            cin >> c;
            mat[i][j] = (c == '#');
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            for (int i2=i;i2<=n;i2++){
                for (int j2=j;j2<=n;j2++){
                    if (i == i2 && j == j2 && !mat[i][j]){
                        dp[i][j][i2][j2] = 0;
                    } else{
                        dp[i][j][i2][j2] = max(i2 - i, j2 - j) + 1;
                    }
                }
            }
        }
    }
    for (int leni=0;leni<=n - 1;leni++){
        for (int lenj=0;lenj<=n - 1;lenj++){
            for (int i=1;i + leni<=n;i++){
                int lasti = i + leni;
                for (int j=1;j + lenj<=n;j++){
                    int lastj = j + lenj;
                    for (int mi=i;mi<=lasti;mi++){
                        dp[i][j][lasti][lastj] = min(dp[i][j][lasti][lastj], dp[i][j][mi][lastj] + dp[mi + 1][j][lasti][lastj]);
                    }
                    for (int mj=j;mj<=lastj;mj++){
                        dp[i][j][lasti][lastj] = min(dp[i][j][lasti][lastj], dp[i][j][lasti][mj] + dp[i][mj + 1][lasti][lastj]);
                    }
                }
            }
        }
    }
    cout << dp[1][1][n][n] << el;

    return 0;
}
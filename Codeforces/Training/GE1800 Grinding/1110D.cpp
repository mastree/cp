#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")

#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

constexpr int N = 1e6 + 10;
constexpr int A = 5, B = 7, M = 9;
constexpr int INF = 1e9;

int n, m;
int ar[N];
int ans;

int dp[2][M][M][M];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=n;i++){
        int a;
        cin >> a;
        ar[a]++;
    }
    for (int i=1;i<=m;i++){
        if (ar[i] < 6) continue;
        int temp = ar[i] / 3 - 2;
        ans += temp;
        ar[i] -= temp * 3;
    }

    for (int i=0;i<2;i++){
        for (int j=0;j<M;j++){
            for (int k=0;k<M;k++){
                for (int l=0;l<M;l++){
                    dp[i][j][k][l] = -INF;
                }
            }
        }
    }
    dp[1][ar[1]][ar[2]][ar[3]] = 0;
    for (int i=M - 1;i>=0;i--){
        for (int j=M - 1;j>=0;j--){
            for (int k=M - 1;k>=0;k--){
                if (i >= 3) dp[1][i - 3][j][k] = max(dp[1][i - 3][j][k], dp[1][i][j][k] + 1);
                if (j >= 3) dp[1][i][j - 3][k] = max(dp[1][i][j - 3][k], dp[1][i][j][k] + 1);
                if (k >= 3) dp[1][i][j][k - 3] = max(dp[1][i][j][k - 3], dp[1][i][j][k] + 1);
                if (i && j && k) dp[1][i - 1][j - 1][k - 1] = max(dp[1][i - 1][j - 1][k - 1], dp[1][i][j][k] + 1);
            }
        }
    }
    for (int id=1;id + 2<=m;id++){
        int turn = (id & 1), nturn = (turn ^ 1);
        if (id != 1){
            for (int i=0;i<A;i++){
                for (int j=0;j<B;j++){
                    for (int k=0;k<M;k++){
                        dp[turn][i][j][k] = -INF;
                    }
                }
            }
            for (int i=0;i<A;i++){
                for (int j=0;j<A;j++){
                    for (int k=0;k<B;k++){
                        dp[turn][j][k][ar[id + 2]] = max(dp[turn][j][k][ar[id + 2]], dp[nturn][i][j][k]);
                    }
                }
            }
        }

        for (int i=A - 1;i>=0;i--){
            for (int j=B - 1;j>=0;j--){
                for (int k=M - 1;k>=0;k--){
                    if (i >= 3) dp[turn][i - 3][j][k] = max(dp[turn][i - 3][j][k], dp[turn][i][j][k] + 1);
                    if (j >= 3) dp[turn][i][j - 3][k] = max(dp[turn][i][j - 3][k], dp[turn][i][j][k] + 1);
                    if (k >= 3) dp[turn][i][j][k - 3] = max(dp[turn][i][j][k - 3], dp[turn][i][j][k] + 1);
                    if (i && j && k) dp[turn][i - 1][j - 1][k - 1] = max(dp[turn][i - 1][j - 1][k - 1], dp[turn][i][j][k] + 1);
                }
            }
        }
    }

    int lastid = m - 2, turn = (lastid & 1);
    int tambah = 0;
    for (int i=0;i<M;i++){
        for (int j=0;j<M;j++){
            for (int k=0;k<M;k++){
                tambah = max(tambah, dp[turn][i][j][k]);
            }
        }
    }
    ans += tambah;
    cout << ans << el;

    return 0;
}
#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 510;
const int INF = 1e9 + 10;

int n, m;
string a, b;
int dp[N][N][N]; // pos, last len, k

int pre[N][2];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    cin >> a >> b;
    {
        string cur;
        for (int i=0;i<=m;i++){
            for (int j=0;j<2;j++){
                cur.pb(j + '0');
                for (int len=1;len<=i + 1;len++){
                    bool ok = 1;
                    for (int id=0;id<len;id++){
                        if (b[len - id - 1] != cur[i - id]){
                            ok = 0;
                            break;
                        }
                    }
                    if (ok) pre[i][j] = len;
                }
                cur.pop_back();
            }
            cur.pb(b[i]);
        }
    }

    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            for (int k=0;k<N;k++){
                dp[i][j][k] = INF;
            }
        }
    }
    dp[0][0][0] = 0;

    int K = n - m + 1;
    for (int i=0;i<n;i++){
        for (int j=0;j<=m;j++){
            for (int k=0;k<=K;k++){
                if (dp[i][j][k] == INF) continue;

                for (int nx=0;nx<2;nx++){
                    int tam = (a[i] != (nx + '0'));
                    int ni = i + 1;
                    int nj = pre[j][nx];
                    int nk = k + (nj == m);
                    dp[ni][nj][nk] = min(dp[ni][nj][nk], dp[i][j][k] + tam);
                }
            }
        }
    }
    for (int k=0;k<=K;k++){
        int ans = INF;
        for (int j=0;j<=m;j++){
            ans = min(ans, dp[n][j][k]);
        }
        if (ans == INF){
            cout << -1 << ' ';
        } else{
            cout << ans << ' ';
        }
    }
    cout << el;

    return 0;
}
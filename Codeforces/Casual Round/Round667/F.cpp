#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 210;
const int INF = 1e9;

int n, mx;
int ar[N];
int a, b;

int dp[2][N][N]; // [pos][cnt_a][moves]

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> mx;
    {
        string s;
        cin >> s;
        for (int i=1;i<=n;i++){
            ar[i] = s[i - 1] - 'a';
        }
    }
    {
        string s;
        cin >> s;
        a = s[0] - 'a';
        b = s[1] - 'a';
    }
    if (a == b){
        int cnt = 0;
        for (int i=1;i<=n;i++){
            if (ar[i] == a) cnt++;
        }
        cnt += min(mx, n - cnt);
        cout << cnt * (cnt - 1) / 2 << el;
        return 0;
    }
    for (int i=0;i<2;i++){
        for (int j=0;j<N;j++){
            for (int k=0;k<N;k++){
                dp[i][j][k] = -INF;
            }
        }
    }
    dp[1][0][0] = 0;
    for (int i=1;i<=n;i++){
        for (int j=0;j<=n;j++){
            for (int k=0;k<=mx;k++){
                dp[0][j][k] = dp[1][j][k];
                dp[1][j][k] = -INF;
            }
        }
        for (int j=0;j<=n;j++){
            for (int k=0;k<=mx;k++){
                if (ar[i] == a){
                    if (j) dp[1][j][k] = max(dp[1][j][k], dp[0][j - 1][k]); // fix di a
                } else if (ar[i] == b){
                    dp[1][j][k] = max(dp[1][j][k], dp[0][j][k] + j); // fix di b
                } else dp[1][j][k] = max(dp[1][j][k], dp[0][j][k]);

                if (k && j) dp[1][j][k] = max(dp[1][j][k], dp[0][j - 1][k - 1]); // ganti ke a
                if (k) dp[1][j][k] = max(dp[1][j][k], dp[0][j][k - 1] + j); // ganti ke b
            }
        }
    }
    int ans = 0;
    for (int i=0;i<=n;i++){
        for (int j=0;j<=mx;j++){
            ans = max(ans, dp[1][i][j]);
        }
    }
    cout << ans << el;

    return 0;
}
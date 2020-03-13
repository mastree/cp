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

const int N = 2e3 + 10;
const int INF = 1e5;

int n, h, l, r;
int ar[N];

int dp[N][N]; // ke berapa, sekarang wake-up di jam brp

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> h >> l >> r;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }

    for (int i=0;i<=n;i++){
        fill(dp[i], dp[i] + h + 1, -INF);
    }

    dp[0][0] = 0;
    for (int i=0;i<n;i++){
        for (int j=0;j<h;j++){
            if (dp[i][j] == -INF) continue;
            int nj = (j + ar[i + 1]) % h;
            if (l <= nj && nj <= r) dp[i + 1][nj] = max(dp[i + 1][nj], dp[i][j] + 1);
            else dp[i + 1][nj] = max(dp[i + 1][nj], dp[i][j]);
            nj = (j + ar[i + 1] - 1) % h;
            if (l <= nj && nj <= r) dp[i + 1][nj] = max(dp[i + 1][nj], dp[i][j] + 1);
            else dp[i + 1][nj] = max(dp[i + 1][nj], dp[i][j]);
        }
    }

    int ans = 0;
    for (int i=0;i<h;i++){
        ans = max(ans, dp[n][i]);
    }
    cout << ans << el;

    return 0;
}
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

const int N = 2e4 + 10;

int n, m, k;
ll dp[52][N];
ll ar[52][N];
ll pc[52][N];

ll ask(int i1, int j1, int i2, int j2){
    return pc[i2][j2] - pc[i1-1][j2] - pc[i2][j1-1] + pc[i1-1][j1-1];
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cin >> ar[i][j];
        }
    }

    for (int i=1;i<=n+2;i++){
        for (int j=1;j<=m;j++){
            pc[i][j] = pc[i-1][j] + pc[i][j-1] - pc[i-1][j-1] + ar[i][j];
        }
    }

    for (int i=1;i<=n;i++){
        ll le[m + 2], ri[m + 2];
        le[0] = 0;
        ri[m - k + 2] = 0;
        for (int j=1;j<=m-k+1;j++){
            le[j] = max(le[j - 1], dp[i-1][j]);
        }
        for (int j=m-k+1;j>0;j--){
            ri[j] = max(ri[j + 1], dp[i-1][j]);
        }

        for (int j=1;j<=m - k + 1;j++){
            dp[i][j] = ask(i, j, i+1, j+k-1);
            ll temp = 0;
            if (j - k >= 1){
                temp = max(temp, le[j-k]);
            }
            if (j + k <= m - k + 1){
                temp = max(temp, ri[j+k]);
            }
            dp[i][j] += temp;
            for (int j2=max(j-k+1, 1);j2<min(j+k, m - k + 2);j2++){
                temp = 0;
                temp += ask(i, j, i+1, j+k-1);
                dp[i][j] = max(dp[i][j], temp + dp[i-1][j2] - ask(i, max(j, j2), i, min(j + k - 1, j2 + k - 1)));
            }
        }
    }

    ll ans = 0;
    for (int i=1;i<=m;i++){
        ans = max(ans, dp[n][i]);
    }
    cout << ans << el;

    return 0;
}
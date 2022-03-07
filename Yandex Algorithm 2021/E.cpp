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

const int N = 103;
const int INF = 1e9 + 10;

int n, m;
int ar[N][N], ri[N][N];

int dp[N][N * N], ndp[N][N * N]; // last, curtot

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    int tot = 0;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            char c;
            cin >> c;
            ar[i][j] = c == '1';
            tot += ar[i][j];
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=m;j>=1;j--){
            ri[i][j] = ri[i][j + 1] + ar[i][j];
        }
    }
    for (int i=0;i<N;i++){
        ndp[i][0];
        for (int j=1;j<N * N;j++){
            dp[i][j] = INF;
            ndp[i][j] = INF;
        }
    }

    int mm = min(m, tot);
    for (int r=n;r>=1;r--){
        for (int last=mm;last>=0;last--){
            for (int taken=0;taken<=tot;taken++){
                if (last < mm) ndp[last][taken] = min(ndp[last][taken], ndp[last + 1][taken]);
                if (last <= taken) ndp[last][taken] = min(ndp[last][taken], dp[last][taken - last] + (last - ri[r][m - last + 1]));
            }
        }
        for (int last=0;last<N;last++){
            for (int taken=0;taken<N * N;taken++){
                dp[last][taken] = ndp[last][taken];
                ndp[last][taken] = INF;
            }
        }
    }

    int ans = INF;
    for (int i=0;i<=mm;i++){
        ans = min(ans, dp[i][tot]);
    }
    cout << ans << el;

    return 0;
}
#pragma gcc optimize ("O3")
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

const int N = 110;
const int INF = 1e9;

int n, tot;
pii ar[N];
int dp[N][N * N]; // dp[ambil botol][ambil air] = harga
int ndp[N][N * N];

int findk(){
    int ret = 0;
    int tot = 0;
    for (int i=1;i<=n;i++) tot += ar[i].se;
    
    for (int i=1;i<=n;i++){
        tot -= ar[i].fi;
        if (tot <= 0) return i;
    }
    return n;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i].se;
        tot += ar[i].se;
    }
    for (int i=1;i<=n;i++){
        cin >> ar[i].fi;
    }
    sort(ar + 1, ar + n + 1, greater<pii>());
    int mk = findk();
    for (int i=0;i<=mk;i++){
        for (int j=0;j<=tot;j++){
            dp[i][j] = INF;
        }
    }
    dp[0][0] = tot;
    for (int i=1;i<=n;i++){
        for (int j=0;j<=mk;j++){
            for (int k=0;k<=tot;k++){
                ndp[j][k] = dp[j][k];
            }
        }
        for (int j=0;j<mk;j++){
            for (int k=0;k<=tot;k++){
                int nj = j + 1;
                int nk = min(tot, k + ar[i].fi);
                dp[nj][nk] = min(dp[nj][nk], ndp[j][k] - ar[i].se);
            }
        }
    }
    cout << mk << " " << dp[mk][tot] << el;

    return 0;
}
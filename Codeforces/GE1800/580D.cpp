#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define ll long long
#define el '\n'

using namespace std;

const int N = 20;

int n, m, k;
ll bonus[N][N]; 
ll poin[N];
ll dp[(1 << N)][N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    for (int i=1;i<=n;i++){
        cin >> poin[i-1];
    }

    for (int i=0;i<k;i++){
        int a, b;
        ll c;
        cin >> a >> b >> c;
        bonus[a-1][b-1] = c;
    }

    for (int i=0;i<=(1 << n);i++){
        for (int j=0;j<n;j++){
            if (i==0){
                for (int k=0;k<n;k++){
                    dp[(i|(1 << k))][k] = poin[k];
                }
            } else{
                if ((i & (1 << j)) == 0){
                    continue;
                }

                for (int k=0;k<n;k++){
                    if ((i & (1 << k)) == 0){
                        dp[(i|(1 << k))][k] = max(dp[(i|(1 << k))][k], dp[i][j] + poin[k] + bonus[j][k]);
                    }
                }
            }
        }
    }
    // // cout << (2 | (1 << 0)) << el;

    // for (int i=0;i<(1 << n);i++){
    //     for (int j=0;j<n;j++){
    //         cout << i << " " << j << " : " << dp[i][j] << el;
    //     }
    // }

    ll ans = 0;
    for (int i=0;i<(1 << n);i++){
        for (int j=0;j<n;j++){
            int cnt = 0;
            for (int k=0;k<n;k++){
                if ((i & (1 << k))) cnt++;
            }
            // cout << i << " => " << cnt << el;
            if (cnt == m){
                ans = max(ans, dp[i][j]);
            }
        }
    }

    cout << ans << el;

    return 0;
}
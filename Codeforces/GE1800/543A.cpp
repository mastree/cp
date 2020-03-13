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

const int N = 5e2 + 10;

int n, m, b;
ll mod;
ll dp[2][N][N];
ll ar[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> b >> mod;
    for (int i=0;i<n;i++){
        cin >> ar[i];
    }

    for (int i=0;i<2;i++){
        for (int j=0;j<N;j++){
            for (int k=0;k<N;k++){
                dp[i][j][k] = 0;
            }
        }
    }
    dp[0][0][0] = 1;
    for (int i=1;i<=m;i++){
        ll cur[N];
        fill(cur, cur + N, 0);
        if (i&1){
            for (int j=0;j<n;j++){
                for (int k=0;k<=b;k++){
                    cur[k] = (cur[k] + dp[0][j][k]) % mod;
                    dp[0][j][k] = 0;
                    if (k < ar[j]) continue;
                    dp[1][j][k] = cur[k - ar[j]];  
                }
            }
        } else{
            for (int j=0;j<n;j++){
                for (int k=0;k<=b;k++){
                    cur[k] = (cur[k] + dp[1][j][k]) % mod;
                    dp[1][j][k] = 0;
                    if (k < ar[j]) continue;
                    dp[0][j][k] = cur[k - ar[j]];  
                }
            }
        }

    }
    ll ans = 0, id = (m&1);
    for (int j=0;j<n;j++){
        for (int k=0;k<=b;k++){
            ans = (ans + dp[id][j][k]) % mod;
        }
    }

    cout << ans << el;

    return 0;
}
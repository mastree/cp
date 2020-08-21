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

const int N = 110;
const ll INF = 1e18;

int q;
int n, m;
ll ar[N][N];
ll dp[N][N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n >> m;
        for (int i=n;i>=1;i--){
            for (int j=m;j>=1;j--){
                cin >> ar[i][j];
            }
        }
        ll ans = INF;
        for (int ai=1;ai<=n;ai++){
            for (int aj=1;aj<=m;aj++){
                ll awal = ar[ai][aj] + ai + aj - 2;
                if (awal > ar[1][1]) continue;
                for (int i=0;i<=n + 1;i++){
                    fill(dp[i], dp[i] + m + 2, INF);
                }
                dp[1][1] =  ar[1][1] - awal;
                for (int i=1;i<=n;i++){
                    for (int j=1;j<=m;j++){
                        ll sup = awal - i - j + 2;
                        ll mn = min(dp[i - 1][j], dp[i][j - 1]);
                        if (mn == INF || sup > ar[i][j]) continue;
                        dp[i][j] = mn + ar[i][j] - sup;
                    }
                }
                ans = min(ans, dp[n][m]);
            }
        }
        cout << ans << el;
    }

    return 0;
}
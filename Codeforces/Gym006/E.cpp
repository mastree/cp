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

const int N = 2e5 + 10;
const int INF = 1e9;

int n;
pii ar[N];
int wins;

pair<int, pii> dp[N][2];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i].fi >> ar[i].se;
        if (ar[i].fi > ar[i].se) wins++;
    }    
    if (wins > n - wins){
        cout << 0 << el;
        return 0;
    }
    for (int i=0;i<=n;i++){
        for (int j=0;j<2;j++) dp[i][j] = mp(INF, mp(0, 0));
    }
    // dp[0][0] = mp(INF, 0);
    dp[0][1].fi = n - wins;
    for (int i=1;i<=n;i++){
        if (dp[i - 1][0].fi < dp[i - 1][1].fi){
            dp[i][0] = dp[i - 1][0];
            dp[i][0].se = mp(i - 1, 0);
        } else{
            dp[i][0] = dp[i - 1][1];
            dp[i][0].se = mp(i - 1, 1);
        }
        if (i == 1) continue;
        if (ar[i].fi > ar[i].se && ar[i - 1].fi <= ar[i - 1].se){
            if (ar[i].fi + ar[i - 1].fi > ar[i].se + ar[i - 1].se){
                if (dp[i][1].fi >= dp[i - 1][0].fi){
                    dp[i][1] = mp(dp[i - 1][0].fi - 1, mp(i - 1, 0));
                }
            }
        } else if (ar[i].fi <= ar[i].se && ar[i - 1].fi > ar[i - 1].se){
            if (ar[i].fi + ar[i - 1].fi > ar[i].se + ar[i - 1].se){
                if (dp[i][1].fi >= dp[i - 1][0].fi){
                    dp[i][1] = mp(dp[i - 1][0].fi - 1, mp(i - 1, 0));
                }
            }
        }
        // cout << i << " " << dp[i][0].fi << "," << dp[i][0].se.fi << "," << dp[i][0].se.se << " " << dp[i][1].fi << "," << dp[i][1].se.fi << "," << dp[i][1].se.se << el; 
        if (wins > dp[i][1].fi){
            cout << n - wins * 2 + 1 << el;
            pii cur = mp(i, 1);
            while (cur.fi != 0){
                // int ncur;
                // ncur = dp[cur - 1][0].se;
                // cout << cur << " " << cur - 1 << el;
                // cur = ncur;
                if (cur.se == 1) cout << cur.fi - 1 << " " << cur.fi << el;
                cur = dp[cur.fi][cur.se].se;
            }
            return 0;
        }
    }
    cout << -1 << el;

    return 0;
}
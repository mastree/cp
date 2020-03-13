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

const int N = 1e5 + 10;
const ll INF = 1e18;

int n;
string s;
ll ar[N];
ll dp[N][5];

string cek = "*hard";

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    cin >> s;
    s = "*" + s;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }

    for (int i=0;i<=n;i++){
        for (int j=0;j<5;j++){
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;
    for (int i=1;i<=n;i++){
        int id;
        for (id=1;id<5;id++){
            if (cek[id] == s[i]) break;
        }
        if (id == 5){
            for (int j=0;j<5;j++){
                dp[i][j] = dp[i-1][j];
            }
        } else{
            for (int j=0;j<id-1;j++){
                dp[i][j] = dp[i-1][j];
            }
            for (int j=id;j<5;j++){
                dp[i][j] = dp[i-1][j];
            }
            dp[i][id-1] = dp[i-1][id-1] + ar[i];
            dp[i][id] = min(dp[i][id], dp[i-1][id-1]);
        }
        // cout << i << " => " << id << el;
        // for (int j=0;j<5;j++){
        //     cout << dp[i][j] << " ";
        // }
        // cout << el;
    }
    ll ans = INF;
    for (int i=0;i<4;i++){
        ans = min(ans, dp[n][i]);
    }
    cout << ans << el;

    return 0;
}
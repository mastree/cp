#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
// #define MOD 1000000007
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'

using namespace std;

const int N = 2e5 + 10;
const int D = 1000;
const ll MOD = 1e9 + 7;

ll r, g;
ll dp[2][N]; // tinggi, kepake r;
ll ans;

ll butuh[D];

int bisa = 0;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (ll i=1;i<D;i++){
        butuh[i] = i * (i + 1) / 2;
    }

    cin >> r >> g;
    dp[0][0] = 1;
    for (int i=0;i<D - 1;i++){
        ll kur = i + 1;
        ll tot = 0;

        ll id = (i & 1);
        ll nid = (kur & 1);
        bisa = i;
        fill(dp[nid], dp[nid] + r + 1, 0);
        for (int j=0;j<=min(butuh[i], r);j++){
            ll sisar = r - j;
            ll sisag = g - (butuh[i] - j);
            if (sisag < 0) continue;

            if (sisar >= kur){
                dp[nid][j + kur] = (dp[nid][j + kur] + dp[id][j]) % MOD;
                tot = (tot + dp[id][j]) % MOD;
            }
            if (sisag >= kur){
                dp[nid][j] = (dp[nid][j] + dp[id][j]) % MOD;
                tot = (tot + dp[id][j]) % MOD;
            }
        }
        
        if (tot == 0) break;
    }
    for (int i=0;i<=r;i++){
        ans = (ans + dp[(bisa & 1)][i]) % MOD;
    }
    cout << ans << el;

    return 0;
}
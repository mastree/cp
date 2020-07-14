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

const int N = 1e5 + 10;
const int CN = 1e3 + 10;
const int INF = 1e9;

int n, k, g[3];
string s;
int ar[N];
vector <pii> v;

int dp[CN][CN];

int cnt2;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k >> g[0] >> g[1] >> g[2];
    cin >> s;
    char bef = s[0];
    int bcnt = 1;
    for (int i=1;i<=n;i++){
        if (i == n || s[i] != bef){
            pii temp = mp(bcnt, (bef == '#'));
            if (temp.se == 1){
                if (temp.fi > 2){
                    temp.fi = 2;
                }
                v.pb(temp);
            } else{
                if (temp.fi > 3){
                    temp.fi -= 2;
                    temp.fi %= 2;
                    temp.fi += 2;
                    cnt2 += (bcnt - temp.fi) / 2;
                }
                v.pb(temp);
            }
            if (i != n) bef = s[i];
            bcnt = 1;
        } else{
            bcnt++;
        }
    }
    int id = 0;
    for (auto x : v){
        // cout << x.fi << " " << x.se << el;
        for (int i=0;i<x.fi;i++){
            id++;
            ar[id] = x.se;
        }
    }
    n = id;
    int mnk = min(n, k);
    for (int i=0;i<=n;i++){
        for (int j=0;j<=mnk;j++){
            dp[i][j] = -INF;
        }
    }
    dp[0][0] = 0;
    for (int i=1;i<=n;i++){
        for (int j=0;j<=mnk;j++) dp[i][j] = dp[i - 1][j];
        if (ar[i] == 0){
            for (int j=1;j<=mnk;j++){
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + g[0]);
            }
            if (i == 1) continue;
            if (ar[i - 1] == 0){
                for (int j=0;j<=mnk;j++){
                    dp[i][j] = max(dp[i][j], dp[i - 2][j] + g[1]);
                }
            } else{
                if (i == 2) continue;
                if (ar[i - 2] == 0){
                    for (int j=0;j<=mnk;j++){
                        dp[i][j] = max(dp[i][j], dp[i - 3][j] + g[2]);
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i=0;i<=mnk;i++){
        int sisa = (k - i) / 2;
        int ganjil = (k - i) & 1;
        if (2 * g[0] > g[1]){
            int ganti;
            int banding;
            if (g[0] > g[1]){
                ganti = min(sisa + ganjil, cnt2);
                banding = dp[n][i] + (cnt2 - ganti) * g[1];
                if (sisa + ganjil <= cnt2){
                    banding += (sisa * 2 + ganjil) * g[0];
                } else{
                    banding += ganti * 2 * g[0];
                }
            } else{
                ganti = min(sisa, cnt2);
                banding = dp[n][i] + (cnt2 - ganti) * g[1] + ganti * g[0] * 2;
            }
            ans = max(ans, banding);
        } else{
            ans = max(ans, dp[n][i] + cnt2 * g[1]);
        }
    }
    cout << ans << el;

    return 0;
}
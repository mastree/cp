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

const int N = 8, MASK = (1 << N), CAP = 110;
const int INF = 1e9;

int q;
int en, t;
int n;
int regen[N], toxic[N];

int dp[MASK][CAP][CAP]; // mask, sisa_energy, toxic level -> max monster

void init(){
    for (int i=0;i<(1 << n);i++){
        for (int j=0;j<CAP;j++){
            for (int k=0;k<CAP;k++){
                dp[i][j][k] = -INF;
            }
        }
    }
    dp[0][100][0] = 0;
}

void solve(){
    cin >> en >> t;
    cin >> n;
    init();
    for (int i=0;i<n;i++){
        cin >> regen[i];
    }
    for (int i=0;i<n;i++){
        cin >> toxic[i];
    }

    for (int i=0;i<(1 << n);i++){
        for (int j=CAP - 1;j>=en + 1;j--){
            for (int k=0;k<CAP;k++){
                if (dp[i][j][k] == -INF) continue;
                int nj = j - en;
                int nk = max(0, k - t);
                dp[i][nj][nk] = max(dp[i][nj][nk], dp[i][j][k] + 1);

                for (int p=0;p<n;p++){
                    if (nk + toxic[p] >= 100) continue;
                    int ni = (i | (1 << p));
                    if (ni == i) continue;
                    
                    int nnj = min(100, nj + regen[p]);
                    int nnk = nk + toxic[p];
                    dp[ni][nnj][nnk] = max(dp[ni][nnj][nnk], dp[i][j][k] + 1);
                }
            }
        }
    }
    int ans = -INF;
    for (int i=0;i<(1 << n);i++){
        for (int j=0;j<CAP;j++){
            for (int k=0;k<CAP;k++){
                ans = max(ans, dp[i][j][k]);
            }
        }
    }
    cout << ans << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        solve();
    }

    return 0;
}
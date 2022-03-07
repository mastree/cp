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

const int N = 1e3 + 10;
const int K = 21;
const int INF = 1e9 + 10;
const string imposs = "IMPOSSIBLE";

int q;
int n, m, y, k; // row, col, take on col, max consecutive
int ar[N][N];

int dp[N][K][2];
int ndp[N][K][2];

void swap_dp(){
    for (int taken=0;taken<=y;taken++){
        for (int con=0;con<=k;con++){
            for (int take=0;take<2;take++){
                swap(dp[taken][con][take], ndp[taken][con][take]);
            }  
        }
    }
}

void solve(){
    cin >> n >> m >> y >> k;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cin >> ar[i][j];
        }
    }
    // vector<vector<vector<int>>> dp(y + 1, vector<vector<int>>(k + 1, vector<int>(2, -INF)));
    // vector<vector<vector<int>>> ndp(y + 1, vector<vector<int>>(k + 1, vector<int>(2, -INF))); 
    // take on col, consec, is_take
    dp[y][0][0] = 0;
    for (int r=1;r<=n;r++){
        for (int taken=0;taken<=y;taken++){
            for (int con=0;con<=k;con++){
                for (int take=0;take<2;take++){
                    if (taken == y){
                        dp[0][con][take] = max(dp[0][con][take], dp[taken][con][take]);
                    }
                    dp[taken][con][take] = -INF;
                }  
            }
        }
        for (int c=1;c<=m;c++){
            for (int taken=0;taken<=y;taken++){
                for (int con=0;con<=k;con++){
                    int ntaken;
                    int ncon;
                    // notake notake
                    if (dp[taken][con][0] > -INF){
                        ntaken = taken;
                        ncon = con;
                        ndp[ntaken][ncon][0] = max(ndp[ntaken][ncon][0], dp[taken][con][0]);
                    }

                    // notake take
                    if (dp[taken][con][0] > -INF){
                        ntaken = taken + 1;
                        ncon = 1;
                        if (ncon <= k && ntaken <= y){
                            ndp[ntaken][ncon][1] = max(ndp[ntaken][ncon][1], dp[taken][con][0] + ar[r][c]);
                        }
                    }

                    // take notake
                    if (dp[taken][con][1] > -INF){
                        ntaken = taken;
                        ncon = 0;
                        ndp[ntaken][ncon][0] = max(ndp[ntaken][ncon][0], dp[taken][con][1]);
                    }

                    // take take
                    if (dp[taken][con][1] > -INF){
                        ntaken = taken + 1;
                        ncon = con + 1;
                        if (ncon <= k && ntaken <= y){
                            ndp[ntaken][ncon][1] = max(ndp[ntaken][ncon][1], dp[taken][con][1] + ar[r][c]);
                        }
                    }
                }
            }
            // swap(dp, ndp);
            swap_dp();
        }
    }
    int mx = -INF;
    for (int con=0;con<=k;con++){
        for (int take=0;take<2;take++){
            mx = max(mx, dp[y][con][take]);
        }
    }
    if (mx == -INF){
        cout << imposs << el;
    } else{
        cout << mx << el;
    }
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
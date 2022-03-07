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

const int INF = 1e9 + 10;
const int N = 5e2 + 10;
const int K = 1e4 + 10;

int q;
int n, k;

int dp[K][3][2];
int ndp[K][3][2];

void reset(int id){
    if (id == 0){
        for (int i=0;i<=k;i++){
            for (int j=0;j<3;j++){
                for (int kk=0;kk<2;kk++){
                    dp[i][j][kk] = INF;
                }
            }
        }
    } else{
        for (int i=0;i<=k;i++){
            for (int j=0;j<3;j++){
                for (int kk=0;kk<2;kk++){
                    ndp[i][j][kk] = INF;
                }
            }
        }
    }
}
void assign(){
    for (int i=0;i<=k;i++){
        for (int j=0;j<3;j++){
            for (int kk=0;kk<2;kk++){
                dp[i][j][kk] = ndp[i][j][kk];
            }
        }
    }
}
void solve(){
    cin >> n >> k;
    vector<int> vec(n + 1);
    for (int i=1;i<=n;i++){
        cin >> vec[i];
    }
    reset(0);
    dp[0][0][0] = 0;
    for (int pos=1;pos<=n;pos++){
        reset(1);
        int x = vec[pos];
        for (int cnt=0;cnt<=k;cnt++){
            int ncnt = cnt + x;
            for (int last=0;last<=2;last++){
                for (int take=0;take<2;take++){
                    if ((take || last < 2) && ncnt <= k){
                        int nlast = last + (take != 1);
                        ndp[ncnt][nlast][1] = min(ndp[ncnt][nlast][1], dp[cnt][last][take] + 1);
                    }
                    ndp[cnt][last][0] = min(ndp[cnt][last][0], dp[cnt][last][take]);
                }
            }
        }
        assign();
    }
    int mn = INF;
    for (int i=0;i<3;i++){
        for (int j=0;j<2;j++){
            mn = min(mn, dp[k][i][j]);
        }
    }
    if (mn < INF) cout << mn << el;
    else cout << -1 << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    for (int i=1;i<=q;i++){
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}
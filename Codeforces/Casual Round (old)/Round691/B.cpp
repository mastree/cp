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

const int N = 110;
const int MX = 1e4;
const int INF = 1e8;

int n, tot;
pii ar[N];
int dp[N][N * N], ndp[N][N * N];
int ans[N];

void print(int x){
    if (x & 1){
        cout << x/2 << ".5";
    } else{
        cout << x/2 << ".0";
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i=1;i<=n;i++){
        cin >> ar[i].se >> ar[i].fi;
        ar[i] = {ar[i].fi, ar[i].se};
        tot += ar[i].fi;
    }    
    sort(ar + 1, ar + 1 + n, greater<pii>());
    for (int i=0;i<N;i++){
        for (int j=0;j<N * N;j++){
            dp[i][j] = -INF;
        }
    }
    dp[0][0] = 0;
    for (int i=1;i<=n;i++){
        for (int k=0;k<i;k++){
            for (int slot=MX;slot>=0;slot--){
                ndp[k][slot] = dp[k][slot];
            }
        }
        for (int k=0;k<i;k++){
            for (int slot=MX;slot>=0;slot--){
                dp[k + 1][slot + ar[i].se - ar[i].fi] = max(dp[k + 1][slot + ar[i].se - ar[i].fi], ndp[k][slot] + ar[i].fi);
            }
        }
    }
    for (int i=1;i<=n;i++){
        for (int slot=0;slot<=MX;slot++){
            ans[i] = max(ans[i], 2 * dp[i][slot] + min(2 * slot, (tot - dp[i][slot])));
        }
    }
    for (int i=1;i<=n;i++){
        print(ans[i]);
        cout << ' ';
    }
    cout << el;

    return 0;
}

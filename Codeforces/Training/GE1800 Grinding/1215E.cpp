#pragma gcc optimize("O3")
#pragma gcc optimize("unroll-loops")

#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 4e5 + 10, M = 20;
const ll INF = 1e18;

int n;
int ar[N];
ll cnt[M][M];

ll dp[(1 << M)];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        ar[i]--;
    }
    {
        int acum[M];
        fill(acum, acum + M, 0);
        for (int i=1;i<=n;i++){
            acum[ar[i]]++;
            for (int j=0;j<M;j++){
                if (j != ar[i]){
                    cnt[ar[i]][j] += acum[j];
                }
            }
        }
    }
    fill(dp, dp + (1 << M), INF);
    dp[0] = 0;
    for (int i=0;i<(1 << M) - 1;i++){
        for (int j=0;j<M;j++){
            if (i & (1 << j)) continue;
            int ni = (i | (1 << j));
            ll nx = dp[i];
            for (int k=0;k<M;k++){
                if (i & (1 << k)) continue;
                nx += cnt[j][k];
            }
            dp[ni] = min(dp[ni], nx);
        }
    }
    cout << dp[(1 << M) - 1] << el;

    return 0;
}
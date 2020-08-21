#pragma GCC optimization("O2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MX = (1 << 19), N = 19;

ll dp[MX][N], total[MX]; // mask, last;
ll bitCnt[MX];

int n, m;
vector<int> adj[N];
bool mat[N][N];

void init(int mm){
    for (int i=0;i<mm;i++){
        for (int j=0;j<n;j++){
            dp[i][j] = 0;
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i=0;i<MX;i++){
        bitCnt[i] = __builtin_popcount(i);
    }

    cin >> n >> m;
    for (int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].pb(b);
        adj[b].pb(a);
        mat[a][b] = 1;
        mat[b][a] = 1;
    } 

    for (int i=n - 1;i>=0;i--){
        int mm = (1 << (i + 1));
        init(mm);
        for (int j=0;j<=i - 1;j++){
            if (mat[i][j]){
                int mask = (1 << j);
                dp[mask][j] = 1;
            }
        }

        for (int mask=0;mask<mm;mask++){
            if (mask & (1 << i)){
                total[bitCnt[mask]] += dp[mask][i];
                continue;
            }
            for (int j=0;j<=i;j++){
                if (mask & (1 << j)){
                    for (int k=0;k<=i;k++){
                        if (mask & (1 << k)) continue;
                        if (mat[j][k]) dp[(mask | (1 << k))][k] += dp[mask][j];
                    }
                }
            }
        }
    }
    ll ans = 0;
    for (int i=3;i<=n;i++){
        ans += total[i] / 2LL;
    }
    cout << ans << el;

    return 0;
}
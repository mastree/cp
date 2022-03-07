#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 410;
const ll INF = 1e18;

int n;
ll ar[N][N], pre[N][N];
ll hit(int ra, int ca, int rb, int cb){
    return pre[rb][cb] - pre[ra - 1][cb] - pre[rb][ca - 1] + pre[ra - 1][ca - 1];
}

ll le[N], ri[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        ll cur = 0;
        for (int j=1;j<=n;j++){
            cin >> ar[i][j];
            cur += ar[i][j];
            pre[i][j] = pre[i - 1][j] + cur;
        }
        pre[i][n + 1] = pre[i - 1][n + 1] + cur;
    }
    for (int i=1;i<=n + 1;i++){
        pre[n + 1][i] = pre[n][i];
    }
    ll ans = -INF;
    for (int h1=0;h1<n;h1++){
        for (int h2=h1 + 2;h2<=n + 1;h2++){
            for (int i=1;i<=n;i++){
                le[i] = min(le[i - 1], hit(1, 1, h1, i) + hit(h2, 1, n, i));
            }
            for (int i=n;i>=1;i--){
                ri[i] = min(ri[i + 1], hit(1, i, h1, n) + hit(h2, i, n, n));
            }
            for (int i=1;i<=n;i++){
                ans = max(ans, pre[n][n] - le[i - 1] - ri[i + 1]);
            }
        }
    }
    cout << ans << el;

    return 0;
}
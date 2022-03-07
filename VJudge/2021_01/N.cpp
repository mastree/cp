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
const int INF = 1e9 + 10;

int n, m;
int ar[N][N], pre[N][N];

int hit(int ra, int ca, int rb, int cb){
    return pre[rb][cb] - pre[ra - 1][cb] - pre[rb][ca - 1] + pre[ra - 1][ca - 1];
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=n;i++){
        int cur = 0;
        for (int j=1;j<=m;j++){
            char c;
            cin >> c;
            ar[i][j] = (c == 'B');
            cur += ar[i][j];
            pre[i][j] = pre[i - 1][j] + cur;
        }
    }
    int ans = INF;
    for (int sz=1;sz<=min(n, m);sz++){
        for (int i=1;i + sz - 1<=n;i++){
            for (int j=1;j + sz - 1<=m;j++){
                int temp = hit(i, j, i + sz - 1, j + sz - 1);
                if (temp == pre[n][m]){
                    ans = min(ans, sz * sz - temp);
                }
            }
        }
    }
    if (ans < INF) cout << ans << el;
    else cout << -1 << el;

    return 0;
}
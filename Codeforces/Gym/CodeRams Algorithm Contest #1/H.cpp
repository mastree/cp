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
const int INF = 1e9 + 10;

int n;
int ar[N][N];
int pre[N][N];

int hit(int ra, int ca, int rb, int cb){
    return pre[rb][cb] - pre[ra - 1][cb] - pre[rb][ca - 1] + pre[ra - 1][ca - 1];
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cin >> ar[i][j];
        }
    }
    for (int i=1;i<=n + 1;i++){
        int cur = 0;
        for (int j=1;j<=n + 1;j++){
            cur += ar[i][j];
            pre[i][j] = pre[i - 1][j] + cur;
            // cout << pre[i][j] << ' ';
        }
        // cout << el;
    }
    int ans = -INF;
    for (int h=3;h<=n;h++){
        vector<vector<int>> ri(n + 2, vector<int>(n + 2, -INF));
        for (int i=1;i + h - 1<=n;i++){
            int ni = i + h - 1;
            for (int j=n;j>=1;j--){
                ri[i][j] = max(ri[i][j + 1], hit(i, j, ni, n) - hit(i, j + 1, ni, n) - hit(i, j, i, n) - hit(ni, j, ni, n));
            }
        }
        for (int i=1;i + h - 1<=n;i++){
            int ni = i + h - 1;
            for (int j=1;j + 2<=n;j++){
                int temp = hit(i, j, ni, n) - hit(i + 1, j + 1, ni - 1, n);
                ans = max(ans, temp + ri[i][j + 2]);
            }
        }
    }
    cout << ans << el;

    return 0;
}
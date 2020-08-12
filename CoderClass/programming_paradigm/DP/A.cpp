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
const int INF = 2e9;

int n, m;
int pre[N][N];

int hitung(int xa, int ya, int xb, int yb){
    return pre[xb][yb] - pre[xa - 1][yb] - pre[xb][ya - 1] + pre[xa - 1][ya - 1];
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=n;i++){
        int cur = 0;
        for (int j=1;j<=m;j++){
            int a;
            cin >> a;
            cur += a;
            pre[i][j] = pre[i - 1][j] + cur;
        }
    }
    int ans = -INF;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            for (int ii=i;ii<=n;ii++){
                for (int jj=j;jj<=m;jj++){
                    ans = max(ans, hitung(i, j, ii, jj));
                }
            }
        }
    }
    cout << ans << el;

    return 0;
}
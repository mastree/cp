#pragma gcc optimize ("O3")
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

const int N = 4e3 + 10;
const int K = 8e2 + 10;
const int INF = 1e9;

int n, k;
int mat[N][N];
int dp[K][N];

int hitung(int xa, int ya, int xb, int yb){
    return mat[xb][yb] - mat[xa - 1][yb] - mat[xb][ya - 1] + mat[xa - 1][ya - 1];
}
int cost(int i, int j){
    return hitung(i, i, j, j);
}

void compute(int l, int r, int optl, int optr, int id){
    if (l > r) return;
    int mid = (l + r) / 2;
    pii best = mp(INF + 1, -1);

    for (int kk=optl;kk<=min(mid, optr);kk++){
        best = min(best, mp(dp[id - 1][kk - 1] + cost(kk, mid), kk));
    }
    dp[id][mid] = best.fi;
    int opt = best.se;
    compute(l, mid - 1, optl, opt, id);
    compute(mid + 1, r, opt, optr, id);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i=1;i<=n;i++){
        int tot = 0;
        for (int j=1;j<=n;j++){
            char c;
            cin >> c;
            tot += (int)(c - '0');
            mat[i][j] = mat[i - 1][j] + tot;
        }
    }
    for (int i=0;i<=k;i++){
        for (int j=0;j<=n;j++){
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;
    for (int i=1;i<=k;i++) compute(1, n, 1, n, i);
    cout << dp[k][n] / 2 << el;

    return 0;
}
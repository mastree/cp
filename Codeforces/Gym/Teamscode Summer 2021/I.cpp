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
const int INF = 1e9 + 10;

int n, m, q;
int ar[N][N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> q;
    for (int i=1;i<=m;i++){
        ar[0][i] = INF;
    }
    for (int i=1;i<=n;i++){
        int cur = INF;
        for (int j=1;j<=m;j++){
            cin >> ar[i][j];
            cur = min(cur, ar[i][j]);
            ar[i][j] = min(ar[i - 1][j], cur);
        }
    }
    while (q--){
        int r, c;
        cin >> r >> c;
        cout << ar[r][c] << el;
    }

    return 0;
}
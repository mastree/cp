#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 110, B = 101;

int n, m;
int ar[N][N];
int r[N], c[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("lucky.in", "r", stdin);
    freopen("lucky.out", "w", stdout);

    cin >> n >> m;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cin >> ar[i][j];
        }
    }

    int cnt = 0;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (ar[i][j] > c[j]) cnt++;
            if (ar[i][j] > r[i]) cnt++;
            int mx = 0;
            for (int k=i + 1;k<=n;k++){
                mx = max(mx, ar[k][j]);
            }
            if (ar[i][j] > mx) cnt++;
            mx = 0;
            for (int k=j + 1;k<=m;k++){
                mx = max(mx, ar[i][k]);
            }
            if (ar[i][j] > mx) cnt++;
            c[j] = max(c[j], ar[i][j]);
            r[i] = max(r[i], ar[i][j]);
        }
    }
    cout << cnt << el;

    return 0;
}
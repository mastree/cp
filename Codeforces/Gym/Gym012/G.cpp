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

const int N = 510;
const int INF = 1e9 + 10;

int q;
int n, m;
int ar[N][N];

int uple[N][N], upri[N][N], dle[N][N], dri[N][N];

void init(){
    for (int i=0;i<n + 3;i++){
        for (int j=0;j<m + 3;j++){
            uple[i][j] = 0;
            upri[i][j] = 0;
            dle[i][j] = 0;
            dri[i][j] = 0;
            ar[i][j] = 0;
        }
    }
}

void solve(){
    cin >> n >> m;
    init();
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cin >> ar[i][j];
        }
    }
    // uple
    for (int i=1;i<=n;i++){
        int cur = 0;
        for (int j=1;j<=m;j++){
            cur = max(cur, ar[i][j]);
            uple[i + 1][j + 1] = max(uple[i][j + 1], cur);
        }
    }
    // upri
    for (int i=1;i<=n;i++){
        int cur = 0;
        for (int j=m;j>=1;j--){
            cur = max(cur, ar[i][j]);
            upri[i + 1][j - 1] = max(upri[i][j - 1], cur);
        }
    }
    // dle
    for (int i=n;i>=1;i--){
        int cur = 0;
        for (int j=1;j<=m;j++){
            cur = max(cur, ar[i][j]);
            dle[i - 1][j + 1] = max(dle[i][j + 1], cur);
        }
    }
    // dri
    for (int i=n;i>=1;i--){
        int cur = 0;
        for (int j=m;j>=1;j--){
            cur = max(cur, ar[i][j]);
            dri[i - 1][j - 1] = max(dri[i][j - 1], cur);
        }
    }
    int ans = INF;
    for (int i=2;i<n;i++){
        for (int j=2;j<m;j++){
            vector<int> v{uple[i][j], upri[i][j], dle[i][j], dri[i][j]};
            sort(v.begin(), v.end());
            ans = min(ans, v.back() - v[0]);
        }
    }
    cout << ans << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        solve();
    }

    return 0;
}
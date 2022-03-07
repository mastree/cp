#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e5 + 10;
const int INF = 2e9 + 10;

int q;
int n;
int ar[3][N];

void solve(){
    cin >> n;
    for (int i=1;i<=2;i++){
        for (int j=1;j<=n;j++){
            cin >> ar[i][j];
        }
        ar[i][n + 1] = 0;
    }
    if (n == 1){
        cout << 0 << el;
        return;
    }
    for (int i=1;i<=n;i++){
        ar[2][i] += ar[2][i - 1];
    }
    for (int j=n;j>=1;j--){
        ar[1][j] += ar[1][j + 1];
    }
    int ans = INF;
    for (int i=0;i<n;i++){
        ans = min(ans, max(ar[2][i], ar[1][i + 2]));
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
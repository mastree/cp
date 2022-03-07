#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e6 + 10;

int q;
int n, m, k;

void solve(){
    cin >> n >> m >> k;
    vector<vector<int>> mat(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> up(n + 2, vector<int>(m + 1, 0));
    vector<vector<int>> down(n + 2, vector<int>(m + 1, 0));
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            char c;
            cin >> c;
            mat[i][j] = c == 'X';
            up[i][j] = up[i - 1][j] + mat[i][j];
        }
    }
    for (int i=n;i>=1;i--){
        for (int j=1;j<=m;j++){
            down[i][j] = down[i + 1][j] + mat[i][j];
        }
    }
    int ans = m;
    for (int umove=0;umove<n;umove++){
        int upcur = umove;
        int downcur = umove;
        for (int j=1;j<=m;j++){
            // up
            if ((k + umove <= n && mat[k + umove][j]) || up[min(k + umove, n)][j] >= k) upcur++;
            
            // down
            if ((k - umove >= 1 && mat[k - umove][j]) || down[max(k - umove, 1)][j] >= (n - k + 1)) downcur++;
        }
        ans = min(ans, min(upcur, downcur));
    }
    cout << ans << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    for (int i=1;i<=q;i++){
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}
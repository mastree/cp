#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 310;

int q;
int n, m;
int ar[N][N], ans[N][N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n >> m;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                cin >> ar[i][j];
                if (i == 1 || i == n){
                    if (j == 1 || j == m){
                        ans[i][j] = 2;
                    } else{
                        ans[i][j] = 3;
                    }
                } else if (j == 1 || j == m){
                    ans[i][j] = 3;
                } else{
                    ans[i][j] = 4;
                }
            }
        }
        bool ok = 1;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                if (ar[i][j] > ans[i][j]){
                    ok = 0;
                    break;
                }
            }
            if (!ok) break;
        }
        if (!ok){
            cout << "NO" << el;
            continue;
        }
        cout << "YES" << el;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                cout << ans[i][j] << " ";
            }
            cout << el;
        }
    }

    return 0;
}
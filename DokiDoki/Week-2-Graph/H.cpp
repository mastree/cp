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
const int INF = 1e9;

int n;
int mat[N][N];
bool udh[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cin >> mat[i][j];
        }
    }
    vector<int> urut;
    for (int i=1;i<=n;i++){
        int a;
        cin >> a;
        urut.pb(a);
    }
    reverse(urut.begin(), urut.end());
    vector<ll> ans;
    for (auto k : urut){
        udh[k] = 1;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
            }
        }
        ll tot = 0;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                if (udh[i] && udh[j]) tot += mat[i][j];
            }
        }
        ans.pb(tot);
    }
    reverse(ans.begin(), ans.end());
    for (int i=0;i<n;i++){
        cout << ans[i];
        if (i != n - 1) cout << ' ';
    }
    cout << el;

    return 0;
}
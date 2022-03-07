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

const int N = 2e3 + 10;
const ll INF = 1e18;
const ll BAT = 1e14;

int q;
ll dple[N][N], dpri[N][N];
bool bisale[N][N], bisari[N][N];

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> ar(n + 1), br(m + 1), cost(n + 1);
    bool ok = 1;
    {
        vector<int> ada;
        for (int i=1;i<=n;i++){
            cin >> ar[i];
            ada.pb(ar[i]);
        }
        for (int i=1;i<=m;i++){
            cin >> br[i];
            ada.pb(br[i]);
        }
        sort(ada.begin(), ada.end());
        ada.resize(unique(ada.begin(), ada.end()) - ada.begin());
        if (ada.size() > n) ok = 0;

        unordered_map<int, int> hehe;
        int cnt = 1;
        for (auto& x : ada){
            hehe[x] = cnt++;
        }
        for (auto& x : ar) x = hehe[x];
        for (auto& x : br) x = hehe[x];
    }
    for (int i=1;i<=n;i++){
        cin >> cost[i];
    }
    if (!ok){
        cout << "No" << el;
        return;
    }
    // vector<vector<ll>> dple(m + 2, vector<ll>(n + 2, INF));
    // vector<vector<ll>> dpri(m + 2, vector<ll>(n + 2, INF));
    // vector<vector<bool>> bisale(m + 2, vector<bool>(n + 2, 1));
    // vector<vector<bool>> bisari(m + 2, vector<bool>(n + 2, 1));
    for (int i=0;i<m + 2;i++){
        for (int j=0;j<n + 2;j++){
            dple[i][j] = dpri[i][j] = INF;
        }
    }
    for (int i=0;i<m + 2;i++){
        for (int j=0;j<n + 2;j++){
            bisale[i][j] = bisari[i][j] = 1;
        }
    }
    {
        for (int i=1;i<=m;i++){
            // bisale[i] = bisale[i - 1];
            for (int j=0;j<n + 2;j++) bisale[i][j] = bisale[i - 1][j];
            // if (i > 1){
            bisale[i][br[i]] = 0;
            // }
        }
        for (int i=m;i>=1;i--){
            // bisari[i] = bisari[i + 1];
            for (int j=0;j<n + 2;j++) bisari[i][j] = bisari[i + 1][j];
            // if (i < m){
            bisari[i][br[i]] = 0;
            // }
        }
    }
    {
        dple[0][0] = 0;
        for (int i=0;i<=m;i++){
            for (int j=1;j<=n;j++){
                // hapus
                if (bisale[i][ar[j]]){
                    dple[i][j] = min(dple[i][j], dple[i][j - 1] + cost[j]);
                }
                // pake
                if (i > 0 && br[i] == ar[j]){
                    dple[i][j] = min(dple[i][j], dple[i - 1][j - 1]);
                }
            }
        }
    }
    {
        dpri[m + 1][n + 1] = 0;
        for (int i=m + 1;i>=1;i--){
            for (int j=n;j>=1;j--){
                // hapus
                if (bisari[i][ar[j]]){
                    dpri[i][j] = min(dpri[i][j], dpri[i][j + 1] + cost[j]);
                }
                // pake
                if (i <= m && br[i] == ar[j]){
                    dpri[i][j] = min(dpri[i][j], dpri[i + 1][j + 1]);
                }
            }
        }
    }
    ll ans = INF;
    for (int i=0;i<=m;i++){
        for (int j=0;j<=n;j++){
            ans = min(ans, dple[i][j] + dpri[i + 1][j + 1]);
        }
    }
    if (ans >= BAT){
        cout << "No" << el;
    } else{
        cout << ans << el;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    freopen("transform.in", "r", stdin);

    cin >> q;
    while (q--){
        solve();
    }

    return 0;
}
#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 5e5 + 10;
const int INF = 1e9;

int n, m;
// 0 morning, 1 night, 2 both
vector<pii> adj[N]; // reverse

int dp[N];
int ans[N];

void solve(){
    fill(dp, dp + n + 2, INF);
    fill(ans, ans + n + 2, -1);

    set<pii> setdah;
    dp[n] = 0;
    setdah.insert(mp(0, n));
    while (!setdah.empty()){
        auto tp = *setdah.begin();
        setdah.erase(tp);
        int cur = tp.fi;
        int node = tp.se;
        for (auto x : adj[node]){
            if (ans[x.fi] != -1){
                if (x.se == 2 && dp[x.fi] > cur + 1){
                    setdah.erase(mp(dp[x.fi], x.fi));
                    dp[x.fi] = cur + 1;
                    setdah.insert(mp(dp[x.fi], x.fi));
                } else if (ans[x.fi] == x.se && dp[x.fi] > cur + 1){
                    setdah.erase(mp(dp[x.fi], x.fi));
                    dp[x.fi] = cur + 1;
                    setdah.insert(mp(dp[x.fi], x.fi));
                }
                continue;
            }
            if (x.se == 0){
                ans[x.fi] = 1;
            } else if (x.se == 1){
                ans[x.fi] = 0;
            } else{
                ans[x.fi] = 0;
                if (dp[x.fi] > cur + 1){
                    setdah.erase(mp(dp[x.fi], x.fi));
                    dp[x.fi] = cur + 1;
                    setdah.insert(mp(dp[x.fi], x.fi));
                }
            }
        }
    }
    for (int i=1;i<=n;i++){
        if (ans[i] == -1) ans[i] = 0;
    }
    if (dp[1] == INF) cout << -1 << el;
    else cout << dp[1] << el;
    for (int i=1;i<=n;i++){
        cout << ans[i];
    }
    cout << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    {
        set<pair<pii, int>> setdah;
        for (int i=1;i<=m;i++){
            int a, b;
            int tipe;
            cin >> a >> b >> tipe;
            if (a == b) continue;
            setdah.insert(mp(mp(a, b), tipe));
        }
        pii bef = mp(-1, -1);
        map<pii, int> cek;
        for (auto x : setdah){
            int a = x.fi.fi;
            int b = x.fi.se;
            int t = x.se;

            if (bef != mp(-1, -1) && bef != mp(a, b)){
                adj[bef.se].pb(mp(bef.fi, cek[bef] - 1));
            }
            cek[mp(a, b)] += t + 1;
            bef = mp(a, b);
        }
        if (bef != mp(-1, -1)){
            adj[bef.se].pb(mp(bef.fi, cek[bef] - 1));
        }
    }
    solve();

    return 0;
}
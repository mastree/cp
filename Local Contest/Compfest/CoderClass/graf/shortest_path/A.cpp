#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pil = pair<int, ll>;

const int N = 1e5 + 10;
const ll INF = 1e18;

int n, m;
vector<pil> adj[N];
ll dp[N];
set<pli> setdah;

void solve(){
    fill(dp, dp + n + 2, INF);
    dp[1] = 0;
    setdah.insert(mp(dp[1], 1));
    while (!setdah.empty()){
        auto tp = *setdah.begin();
        setdah.erase(tp);
        int node = tp.se;
        ll cur = tp.fi;
        for (auto x : adj[node]){
            if (dp[x.fi] > cur + x.se){
                setdah.erase(mp(dp[x.fi], x.fi));
                dp[x.fi] = cur + x.se;
                setdah.insert(mp(dp[x.fi], x.fi));
            }
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=m;i++){
        int a, b;
        ll w;
        cin >> a >> b >> w;
        adj[a].pb(mp(b, w));
        adj[b].pb(mp(a, w));
    }
    solve();
    cout << dp[n] << el;

    return 0;
}
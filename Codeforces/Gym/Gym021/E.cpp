#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;

const int N = 1e4 + 10;
const int INF = 1e9 + 10;

int n, m, k;
vector<int> path;
vector<pil> adj[N];

ll dp[N];

bool init(){
    fill(dp, dp + n + 2, INF);
    dp[1] = 0;
    set<pair<ll, int>> setdah;
    setdah.insert(mp(0LL, 1));
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
    for (int i=1;i<k;i++){
        int node = path[i];
        int par = path[i - 1];

        int cnt = 0;
        for (auto x : adj[node]){
            if (x.fi != par){
                if (dp[node] == dp[x.fi] + x.se) return 1;
            } else if (dp[node] == dp[x.fi] + x.se) cnt++;
        }
        if (cnt > 1) return 1;
    }
    return 0;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    for (int i=1;i<=k;i++){
        int a;
        cin >> a;
        path.pb(a);
    }
    for (int i=1;i<=m;i++){
        int a, b;
        ll c;
        cin >> a >> b >> c;
        adj[a].pb(mp(b, c));
        adj[b].pb(mp(a, c));
    }
    bool ok = init();
    if (ok) cout << "yes" << el;
    else cout << "no" << el;

    return 0;
}
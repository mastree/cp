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
using pli = pair<ll, int>;

const int N = 1e5 + 10;
const int INF = 1e9 + 100;
const ll MOD = 1e9 + 7;

int n, m;
vector<pii> adj[N];
int dp[N];

void dijkstra(){
    fill(dp, dp + n + 2, INF);
    dp[1] = 0;
    set<pii> setdah;
    setdah.insert(mp(dp[1], 1));
    while (!setdah.empty()){
        auto tp = *setdah.begin();
        setdah.erase(tp);
        int cur = tp.fi;
        int node = tp.se;
        for (auto x : adj[node]){
            if (dp[x.fi] > cur + x.se){
                setdah.erase(mp(dp[x.fi], x.fi));
                dp[x.fi] = cur + x.se;
                setdah.insert(mp(dp[x.fi], x.fi));
            }
        }
    }
}
bool bisa[N];
int in[N];
void dfs_bisa(int node){
    for (auto x : adj[node]){
        if (dp[node] == dp[x.fi] + x.se){
            if (!bisa[x.fi]) dfs_bisa(x.fi);
            bisa[x.fi] = 1;
            in[x.fi]++;
        }
    }
}
ll cnt[N];
void solve(int node){
    for (auto x : adj[node]){
        if (dp[node] == dp[x.fi] + x.se){
            cnt[x.fi] = (cnt[x.fi] + cnt[node]) % MOD;
            if (--in[x.fi] == 0 && x.fi != 1){
                solve(x.fi);
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
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].pb(mp(b, c));
        adj[b].pb(mp(a, c));
    }
    dijkstra();
    bisa[n] = 1;
    bisa[1] = 1;
    dfs_bisa(n);
    cnt[n] = 1;
    solve(n);
    cout << cnt[1] << el;

    return 0;
}
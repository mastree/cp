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
const int M = 5e4 + 10;
const int INF = 1e9;

int q;
int n, m, t;
// int s, g, h; // start, intersection passed
vector<int> need;
vector<vector<pii>> adj;
vector<int> target;
vector<int> dp[3];

void dijkstra(int id){
    dp[id].clear();
    dp[id].resize(n + 1, INF);
    dp[id][need[id]] = 0;
    set<pii> setdah;
    setdah.insert(mp(0, need[id]));
    while (!setdah.empty()){
        auto temp = *setdah.begin();
        setdah.erase(temp);
        int cur = temp.fi;
        int node = temp.se;
        for (auto &x : adj[node]){
            if (cur + x.se < dp[id][x.fi]){
                setdah.erase(mp(dp[id][x.fi], x.fi));
                dp[id][x.fi] = cur + x.se;
                setdah.insert(mp(dp[id][x.fi], x.fi));
            }
        }
    }
}

void solve(){
    cin >> n >> m >> t;
    // cin >> s >> g >> h;
    need.clear();
    for (int i=0;i<3;i++){
        int a;
        cin >> a;
        need.pb(a);
    }
    adj.clear();
    adj.resize(n + 1, vector<pii>());
    int mn = INF;
    for (int i=1;i<=m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].pb(mp(b, c));
        adj[b].pb(mp(a, c));
        if (mp(a, b) == mp(need[1], need[2]) || mp(b, a) == mp(need[1], need[2])) mn = min(mn, c);
    }
    target.clear();
    for (int i=1;i<=t;i++){
        int a;
        cin >> a;
        target.pb(a);
    }
    sort(target.begin(), target.end());
    for (int i=0;i<3;i++){
        dijkstra(i);
    }
    for (auto &x : target){
        bool bisa = 0;
        if ((dp[0][need[1]] + dp[2][x] + mn == dp[0][x] || dp[0][need[2]] + dp[1][x] + mn == dp[0][x]) && dp[0][x] != INF){
            cout << x << ' ';
        }
    }
    cout << el;
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
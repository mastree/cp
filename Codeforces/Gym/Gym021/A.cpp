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

const int N = 2e4 + 10, P = 17;
const ll INF = 1e18;

int n, p, m, taxi;
ll g;
vector<int> sites; 
vector<pil> adj[N];

ll dist[P][N]; // source, dest

void dijkstra(int id){
    int sc = sites[id];
    fill(dist[id], dist[id] + n + 2, INF);
    dist[id][sc] = 0;
    set<pii> setdah;
    setdah.insert(mp(0, sc));
    while (!setdah.empty()){
        auto tp = *setdah.begin();
        setdah.erase(tp);
        int node = tp.se;
        ll cur = tp.fi;
        for (auto x : adj[node]){
            if (dist[id][x.fi] > cur + x.se){
                setdah.erase(mp(dist[id][x.fi], x.fi));
                dist[id][x.fi] = cur + x.se;
                setdah.insert(mp(dist[id][x.fi], x.fi));
            }
        }
    }
}
ll dp[(1 << P)][P][2];
void solve(){
    for (int i=0;i<(1 << p);i++){
        for (int j=0;j<P;j++){
            dp[i][j][0] = dp[i][j][1] = INF;
        }
    }
    dp[0][0][0] = 0;
    for (int i=0;i<(1 << p);i++){
        for (int j=0;j<p;j++){
            int node = sites[j];
            if (dp[i][j][0] != INF){
                for (int k=0;k<p;k++){
                    if (i & (1 << k)) continue;
                    int nnode = sites[k];
                    int nmask = (i | (1 << k));
                    dp[nmask][k][0] = min(dp[nmask][k][0], dp[i][j][0] + dist[j][nnode]);
                    dp[nmask][k][1] = min(dp[nmask][k][1], dp[i][j][0] + taxi);
                }
            } 
            if (dp[i][j][1] != INF){
                for (int k=0;k<p;k++){
                    if (i & (1 << k)) continue;
                    int nnode = sites[k];
                    int nmask = (i | (1 << k));
                    dp[nmask][k][1] = min(dp[nmask][k][1], dp[i][j][1] + dist[j][nnode]);
                }
            }
        }
    }
    int lmask = (1 << p) - 1;
    if (dp[lmask][0][0] <= g){
        cout << "possible without taxi" << el;
    } else if (dp[lmask][0][1] <= g){
        cout << "possible with taxi" << el;
    } else{
        cout << "impossible" << el;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> p >> m >> g >> taxi;
    bool ada0 = 0;
    for (int i=1;i<=p;i++){
        int a, b;
        cin >> a >> b;
        if (a == 0){
            ada0 = 1;
        }
        sites.pb(a);
        g -= b;
    }
    if (g < 0){
        cout << "impossible" << el;
        return 0;
    }
    if (!ada0){
        sites.pb(0);
        p++;
    }
    sort(sites.begin(), sites.end());
    for (int i=1;i<=m;i++){
        int a, b;
        ll c;
        cin >> a >> b >> c;
        adj[a].pb(mp(b, c));
        adj[b].pb(mp(a, c));
    }
    for (int i=0;i<p;i++){
        dijkstra(i);
    }
    solve();

    return 0;
}
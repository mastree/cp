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
using pll = pair<ll, ll>;

const int N = 2e5 + 10;
const ll INF = 1e18;

struct Edge{
    int p;
    int t;
    int aid; // posisi di adj
    int bid; // posisi di adj

    Edge(){}
    Edge(int p, int t, int aid, int bid) : p(p), t(t), aid(aid), bid(bid) {}
};

int n, m;
vector<pii> adj[N]; // dest, edge id
vector<Edge> edges; // color, weight

vector<ll> naik[N], turun[N];

int getid(int node, int edgeid){
    Edge temp = edges[edgeid];
    if (adj[node].size() <= temp.aid) return temp.bid;
    if (adj[node][temp.aid].se == edgeid) return temp.aid;
    return temp.bid;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    {
        int a = 1, b = 1;
        int p = 1, t = 0;
        edges.emplace_back(p, t, 0, 0);
        adj[a].emplace_back(b, 0);
    }
    {
        int a = n, b = n;
        int p = 1, t = 0;
        edges.emplace_back(p, t, 0, 0);
        adj[a].emplace_back(b, 1);
    }
    for (int i=2;i<=m + 1;i++){
        int a, b;
        int p, t;
        cin >> a >> b >> p >> t;
        edges.emplace_back(p, t, adj[a].size(), adj[b].size());
        adj[a].emplace_back(b, i);
        adj[b].emplace_back(a, i);
    } 
    auto comp = [&](const pii& a, const pii& b) -> bool {
        return edges[a.se].p < edges[b.se].p;
    };
    for (int i=1;i<=n;i++){
        sort(adj[i].begin(), adj[i].end(), comp);
        int len = adj[i].size();
        for (int j=0;j<len;j++){
            int id = adj[i][j].se;
            if (i <= adj[i][j].fi){
                edges[id].aid = j;
            }
            if (i >= adj[i][j].fi){
                edges[id].bid = j;
            }
        }
    }
    // node, adj id = dist
    // naik -> turun = + 2 color
    // turun -> naik = - 2 color
    for (int i=1;i<=n;i++){
        naik[i].assign(adj[i].size(), INF);
        turun[i].assign(adj[i].size(), INF);
    }
    set<pair<ll, pii>> snaik, sturun;
    naik[1][0] = -1;
    turun[1][0] = 1;
    snaik.insert(mp(-2, mp(1, 0)));
    sturun.insert(mp(2, mp(1, 0)));

    while (!snaik.empty() && !sturun.empty()){
        if (!snaik.empty()){
            auto temp = *snaik.begin();
            snaik.erase(temp);
            ll cur = temp.fi;
            int node = temp.se.fi;
            int adjid = temp.se.se;
            int id = adj[node][adjid].se;
 
            int i = lower_bound(adj[node].begin(), adj[node].end(), mp(-1, id), comp) - adj[node].begin();
            int len = adj[node].size();
            for (;i<len;i++){
                auto x = adj[node][i];
                if (x.se == id) continue;
                ll ndist = cur + edges[x.se].t;
                int nid = getid(x.fi, x.se);
                if (naik[x.fi][nid] > ndist){
                    snaik.erase(mp(naik[x.fi][nid], mp(x.fi, nid)));
                    naik[x.fi][nid] = ndist;
                    snaik.insert(mp(naik[x.fi][nid], mp(x.fi, nid)));
                } else break;
                ndist += 2LL * edges[x.se].p;
                if (turun[x.fi][nid] > ndist){
                    sturun.erase(mp(turun[x.fi][nid], mp(x.fi, nid)));
                    turun[x.fi][nid] = ndist;
                    sturun.insert(mp(turun[x.fi][nid], mp(x.fi, nid)));
                }
            }
        }
        if (!sturun.empty()){
            auto temp = *sturun.begin();
            sturun.erase(temp);
            ll cur = temp.fi;
            int node = temp.se.fi;
            int adjid = temp.se.se;
            int id = adj[node][adjid].se;
            
            int i = lower_bound(adj[node].begin(), adj[node].end(), mp(-1, id), comp) - adj[node].begin() - 1;
            for (;i>=0;i--){
                auto x = adj[node][i];
                if (x.se == id) continue;
                ll ndist = cur + edges[x.se].t;
                int nid = getid(x.fi, x.se);
                if (turun[x.fi][nid] > ndist){
                    sturun.erase(mp(turun[x.fi][nid], mp(x.fi, nid)));
                    turun[x.fi][nid] = ndist;
                    sturun.insert(mp(turun[x.fi][nid], mp(x.fi, nid)));
                } else break;
                ndist -= 2LL * edges[x.se].p;
                if (naik[x.fi][nid] > ndist){
                    snaik.erase(mp(naik[x.fi][nid], mp(x.fi, nid)));
                    naik[x.fi][nid] = ndist;
                    snaik.insert(mp(naik[x.fi][nid], mp(x.fi, nid)));
                }
            }
        }
    }
    cout << turun[n][0] << el;
    
    return 0;
}
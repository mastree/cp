#include <bits/stdc++.h>

#define fi first
#define se second
#define mp(a, b) make_pair(a, b)

using namespace std;
using pii = pair<int, int>;
using ll = long long;

const int N = 2e5 + 10;
const ll INF = 1e18;

int n, m;
vector<pii> adj[N];
ll dist[N][2][2];

void solve(){
    for (int i=0;i<N;i++){
        for (int j=0;j<2;j++){
            for (int k=0;k<2;k++){
                dist[i][j][k] = INF;
            }
        }
    }
    dist[1][0][0] = 0;
    set<pair<ll, pii>> setdah; // dist, node, bit-double bit-skip
    setdah.insert(mp(0, mp(1, (0 << 1) + 0)));
    while (!setdah.empty()){
        auto tp = *setdah.begin();
        setdah.erase(tp);
        ll cur = tp.fi;
        int node = tp.se.fi;
        int bd = (tp.se.se >= 2);
        int bs = (tp.se.se & 1);
        // cout << node << " " << bd << " " << bs << " " << cur << '\n';
        for (auto& x : adj[node]){
            for (int i=bd;i<2;i++){
                for (int j=bs;j<2;j++){
                    ll ncur = cur + x.se;
                    if (i != bd){
                        ncur += x.se;
                    }
                    if (j != bs){
                        ncur -= x.se;
                    }
                    if (dist[x.fi][i][j] > ncur){
                        setdah.erase(mp(dist[x.fi][i][j], mp(x.fi, (i << 1) + j)));
                        dist[x.fi][i][j] = ncur;
                        setdah.insert(mp(dist[x.fi][i][j], mp(x.fi, (i << 1) + j)));
                    }
                }
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i=1;i<=m;i++){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].emplace_back(b, w);
        adj[b].emplace_back(a, w);
    }
    solve();
    for (int i=2;i<=n;i++){
        cout << dist[i][1][1] << ' ';
    }
    cout << '\n';
    return 0;
}

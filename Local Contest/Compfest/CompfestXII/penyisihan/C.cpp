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

const int N = 110;
const ll INF = 1e18;

int n, m;
set<pli> adj[N], adj2[N];

ll dist[N][N];

void init(){
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            dist[i][j] = INF;
            if (i == j) dist[i][j] = 0;
        }
    }
    for (int i=1;i<=n;i++){
        for (auto x : adj[i]){
            dist[i][x.se] = min(dist[i][x.se], x.fi);
        }
    }
    for (int k=1;k<=n;k++){
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                if (dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]); 
            }
        }
    }
}
void init2(){
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            dist[i][j] = INF;
            if (i == j) dist[i][j] = 0;
        }
    }
    for (int i=1;i<=n;i++){
        for (auto x : adj2[i]){
            dist[i][x.se] = min(dist[i][x.se], x.fi);
        }
    }
    for (int k=1;k<=n;k++){
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                if (dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]); 
            }
        }
    }
}
bool valid(){
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if (dist[i][j] == INF) return 0;
        }
    }
    return 1;
}

ll tot = 0, tot2 = 0;
vector<int> ans, ans2;
void solve(){
    int udah = 0;
    int node = 1;
    ans.pb(cur);
    while (udah < m && node != 1){
        if (adj[node].empty()){
            for ()
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
        adj[a].insert(mp(w, b));
        if (i == 1){
            adj2[b].insert(mp(w, a));
        } else adj2[a].insert(mp(w, b));
    }
    init();
    if (valid()){
        
    }
    init2();
    if (valid()){

    }

    return 0;
}
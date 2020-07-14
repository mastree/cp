#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 300;

int q;
int n, m;
vector<pii> edges;
vector<int> comp[N];
set<pii> adj[N];
unordered_map<int, int> cek[N];

int par[N], sz[N], deg[N];

int find(int a){
    return (par[a] == a ? a : par[a] = find(par[a]));
}
void make(int a, int b){
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
}
void init(){
    edges.clear();
    for (int i=1;i<=n;i++){
        comp[i].clear();
        adj[i].clear();
        cek[i].clear();
        par[i] = i;
        sz[i] = 1;
        deg[i] = 0;
    }
}

vector<int> path;
void prep(int id){
    path.clear();
    vector<int> od;
    for (auto x : comp[id]){
        if (deg[x] & 1) od.pb(x);
    }
    int len = od.size();
    for (int i=0;i<len - 1;i+=2){
        int u = od[i], v = od[i + 1];
        adj[u].insert(mp(v, 2)); // fake edge
        adj[v].insert(mp(u, 2));
    }
}

void dfs_euler(int node){
    if (adj[node].empty()){
        path.pb(node);
        return;
    }
    while (!adj[node].empty()){
        pii temp = *adj[node].begin();
        int dest = temp.fi;
        adj[node].erase(temp);
        adj[dest].erase(mp(node, temp.se));
        dfs_euler(dest);
    }
    path.pb(node);
}

void solve(int id){
    dfs_euler(comp[id][0]);
    int len = path.size();
    for (int i=0;i<len - 1;i++){
        int u = path[i], v = path[i + 1];
        cek[u][v] = 1;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n >> m;
        init();
        int cntans = 0;
        for (int i=1;i<=m;i++){
            int a, b;
            cin >> a >> b;
            adj[a].insert(mp(b, 1));
            adj[b].insert(mp(a, 1));
            edges.emplace_back(a, b);
            deg[a]++;
            deg[b]++;
            make(a, b);
        }
        for (int i=1;i<=n;i++){
            comp[find(i)].pb(i);
            if (deg[i] & 1 ^ 1) cntans++;
        }
        for (int i=1;i<=n;i++){
            if (par[i] == i){
                prep(i);
                solve(i);
            }
        }
        cout << cntans << el;
        for (auto x : edges){
            if (cek[x.fi][x.se]) cout << x.fi << " " << x.se << el;
            else cout << x.se << " " << x.fi << el;
        }
    }

    return 0;
}
#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'

using namespace std;

const int N = 4e5 + 10;

int n, m;
vector<int> adl[N];
vector<pii> edges;
unordered_map<int, bool> mark[N];

int par[N], sz[N];
int parent[N], color[N];

void init(){
    for (int i=1;i<=n;i++){
        par[i] = i;
        sz[i] = 1;
    }
}

int find(int a){
    if (par[a] == a) return a;
    return par[a] = find(par[a]);
}
void make(int a, int b){
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
}

void dfs_scc(int node, int p){
    if (color[node] == 2) return;
    // cout << p << " => " << node << el;
    if (color[node]){
        int cur = p;
        make(node, p);
        while (find(cur) != find(parent[cur])){
            make(cur, parent[cur]);
            cur = parent[cur];
        }
        return;
    }
    parent[node] = p;
    color[node] = 1;
    for (auto x : adl[node]){
        if (x == p) continue;
        dfs_scc(x, node);
    }
    color[node] = 2;
}

bool vis[N];
void dfs_edge(int node, int comp){
    if (vis[node]) return;
    vis[node] = 1;
    for (auto x : adl[node]){
        if (find(x) != comp || mark[x][node]) continue;
        mark[node][x] = 1;
        dfs_edge(x, comp);
    }
}
void dfs_center(int node){
    vis[node] = 1;
    for (auto x : adl[node]){
        if (vis[x]) continue;
        if (find(node) != find(x)){
            mark[x][node] = 1;
        }
        dfs_center(x);
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        adl[a].pb(b);
        adl[b].pb(a);
        edges.pb(mp(a, b));
    }
    init();
    dfs_scc(1, 1);
    for (int i=1;i<=n;i++){
        if (par[i] == i){
            dfs_edge(i, i);
        }
    }
    int ans = 0, id;
    for (int i=1;i<=n;i++){
        if (par[i] == i){
            if (ans < sz[i]){
                ans = sz[i];
                id = i;
            }
        }
    }
    fill(vis, vis + n + 2, 0);
    dfs_center(id);
    cout << ans << el;
    for (auto x : edges){
        int a = x.fi, b = x.se;
        if (mark[a][b]) cout << a << " " << b << el;
        else cout << b << " " << a << el;
    }

    return 0;
}
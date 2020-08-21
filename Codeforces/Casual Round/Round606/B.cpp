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

const int N = 1e5 + 4;

int n,m,a,b,q;
vector <int> adl[2*N];

int par[N*2], sz[N*2], parent[N*2], color[N*2];
bool path[N*2];

int find(int a){
    if (par[a] == a) return a;
    return par[a] = find(par[a]);
}

void make(int a,int b){
    a = par[a];
    b = par[b];
    if (a==b) return;
    if (sz[a]<sz[b]) swap(a,b);
    par[b]=a;
    sz[a]+=sz[b];
}

void dfs_sc(int node, int p){
    if (color[node]==2) return;

    parent[node] = p;
    if (color[node]==1){
        int cur = node;
        // parent[node] = p;
        while (find(cur)!=find(parent[cur])){
            make(cur, parent[cur]);
            cur = parent[cur];
        }
        return;
    }
    // cout << node << " " << p << el;

    color[node] = 1;
    for (auto adj : adl[node]){
        if (adj != p) dfs_sc(adj, node);
    }
    color[node] = 2;
}

bool vis[N*2];
void dfs_path(int node, int p){
    cout << node << el;
    parent[node]=p;
    if (path[node]){
        int cur = p;
        while (!path[cur]){
            path[cur]=1;
            cur = parent[cur]; 
        }
        // path[a]=1;
    } 
    if (vis[node]) return;
    
    if (!vis[node]){
        for (auto x : adl[node]){
            if (x != p && x != a) dfs_path(x, node);
        }
    }
    vis[node]=1;
}

ll res;
void dfs_sol(int node){
    if (vis[node]) return;
    res++;
    vis[node]=1;
    for (auto x : adl[node]){
        if (vis[x] || path[x]) continue;
        dfs_sol(x);
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;

    while (q--){
        cin >> n >> m >> a >> b;
        for (int i=1;i<=n;i++){
            adl[i].clear();
            adl[i].shrink_to_fit();
        }
        // setup
        for (int i=1;i<=n;i++){
            color[i]=0;
            par[i]=i;
            sz[i]=1;
            parent[i]=i;
            path[i]=0;
            vis[i]=0;
        }

        for (int i=0;i<m;i++){
            int a, b;
            cin >> a >> b;
            adl[a].pb(b);
            adl[b].pb(a);
        }


        dfs_sc(1, 0);
        // if (find(a) != find(b)){
        path[a]=1;
        path[b]=1;
        dfs_path(a,a);
        for (int i=1;i<=n;i++) vis[i]=0;
        // } else{
        //     for (int i=1;i<=n;i++){
        //         if (find(i)==find(a)){
        //             path[i]=1;
        //         }
        //     }
        // }

        res = 0;
        dfs_sol(a);
        ll res1 = res-1;
        for (int i=1;i<=n;i++) vis[i]=0;
        res = 0;
        dfs_sol(b);
        ll res2 = res-1;
        cout << res1 * res2 << el;
    }

    return 0;
}
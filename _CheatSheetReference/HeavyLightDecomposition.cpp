int n, q;
vector<pil> adj[N]; 

int dep[N], parent[N], timer;
int head[N], heavy[N], pos[N];

int pathlen;
vector<int> path;

int dfs_heavy(int node, int p){
    if (node != p) dep[node] = dep[p] + 1;
    parent[node] = p;
    int ret = 1, mx = 0;
    for (auto dest : adj[node]){
        int x = dest.fi;
        if (x == p){
            cost[node] = dest.se;
            continue;
        }
        int cur = dfs_heavy(x, node);
        ret += cur;
        if (mx < cur){
            mx = cur;
            heavy[node] = x;
        }
    }
    return ret;
}

void decompose(int node, int h){
    path.pb(node);
    pos[node] = timer++;
    head[node] = h;
    if (heavy[node]){
        decompose(heavy[node], h);
    }
    for (auto dest : adj[node]){
        int x = dest.fi;
        if (x == parent[node] || x == heavy[node]) continue;
        decompose(x, x);
    }
}
ll query(int a, int b){ // this query was meant to be query for edges(NOT NODE)
    ll ret = 0;
    for (; head[a] != head[b]; b = parent[head[b]]){
        if (dep[head[a]] > dep[head[b]]) swap(a, b);
        if (dep[b] > lasthead[head[b]]){
            ret += ask(1, 0, pathlen - 1, pos[head[b]], pos[b]);
            lasthead[head[b]] = dep[b];
        } 
    }
    if (dep[a] > dep[b]) swap(a, b);
    if (a == b) return ret;
    ret += ask(1, 0, pathlen - 1, pos[a] + 1, pos[b]);
    return ret;
}
#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e5 + 10;

int q;
int n, m;

vector<int> adj[N];
vector<int> tadj[N];

int low[N], tin[N], timer;
int cnt;
bool vis[N];

vector<pii> edges;

void init(){
    for (int i=1;i<=n + 1;i++){
        adj[i].clear();
        tadj[i].clear();
    }
    edges.clear();
}

void dfs_init(int node, int p){
    low[node] = tin[node] = ++timer;
    for (auto x : adj[node]){
        if (x == p) continue;
        if (tin[x]){
            low[node] = min(low[node], tin[x]);
        } else{
            dfs_init(x, node);
            low[node] = min(low[node], low[x]);
            if (low[x] > tin[node]){
                edges.emplace_back(x, node);
                cnt++;
            }
        }
    }
}

pii dfs(int node, int p){
    pii ret = mp(0, node);
    vis[node] = 1;
    for (auto x : tadj[node]){
        if (x == p) continue;
        pii cur = dfs(x, node);
        cur.fi++;
        if (cur.fi > ret.fi){
            ret = cur;
        }
    }
    return ret;
}

stack<int> st;
bool on_stack[N];
int comp[N];
int numComp;

void tarjan_dfs(int node, int p){
    tin[node] = low[node] = ++timer;
    st.push(node);
    on_stack[node] = 1;
    for (auto x : adj[node]){
        if (x == p) continue;
        if (tin[x] == 0){
            tarjan_dfs(x, node);
            low[node] = min(low[node], low[x]);
        } else if (on_stack[x]){
            low[node] = min(low[node], tin[x]);
        }
    }
    if (low[node] == tin[node]){
        int cur = 0;
        do{
            cur = st.top();
            st.pop();
            comp[cur] = numComp;
            on_stack[cur] = 0;
        } while (node != cur && !st.empty());
        numComp++;
    }
}

void scc(){
    fill(low, low + n + 2, 0);
    fill(tin, tin + n + 2, 0);
    timer = 0;
    cnt = 0;

    dfs_init(1, 1);
    
    fill(vis, vis + n + 2, 0);

    fill(low, low + n + 2, 0);
    fill(tin, tin + n + 2, 0);
    fill(on_stack, on_stack + n + 2, 0);
    fill(comp, comp + n + 2, 0);
    numComp = 1;
    while (!st.empty()) st.pop();
    timer = 0;

    for (int i=1;i<=n;i++) if (tin[i] == 0) tarjan_dfs(i, i);

    for (auto x : edges){
        tadj[comp[x.fi]].pb(comp[x.se]);
        tadj[comp[x.se]].pb(comp[x.fi]);
    }

    int mx = 0;
    for (int i=1;i<=n;i++){
        if (!vis[i]){
            pii a = dfs(i, i);
            pii b = dfs(a.se, a.se);
            mx = max(mx, b.fi);
        }
    }
    cout << cnt - mx << el;
}

void solve(){
    cin >> n >> m;
    for (int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    scc();
    init();
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
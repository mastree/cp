#pragma gcc optimize ("O3")
#pragma gcc optimize ("unroll-loops")

#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e5 + 10, M = 1e6 + 10;
const int INF = 1e9;

int n, m;
vector<pair<pii, int>> edges[M];

int par[N], sz[N];

void init(){
    for (int i=1;i<=n;i++){
        par[i] = i;
        sz[i] = 1;
    }
}
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

map<int, int> getid;

vector<int> adj[N]; 
int comp[N], csz[N];
int compNum;
int low[N], tin[N], timer;
stack<int> st;

unordered_map<int, int> cnt[N];

int ans[N];
vector<int> nada;

void dfs_scc(int node, int p){
    low[node] = tin[node] = ++timer;
    st.push(node);
    for (auto x : adj[node]){
        if (x == p && cnt[node][x] == 1) continue;  // add parent as parameter and add this line for directed graph
        if (tin[x] == 0){
            dfs_scc(x, node);
            low[node] = min(low[node], low[x]);
        } else {
            low[node] = min(low[node], tin[x]);
        }
    }
    if (low[node] == tin[node]){
        ++compNum;
        while (1){
            auto temp = st.top();
            st.pop();
            comp[temp] = compNum;
            if (temp == node || st.empty()) break;
        }
    }
}

void tarjan(){
    compNum = timer = 0;
    for (auto x : nada){
        low[x] = 0;
        tin[x] = 0;
        comp[x] = 0;
    }
    while (!st.empty()) st.pop();

    for (auto i : nada){
        if (tin[i] == 0) dfs_scc(i, adj[i][0]);
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    {
        for (int i=1;i<=m;i++){
            int a, b;
            int w;
            cin >> a >> b >> w;
            edges[w].pb(mp(mp(a, b), i));
        }
    }
    init();
    for (int i=1;i<M;i++){
        if (edges[i].empty()) continue;
        for (auto x : edges[i]){
            int a = find(x.fi.fi);
            int b = find(x.fi.se);
            if (a == b){
                ans[x.se] = 0;
                continue;
            }
            cnt[a][b]++;
            cnt[b][a]++;
            nada.pb(a);
            nada.pb(b);
            adj[a].pb(b);
            adj[b].pb(a);
            ans[x.se] = 1;
        }
        tarjan();
        for (auto x : nada){
            adj[x].clear();
            cnt[x].clear();
        }
        nada.clear();
        for (auto x : edges[i]){
            int a = x.fi.fi, b = x.fi.se;
            if (comp[find(a)] != comp[find(b)]) ans[x.se] = 2;
        }

        for (auto x : edges[i]){
            make(x.fi.fi, x.fi.se);
        }
    }
    for (int i=1;i<=m;i++){
        if (ans[i] == 0) cout << "none" << el;
        else if (ans[i] == 1) cout << "at least one" << el;
        else cout << "any" << el;
    }

    return 0;
}
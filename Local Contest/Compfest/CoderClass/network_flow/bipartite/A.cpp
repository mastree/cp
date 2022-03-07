#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 510;
const int M = 1e3 + 10;
const int INF = 1e9 + 10;

int n, m;
int ar[N];
vector<pii> fac[N];
vector<int> fac_id[N];
int timer;

void init_fac(int id){
    int x = ar[id];
    for (int i=2;i * i<=x;i++){
        if (x % i == 0){
            int cnt = 0;
            while (x % i == 0){
                cnt++;
                x /= i;
            }
            fac[id].pb(mp(i, cnt));
            fac_id[id].pb(++timer);
        }
    }
    if (x > 1){
        fac[id].pb(mp(x, 1));
        fac_id[id].pb(++timer);
    }
}

struct FlowEdge{
    int v, u;
    int cap, flow = 0;
    FlowEdge(int v, int u, int cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
    const int flow_inf = 1e9 + 10;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }
    void add_edge(int v, int u, int cap) {
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }
    bool bfs() {
        while (!q.empty()){
            int v = q.front();
            q.pop();
            for (int id : adj[v]){
                if (edges[id].cap - edges[id].flow < 1) continue;
                if (level[edges[id].u] != -1) continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }
    int dfs(int v, int pushed) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            int tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }
    int flow() {
        int f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (int pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        init_fac(i);
    }
    int s = 0, t = timer + 1;
    Dinic dinic(t + 1, s, t);
    for (int i=1;i<=n;i++){
        if (i & 1){
            for (int j=0;j<fac[i].size();j++){
                dinic.add_edge(s, fac_id[i][j], fac[i][j].se);
            }
        } else{
            for (int j=0;j<fac[i].size();j++){
                dinic.add_edge(fac_id[i][j], t, fac[i][j].se);
            }
        }
    }
    for (int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        if (a & 1 ^ 1) swap(a, b);
        int j = 0;
        for (int k=0;j<fac[a].size() && k<fac[b].size();k++){
            while (j < fac[a].size() && fac[a][j].fi < fac[b][k].fi) j++;
            if (j < fac[a].size() && fac[a][j].fi == fac[b][k].fi){
                dinic.add_edge(fac_id[a][j], fac_id[b][k], fac[a][j].se);
            }
        }
    }
    int ans = dinic.flow();
    cout << ans << el;

    return 0;
}
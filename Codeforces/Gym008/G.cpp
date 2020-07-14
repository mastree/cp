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

struct FlowEdge {
    int v, u;
    long long cap, flow = 0;
    FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
    const long long flow_inf = 1e18;
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

    void add_edge(int v, int u, long long cap) {
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }

    bool bfs() {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : adj[v]) {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    long long dfs(int v, long long pushed) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    long long flow() {
        long long f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
};

const int N = 1e3 + 10;
const int INF = 1e9 + 10;

int n, m, k;
int gas[N], refiner[N];
vector<pii> adl[N]; // from refiner to gas;  
int tot;

bool eval(int mn){
    Dinic dinic(3 + n + m, 1, 2 + n + m);
    for (int i=1;i<=n;i++){
        dinic.add_edge(i + m + 1, 2 + n + m, gas[i]);
    }
    for (int i=1;i<=m;i++){
        dinic.add_edge(1, i + 1, refiner[i]);
    }
    for (int i=1;i<=m;i++){
        for (auto x : adl[i]){
            if (x.se > mn) continue;
            int a = i + 1;
            int b = x.fi + m + 1;
            int cap = INF;
            dinic.add_edge(a, b, cap);
        }
    }
    int temp = (int) dinic.flow();
    return (temp >= tot); 
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    for (int i=1;i<=n;i++){
        cin >> gas[i];
        tot += gas[i];
    }
    for (int i=1;i<=m;i++){
        cin >> refiner[i];
    }
    for (int i=1;i<=k;i++){
        int a, b, w;
        cin >> a >> b >> w;
        adl[b].pb(mp(a, w));
    }

    int low = 1, high = INF;
    while (low < high){
        int mid = (low + high) / 2;
        if (eval(mid)){
            high = mid;
        } else{
            low = mid + 1;
        }
    }
    if (high == INF) cout << -1 << el;
    else cout << high << el;

    return 0;
}
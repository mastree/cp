#include <bits/stdc++.h>

using namespace std;
using pli = pair<long long, int>;

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

const long long INF = 1e18;
const int N = 1e5 + 5;

int n, m;
int val_w[N];
pair<int, int> edges[N];
vector<pair<int, int>> adj[N];
vector<pair<int, int>> radj[N];
vector<pair<int, int>> adj_dijkstra[N];
long long dist[N][3];
bool visited[N];
int tin[N], low[N];
int timer;
bool in_dijsktra[N];
bool bridge[N];

void dijkstra(int s, bool reverse) {
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    for (int u = 1; u <= n; u++) {
        dist[u][s] = INF;
    }
    dist[s][s] = 0LL;
    pq.emplace(dist[s][s], s);
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (dist[u][s] != d) {
            continue;
        }
        if (!reverse) {
            debug() << imie(u) imie(adj[u]);
        }
        for (auto& [v, id] : (!reverse ? adj[u] : radj[u])) {
            if (!reverse) {
                debug() << "N-REVERSE" << imie(u) imie(v) imie(id);
                debug() << imie(dist[v][s]) imie(dist[u][s]) imie(val_w[id]);
            }
            if (dist[v][s] > dist[u][s] + val_w[id]) {
                dist[v][s] = dist[u][s] + val_w[id];
                pq.emplace(dist[v][s], v);
            }
        }
    }
}

void dfs(int u, int p = -1) {
    visited[u] = true;
    tin[u] = low[u] = timer++;
    for (auto& [v, id] : adj_dijkstra[u]) {
        if (v == p) continue;
        if (visited[v]) {
            low[u] = min(low[u], tin[v]);
        } else {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (tin[u] < low[v]) {
                debug() << imie("BRIDGE") imie(id);
                bridge[id] = true;
            }
        }
    }
}

void find_bridges() {
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        auto& [u, v] = edges[i];
        cin >> u >> v >> val_w[i];
        adj[u].emplace_back(v, i);
        radj[v].emplace_back(u, i);
    }
    int source = 1;
    int target = 2;
    dijkstra(source, false);
    dijkstra(target, true);
    debug() << imie(dist[target][source]) imie(dist[source][target]);
    for (int i = 1; i <= m; i++) {
        auto& [u, v] = edges[i];
        debug() << imie(i) imie(dist[u][source]) imie(dist[v][target]) imie(val_w[i]);
        if (dist[u][source] + dist[v][target] + val_w[i] == dist[target][source]) {
            adj_dijkstra[u].emplace_back(v, i);
            adj_dijkstra[v].emplace_back(u, i);
            in_dijsktra[i] = true;
            debug() << imie("DIJKSTRA") imie(i);
        }
    }
    find_bridges();
    for (int i = 1; i <= m; i++) {
        if (bridge[i]) {
            cout << "SAD" << '\n';
        } else if (in_dijsktra[i]) {
            cout << "SOSO" << '\n';
        } else {
            auto& [u, v] = edges[i];
            debug() << imie(u) imie(v);
            debug() << imie(dist[u][source]) imie(dist[v][target]) imie(val_w[i]);
            if (dist[v][source] + val_w[i] + dist[u][target] < dist[target][source]) {
                cout << "HAPPY" << '\n';
            } else {
                cout << "SOSO" << '\n';
            }
        }
    }

    return 0;
}
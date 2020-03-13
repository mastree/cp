#include <bits/stdc++.h>
using namespace std;
typedef pair<pair<int, int>, int> pipi;

int par[100005];
int n, m;

void reset() {
    for (int i = 1; i <= n; i++) {
        par[i] = i;
    }
    return;
}

int find(int x) {
    if (par[x] == x) return x;
    return par[x] = find(par[x]);
}

void uni(int u, int v) {
    u = find(u);
    v = find(v);
    par[u] = v;
}

int main() {
    cin >> n >> m;
    vector<pipi> adj;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj.push_back({{u, v}, w});
    }
    sort(adj.begin(), adj.end(), [](pipi a, pipi b) {
        return a.second < b.second;
    });

    int ans = INT_MAX;
    reset();
    for (int i = 1; i < m; i++) {
        uni(adj[i].first.first, adj[i].first.second);
        if (find(adj[0].first.first) == find(adj[0].first.second)) {
            ans = min(ans, adj[i].second);
        }
    }

    cout << ans << '\n';

    return 0;
}
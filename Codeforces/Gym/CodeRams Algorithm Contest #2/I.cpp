#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

struct graph
{
	int n;
	vector<vector<int>> adj;
 
	graph(int n) : n(n), adj(n) {}
 
	void add_edge(int u, int v)
	{
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
 
	int add_node()
	{
		adj.push_back({});
		return n++;
	}
 
	vector<int>& operator[](int u) { return adj[u]; }
};
 
vector<vector<int>> biconnected_components(graph &adj)
{
	int n = adj.n;
 
	vector<int> num(n), low(n), art(n), stk;
	vector<vector<int>> comps;
 
	function<void(int, int, int&)> dfs = [&](int u, int p, int &t)
	{
		num[u] = low[u] = ++t;
		stk.push_back(u);
 
		for (int v : adj[u]) if (v != p)
		{
			if (!num[v])
			{
				dfs(v, u, t);
				low[u] = min(low[u], low[v]);
 
				if (low[v] >= num[u])
				{
					art[u] = (num[u] > 1 || num[v] > 2);
 
					comps.push_back({u});
					while (comps.back().back() != v)
						comps.back().push_back(stk.back()), stk.pop_back();
				}
			}
			else low[u] = min(low[u], num[v]);
		}
	};
 
	for (int u = 0, t; u < n; ++u)
		if (!num[u]) dfs(u, -1, t = 0);
 
	// build the block cut tree
	function<graph()> build_tree = [&]()
	{
		graph tree(0);
		vector<int> id(n);
 
		for (int u = 0; u < n; ++u)
			if (art[u]) id[u] = tree.add_node();
 
		for (auto &comp : comps)
		{
			int node = tree.add_node();
			for (int u : comp)
				if (!art[u]) id[u] = node;
				else tree.add_edge(node, id[u]);
		}
 
		return tree;
	};
 
	return comps;
}
const int N = 1e5 + 10;

int n, m, a, b;
graph g(N);
vector<int> grup[N];
bool ans[N];

vector<int> adj[N + N];
int par[N + N];
bool mark[N + N], vis[N + N];

void dfs(int node, int p){
    vis[node] = 1;
    if (node == par[b]){
        mark[node] = 1;
        return;
    }
    for (auto& x : adj[node]){
        if (x == p) continue;
        if (!vis[x]) dfs(x, node);
        if (mark[x]) mark[node] = 1;
    }
    // cout << node << " " << mark[node] << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> a >> b;
    g.n = n;
    for (int i=1;i<=m;i++){
        int len;
        cin >> len;
        int a;
        cin >> a;
        for (int i=1;i<len;i++){
            int b;
            cin >> b;
            g[a].pb(b);
            g[b].pb(a);
            cout << a << " " << b << el;
            a = b;
        }
    }   
    vector<vector<int>> comps = biconnected_components(g);
    int len = comps.size();
    for (int i=0;i<len;i++){
        cout << i + 1 << " => ";
        for (auto& x : comps[i]){
            grup[x].pb(i + 1);
            cout << x << ' ';
        }
        cout << el;
    }
    // for (int i=1;i<=n;i++){
    //     if (grup[i].size() == 1 && i != a && i != b){
    //         par[i] = n + grup[i][0];
    //     } else{
    //         par[i] = i;
    //         for (auto& x : grup[i]){
    //             adj[i].pb(n + x);
    //             adj[n + x].pb(i);
    //         }
    //     }
    // }
    // dfs(par[a], par[a]);
    // for (int i=1;i<=n;i++){
    //     // cout << i << " " << mark[par[i]] << el;
    //     ans[i] = 1;
    //     if (mark[par[i]] && par[i] == i) ans[i] = 0;
    // }
    // for (int i=1;i<=n;i++){
    //     cout << ans[i];
    // }
    // cout << el;
    for (int i=1;i<=n;i++){
        if ((int)grup[i].size() == 1 && i != a && i != b){
            par[i] = n + grup[i][0];
        } else{
            par[i] = i;
            for (auto& x : grup[i]){
                adj[i].pb(n + x);
                adj[n + x].pb(i);
                cout << i << " " << n + x << el;
            }
        }
    }
    fill(mark, mark + N + N, 0);
    fill(vis, vis + N + N, 0);
    dfs(par[a], par[a]);
    for (int i=1;i<=n;i++){
        if (par[i] == i && mark[i] == 1) ans[i] = 0;
        else ans[i] = 1;
    }
    for (int i=1;i<=n;i++){
        cout << ans[i];
    }
    cout << el;

    return 0;
}
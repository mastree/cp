#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e4 + 10;

struct Graf{
    int n;
    vector<vector<int>> adj;
    vector<int> low, tin;
    int timer, cnt;

    Graf(int n = 0) : n(n) {
        adj.resize(n + 1);
        low.resize(n + 1, 0);
        tin.resize(n + 1, 0);
        timer = 0;
        cnt = 0;
    }
    void add_edge(int a, int b){
        adj[a].pb(b);
        adj[b].pb(a);
    }
    void dfs(int node, int p){
        low[node] = tin[node] = ++timer;
        int ch = 0;
        for (auto x : adj[node]){
            if (x == p) continue;
            if (tin[x] != 0){
                low[node] = min(low[node], tin[x]);
            } else{
                dfs(x, node);
                low[node] = min(low[node], low[x]);
                if (tin[node] <= low[x]){
                    ch++;
                }
            }
        }
        if (node != p && ch) cnt++;
        else if (node == p && ch >= 2) cnt++;
    }
    int solve(){
        for (int i=1;i<=n;i++){
            if (tin[i] == 0) dfs(i, i);
        }
        return cnt;
    }
};

int n, m;
bool solve(){
    cin >> n >> m;
    if (n == 0 && m == 0) return 0;
    Graf g(n);
    {
        for (int i=1;i<=m;i++){
            int a, b;
            cin >> a >> b;
            g.add_edge(a, b);
        }
    }
    cout << g.solve() << el;
    return 1;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while (1){
        if (!solve()) break;
    }

    return 0;
}
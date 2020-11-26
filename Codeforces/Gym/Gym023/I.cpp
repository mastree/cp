#pragma gcc optimize ("O2")
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

const int N = 1e5 + 10, M = 18;

struct Graf{
    int n, r;
    vector<vector<int>> adj;
    vector<vector<int>> up;
    vector<int> tin, tout, sz;
    int timer;

    Graf(){}
    Graf(int n, int r) : n(n), r(r) {
        adj.resize(n + 2);
        up.resize(n + 2, vector<int>(M, 0));
        tin.resize(n + 2);
        tout.resize(n + 2);
        sz.resize(n + 2, 0);
        timer = 0;
    }
    void add_edge(int a, int b){
        adj[a].pb(b);
        adj[b].pb(a);
    }

    void dfs_init(int node, int p){
        sz[node] = 1;
        up[node][0] = p;
        for (int i=1;i<M;i++){
            up[node][i] = up[up[node][i - 1]][i - 1];
        }
        tin[node] = ++timer;
        for (auto x : adj[node]){
            if (x == p) continue;
            dfs_init(x, node);
            sz[node] += sz[x];
        }
        tout[node] = ++timer;
    }
    bool is_ancestor(int a, int b){
        return tin[a] <= tin[b] && tout[b] <= tout[a];
    }
    int up_to_child(int a, int b){ // a ancestor of b
        for (int i=M - 1;i>=0;i--){
            if (!is_ancestor(up[b][i], a)){
                b = up[b][i];
            }
        }
        return b;
    }
    int ask(int a){
        if (a == r) return n;
        if (is_ancestor(a, r)){
            int temp = up_to_child(a, r);
            return n - sz[temp];
        } 
        return sz[a];
    }
    void change_r(int nr){
        r = nr;
    }
};

int tc;

void solve(){
    int n, q, r;
    cin >> n >> q >> r;
    Graf g(n, r);
    for (int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        g.add_edge(a, b);
    }
    g.dfs_init(1, 1);
    while (q--){
        int tipe, x;
        cin >> tipe >> x;
        if (tipe == 0){
            g.change_r(x);
        } else{
            cout << g.ask(x) << el;
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    for (int i=1;i<=tc;i++){
        cout << "Case #" << i << ":\n";
        solve();
    }

    return 0;
}
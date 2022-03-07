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
const int INF = 1e9;

int q;
int n;
vector<int> adj[N];

int sz[N], mx[N];
vector<int> bisa;

int parent[N];

void reset(){
    for (int i=1;i<=n;i++){
        adj[i].clear();
        sz[i] = mx[i] = 0;
        parent[i] = 0;
    }
    bisa.clear();
}
int dfs_size(int node, int p){
    sz[node] = 1;
    parent[node] = p;
    for (auto x : adj[node]){
        if (x == p) continue;
        int temp = dfs_size(x, node);
        sz[node] += temp;
        mx[node] = max(mx[node], temp);
    }
    if (n - sz[node] <= n / 2 && mx[node] <= n / 2){
        bisa.pb(node);
    }
    return sz[node];
}
int dfs(int node){
    int ret = node;
    for (auto x : adj[node]){
        if (x == parent[node]) continue;
        ret = dfs(x);
    }
    return ret;
}

void solve(){
    cin >> n;
    for (int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs_size(1, 1);
    if (bisa.size() == 1){
        pii temp = mp(1, adj[1][0]);
        cout << temp.fi << " " << temp.se << el;
        cout << temp.fi << " " << temp.se << el;
        reset();
        return;
    }
    int ambil = dfs(bisa[0]);
    cout << ambil << " " << parent[ambil] << el;
    cout << ambil << " " << bisa[1] << el;
    reset();
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
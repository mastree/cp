#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 8e5 + 10;

int q;
int n;
vector<vector<int>> adj;
vector<vector<int>> freq;

int dep[N], parent[N], timer;
int head[N], heavy[N], pos[N];

int pathlen;
vector<int> path;

int pathpre[N];

int dfs_heavy(int node, int p){
    if (node != p) dep[node] = dep[p] + 1;
    parent[node] = p;
    int ret = 1, mx = 0;
    for (auto dest : adj[node]){
        int x = dest;
        if (x == p){
            // cost[node] = 1;
            continue;
        }
        int cur = dfs_heavy(x, node);
        ret += cur;
        if (mx < cur){
            mx = cur;
            heavy[node] = x;
        }
    }
    return ret;
}

void decompose(int node, int h){
    path.pb(node);
    pos[node] = timer++;
    head[node] = h;
    if (heavy[node]){
        decompose(heavy[node], h);
    }
    for (auto dest : adj[node]){
        int x = dest;
        if (x == parent[node] || x == heavy[node]) continue;
        decompose(x, x);
    }
}

int query(int a, int b){
    int ret = -1; // LCA
    for (; head[a] != head[b]; b = parent[head[b]]){
        if (dep[head[a]] > dep[head[b]]) swap(a, b);
        pathpre[pos[head[b]]]++;
        pathpre[pos[b] + 1]--;
    }
    if (dep[a] > dep[b]) swap(a, b);
    // cout << pos[a] << " " << pos[b] << el;
    pathpre[pos[a] + 1]++;
    pathpre[pos[b] + 1]--;
    return a;
}

void init_hld(){
    fill(dep, dep + n + 1, 0);
    fill(parent, parent + n + 1, 0);
    fill(head, head + n + 1, 0);
    fill(heavy, heavy + n + 1, 0);
    fill(pos, pos + n + 1, 0);
    fill(pathpre, pathpre + n + 1, 0);
    timer = 0;
    path.clear();
    dfs_heavy(1, 1);
    decompose(1, 1);
    pathlen = path.size();
}

void solve(){
    cin >> n;
    adj.clear();
    freq.clear();
    adj.resize(n + 1, vector<int>());
    freq.resize(n + 1, vector<int>());
    for (int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for (int i=1;i<=n;i++){
        int a;
        cin >> a;
        freq[a].pb(i);
    }
    init_hld();
    int ans = 0;
    for (int i=1;i<=n;i++){
        int len = freq[i].size();
        if (len > 1){
            int last = freq[i][0];
            for (int j=1;j<len;j++){
                last = query(last, freq[i][j]);
            }
        }
    }
    int cur = 0;
    for (int i=1;i<pathlen;i++){
        cur += pathpre[i];
        if (cur == 0) ans++;
    }
    cout << ans << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    for (int i=1;i<=q;i++){
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}
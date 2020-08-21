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

int n, m, q;
vector<int> adj[N];
vector<int> city[N]; // ids of population

int parent[N], dep[N];
int heavy[N], head[N], pos[N], cur_pos;
vector<int> path;
int pathlen;

vector<int> t[8 * N];

void build(int v, int tl, int tr){
    if (tl == tr){
        for (auto x : city[path[tl]]){
            t[v].pb(x);
        }
        return;
    }
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
    t[v].resize(t[v * 2].size() + t[v * 2 + 1].size());
    merge(t[v * 2].begin(), t[v * 2].end(), t[v * 2 + 1].begin(), t[v * 2 + 1].end(), t[v].begin());
    while (t[v].size() > 10) t[v].pop_back(); 
}
vector<int> ask(int v, int tl, int tr, int l, int r){
    vector<int> ret;
    if (l > r) return ret;
    else if (l <= tl && tr <= r){
        return t[v];
    }
    int tm = (tl + tr) / 2;
    vector<int> temp1, temp2;
    temp1 = ask(v * 2, tl, tm, l, min(tm, r));
    temp2 = ask(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    ret.resize(temp1.size() + temp2.size());
    merge(temp1.begin(), temp1.end(), temp2.begin(), temp2.end(), ret.begin());
    while (ret.size() > 10) ret.pop_back();
    return ret;
}
vector<int> query(int a, int b){
    vector<int> ret, nret, temp;
    for (; head[a] != head[b]; b = parent[head[b]]){
        if (dep[head[a]] > dep[head[b]]) swap(a, b);
        temp = ask(1, 0, pathlen - 1, pos[head[b]], pos[b]);
        nret.resize(ret.size() + temp.size());
        merge(ret.begin(), ret.end(), temp.begin(), temp.end(), nret.begin());
        while (nret.size() > 10) nret.pop_back();
        ret = nret;
    }
    if (dep[a] > dep[b]) swap(a, b);
    temp = ask(1, 0, pathlen - 1, pos[a], pos[b]);
    nret.resize(ret.size() + temp.size());
    merge(ret.begin(), ret.end(), temp.begin(), temp.end(), nret.begin());
    ret.clear();
    for (auto x : nret){
        if (ret.empty()){
            ret.pb(x);
        } else{
            if (x == ret.back()) continue;
            ret.pb(x);
        }
    }
    while (ret.size() > 10) ret.pop_back();
    return ret;
}
int dfs_init(int node, int p){
    if (node != 1) dep[node] = dep[p] + 1;
    parent[node] = p;

    int ret = 1, mx = 0;
    for (auto x : adj[node]){
        if (x == p) continue;
        int cur = dfs_init(x, node);
        ret += cur;
        if (mx < cur){
            heavy[node] = x;
            mx = cur;
        }
    }
    return ret;
}

void decompose(int node, int h){
    head[node] = h;
    pos[node] = cur_pos++;
    path.pb(node);
    if (heavy[node]){
        decompose(heavy[node], h);
    }
    for (auto x : adj[node]){
        if (x == parent[node] || x == heavy[node]) continue;
        decompose(x, x);
    }
}

void init(){
    int dummy = dfs_init(1, 1);
    decompose(1, 1);
    dep[0] = INF;
    pathlen = path.size();

    build(1, 0, pathlen - 1);
}

void solve(int v, int u, int a){
    vector<int> temp, ans;
    temp = query(v, u);
    int pp = temp.size();
    for (int i=0;i<pp;i++){
        if (i == 0) ans.pb(temp[i]);
        else{
            if (temp[i] == ans.back()) continue;
            ans.pb(temp[i]);
        }
    }
    while (ans.size() > a) ans.pop_back();
    cout << ans.size() << " ";
    for (auto x : ans) cout << x << " "; cout << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> q;
    for (int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for (int i=1;i<=m;i++){
        int a;
        cin >> a;
        if (city[a].size() < 10) city[a].pb(i);
    }
    init();

    while (q--){
        int v, u, a;
        cin >> v >> u >> a;

        solve(v, u, a);
    }

    return 0;
}
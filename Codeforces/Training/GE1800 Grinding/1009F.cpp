#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e6 + 10;

int n;
vector<int> adj[N];
int ans[N];
int dep[N];

map<int, int> cnt[N];
int par[N];
int sz[N];
int mx[N]; // id of the max

int find(int a){
    return (par[a] == a ? a : par[a] = find(par[a]));
}
void make(int a, int b){
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
    for (auto x : cnt[b]){
        int tot = cnt[a][x.fi] + x.se;
        cnt[a][x.fi] = tot;
        if (mp(tot, -x.fi) > mp(cnt[a][mx[a]], -mx[a])){
            mx[a] = x.fi;
        }
    }
}

void dfs_dep(int node, int p){
    dep[node] = dep[p] + 1;
    for (auto x : adj[node]){
        if (x == p) continue;
        dfs_dep(x, node);
    }
}
void init(){
    dfs_dep(1, 1);
    for (int i=1;i<=n;i++){
        par[i] = i;
        sz[i] = 1;
        cnt[i][dep[i]]++;
        mx[i] = dep[i];
    }
}

void dfs(int node, int p){
    for (auto x : adj[node]){
        if (x == p) continue;
        dfs(x, node);
        make(node, x);
    }
    ans[node] = mx[find(node)] - dep[node];
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    init();
    dfs(1, 1);
    for (int i=1;i<=n;i++){
        cout << ans[i] << el;
    }

    return 0;
}
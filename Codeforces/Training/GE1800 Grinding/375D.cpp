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
using piiii = pair<pii, pii>;

const int N = 1e5 + 10;

int n, m;
int color[N];
vector<int> adj[N];
int dep[N];
vector<piiii> quer; // dep, id_query, node, cnt minimum
int ans[N];

piiii mp4(const int a, const int b, const int c, const int d){
    return mp(mp(a, b), mp(c, d));
}

void dfs_height(int node, int p){
    dep[node] = dep[p] + 1;
    for (auto x : adj[node]){
        if (x == p) continue;
        dfs_height(x, node);
    }
}

vector<int> cnt_cnt[N];
unordered_map<int, int> cnt[N];
int par[N], sz[N];

void upd(int p, int x, int add){
    while (x > 0){
        cnt_cnt[p][x] += add;
        x = x - (x & (-x));
    }
}
int ask(int p, int x){
    int mx = (int)cnt_cnt[p].size();
    int ret = 0;
    x = max(x, 1);
    while (x < mx){
        ret += cnt_cnt[p][x];
        x = x + (x & (-x));
    }
    return ret;
}

int find(int a){
    if (par[a] == a) return a;
    return par[a] = find(par[a]);
}
void make(int a, int b){
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
    cnt_cnt[a].resize(sz[a] + 1, 0);
    for (auto x : cnt[b]){
        int col = x.fi, tam = x.se;
        int temp = cnt[a][col];
        upd(a, temp, -1);
        upd(a, temp + tam, 1);
        cnt[a][col] += tam;
    }
}

void push(int node){
    if (sz[find(node)]) return;
    sz[node]++;
    cnt[node][color[node]]++;
    cnt_cnt[node].resize(2, 0);
    upd(node, 1, 1);
    for (auto x : adj[node]){
        if (dep[x] < dep[node]) continue;
        push(x);
        make(node, x);
    }
}

void solve(piiii qq){
    int a = qq.se.fi, b = qq.se.se;
    push(a);
    ans[qq.fi.se] = ask(find(a), b);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=n;i++){
        par[i] = i;
        sz[i] = 0;
        cin >> color[i];
    }
    for (int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs_height(1, 1);
    for (int i=1;i<=m;i++){
        int c, d;
        cin >> c >> d;
        quer.pb(mp4(dep[c], i, c, d));
    }
    sort(quer.begin(), quer.end(), greater<piiii>());
    for (auto qq : quer){
        solve(qq);
    }
    for (int i=1;i<=m;i++){
        cout << ans[i] << el;
    }

    return 0;
}
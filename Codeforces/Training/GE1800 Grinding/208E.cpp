#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'

using namespace std;

const int N = 1e5 + 10;
const int M = 17;

int n, q;
int par[N];
vector<int> adl[N];

int upar[N], sz[N];
int dep[N];
vector<int> tree[N];

int tin[N], tout[N];
vector<int> euler[N];
vector<unordered_map<int, int>> t[N];

int up[N][M];

bool is_ancestor(int a, int b){
    return tin[a] <= tin[b] && tout[b] <= tout[a];
}

int find(int a){
    if (upar[a] == a) return a;
    return upar[a] = find(upar[a]);
}

void make(int a, int b){
    a = find(a);
    b = find(b);
    if (a == b) return;
    sz[a] += sz[b];
    upar[b] = a;
}

int timer[N];
void dfs_tur(int node, int p){
    dep[node] = dep[p] + 1;
    tin[node] = ++timer[find(node)];
    euler[find(node)].pb(dep[node]);
    up[node][0] = p;
    for (int i=1;i<M;i++){
        up[node][i] = up[up[node][i - 1]][i - 1];
    }

    for (auto x : adl[node]){
        if (x == p) continue;
        dfs_tur(x, node);
    }
    tout[node] = timer[find(node)];
    // euler[find(node)].pb(-1);
}

int uni;
void build(int v, int tl, int tr){
    if (tl == tr){
        t[uni][v][euler[uni][tl]]++;
        return;
    }
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
    for (auto x : t[uni][v * 2]){
        t[uni][v][x.fi] = x.se;
    }
    for (auto x : t[uni][v * 2 + 1]){
        t[uni][v][x.fi] += x.se;
    }
}

int val;
int ask(int v, int tl, int tr, int l, int r){
    if (l > r) return 0;
    else if (l <= tl && tr <= r){
        return t[uni][v][val];
    }
    int tm = (tl + tr) / 2;
    return ask(v * 2, tl, tm, l, min(tm, r)) + ask(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}

int xth_ancestor(int node, int x){
    int cur = 0;
    for (int i=M - 1;i>=0;i--){
        int plus = (1 << i);
        if (cur + plus <= x){
            node = up[node][i];
            cur += plus;
        }
    }
    return node;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        sz[i] = 1;
        upar[i] = i;
    }
    for (int i=1;i<=n;i++){
        cin >> par[i];
        if (par[i] != 0){
            adl[par[i]].pb(i);
            adl[i].pb(par[i]);
            make(par[i], i);
        }
    }
    for (int i=1;i<=n;i++){
        tree[find(i)].pb(i);
    }
    for (int i=1;i<=n;i++){
        if (upar[i] == i){
            euler[i].pb(-1); // dummy;
            dfs_tur(i, i);
            t[i].resize(timer[i] * 4 + 10);
            uni = i;
            build(1, 1, timer[i]);
        }
    }

    cin >> q;
    while (q--){
        int v, p;
        cin >> v >> p;
        if (dep[v] <= p){
            cout << 0 << " ";
            continue;
        }
        v = xth_ancestor(v, p);
        uni = find(v);
        val = dep[v] + p;
        cout << ask(1, 1, timer[uni], tin[v], tout[v]) - 1 << " ";
    }
    cout << el;

    return 0;
}
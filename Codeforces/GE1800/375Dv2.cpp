#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

struct Query{
    int i;
    int l, r;
    int k;
};

const int N = 1e5 + 10;

int n, m;
int color[N];
vector<int> adj[N];
int tin[N], timer, sz[N];
int tur[N];

Query quer[N];

void dfs_tin(int node, int p){
    tin[node] = ++timer;
    tur[timer] = node;
    sz[node] = 1;
    for (auto x : adj[node]){
        if (x == p) continue;
        dfs_tin(x, node);
        sz[node] += sz[x];
    }
}

int sqr;
bool comp(Query a, Query b){
    pii tempa = mp(a.l / sqr, a.r / sqr);
    pii tempb = mp(b.l / sqr, b.r / sqr);
    return tempa < tempb;
}

int cnt[N], bit[N];
int ans[N];

void upd(int x, int add){
    while (x > 0){
        bit[x] += add;
        x = x - (x & (-x));
    }
}
int ask(int x){
    int ret = 0;
    while (x < N){
        ret += bit[x];
        x = x + (x & (-x));
    }
    return ret;
}
void add(int col){
    upd(cnt[col], -1);
    cnt[col]++;
    upd(cnt[col], 1);
}
void subt(int col){
    upd(cnt[col], -1);
    cnt[col]--;
    upd(cnt[col], 1);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    sqr = sqrt(n);
    for (int i=1;i<=n;i++){
        cin >> color[i];
    }
    for (int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs_tin(1, 1);
    for (int i=1;i<=m;i++){
        int node;
        cin >> node >> quer[i].k;
        quer[i].i = i;
        quer[i].l = tin[node];
        quer[i].r = tin[node] + sz[node] - 1;
    }
    sort(quer + 1, quer + m + 1, &comp);
    int l = 1, r = 0;
    for (int i=1;i<=m;i++){
        int ql = quer[i].l, qr = quer[i].r;

        while (l < ql){
            subt(color[tur[l]]);
            l++;
        }
        while (l > ql){
            l--;
            add(color[tur[l]]);
        }
        while (r < qr){
            r++;
            add(color[tur[r]]);
        }
        while (r > qr){
            subt(color[tur[r]]);
            r--;
        }
        ans[quer[i].i] = ask(quer[i].k);
    }
    for (int i=1;i<=m;i++) cout << ans[i] << el;

    return 0;
}
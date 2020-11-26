#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e3 + 10;

int n, m, q;
vector<int> adj[N];
int ans[N];
pii quer[N];

vector<pii> edges;

int rpar[N], rsz[N];
int rfind(int a){
    return (rpar[a] == a ? a : rpar[a] = rfind(rpar[a]));
}
void rmake(int a, int b){
    a = rfind(a);
    b = rfind(b);
    if (a == b) return;
    if (rsz[a] < rsz[b]) swap(a, b);
    rsz[a] += rsz[b];
    rpar[b] = a;
}
int pus;
int par[N], sz[N];
int find(int a){
    return (par[a] == a ? a : par[a] = find(par[a]));
}
void make(int a, int b){
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    par[b] = a;
}
void proc(){
    for (int i=1;i<=n;i++){
        par[i] = i;
        sz[i] = 1;
    }
    for (auto x : edges){
        if (x.fi == pus || x.se == pus) continue;
        make(x.fi, x.se);
    }
    for (int i=1;i<=q;i++){
        int a = quer[i].fi;
        int b = quer[i].se;
        if (rfind(a) == rfind(b) && find(a) != find(b)){
            ans[i]++;
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=n;i++){
        rpar[i] = i;
        rsz[i] = 1;
    }
    for (int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        rmake(a, b);
        edges.emplace_back(a, b);
        adj[a].pb(b);
        adj[b].pb(a);
    }
    cin >> q;
    for (int i=1;i<=q;i++){
        cin >> quer[i].fi >> quer[i].se;
    }
    for (int i=1;i<=n;i++){
        pus = i;
        proc(); 
    }
    for (int i=1;i<=q;i++){
        cout << ans[i] << el;
    }

    return 0;
}
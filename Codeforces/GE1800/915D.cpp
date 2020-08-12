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

const int N = 700;

int n, m;
vector<int> adj[N], radj[N];
vector<int> order;
bool vis[N];
int comp[N];
vector<int> vcomp[N];

int a, b;

void dfs1(int node){
    vis[node] = 1;
    for (auto x : adj[node]){
        if (vis[x]) continue;
        dfs1(x);
    }
    order.pb(node);
}
void dfs2(int node, int id){
    comp[node] = id;
    vcomp[id].pb(node);
    for (auto x : radj[node]){
        if (comp[x]) continue;
        dfs2(x, id);
    }
}

void kosaraju(){
    fill(vis, vis + n + 2, 0);
    fill(comp, comp + n + 2, 0);
    order.clear();
    for (int i=1;i<=n;i++){
        vcomp[i].clear();
        if (!vis[i]){
            dfs1(i);
        }
    }
    for (int i=n - 1, j = 0;i>=0;i--){
        int cur = order[i];
        if (!comp[cur]){
            ++j;
            dfs2(cur, j);
        }
    }
}

void dfs12(int node){
    vis[node] = 1;
    for (auto x : adj[node]){
        if (vis[x] || (node == a && x == b)) continue;
        dfs12(x);
    }
    order.pb(node);
}
void dfs22(int node, int id){
    comp[node] = id;
    for (auto x : radj[node]){
        if (comp[x] || (node == b && x == a)) continue;
        dfs22(x, id);
    }
}

bool kosaraju2(){
    fill(vis, vis + n + 2, 0);
    fill(comp, comp + n + 2, 0);
    order.clear();
    for (int i=1;i<=n;i++){
        if (!vis[i]){
            dfs12(i);
        }
    }
    int j = 0;
    for (int i=n - 1;i>=0;i--){
        int cur = order[i];
        if (!comp[cur]){
            ++j;
            dfs22(cur, j);
        }
    }
    return j == n;
}
vector<pii> v;
bool ok = 0;
void solve(){
    for (auto x : v){
        a = x.fi, b = x.se;
        if (kosaraju2()){
            ok = 1;
            break;
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        radj[b].pb(a);
    }
    kosaraju();
    int cnt = 0, id = -1;
    for (int i=1;i<=n;i++){
        if (vcomp[i].size() > 1){
            cnt++;
            id = i;
        }
    }
    if (cnt == 0){
        cout << "YES" << el;
        return 0;
    } else if (cnt > 1){
        cout << "NO" << el;
        return 0;
    }
    for (auto x : vcomp[id]){
        int cntin = 0, cntout = 0, yin = -1, yout = -1;
        for (auto y : adj[x]){
            if (comp[y] == comp[x]){
                cntin++;
                yin = y;
            }
        }
        for (auto y : radj[x]){
            if (comp[y] == comp[x]){
                cntout++;
                yout = y;
            }
        }
        if (cntin == 1){
            v.pb(mp(x, yin)); 
        } 
        if (cntout == 1){
            v.pb(mp(yout, x));
        }
    }
    solve();
    if (ok) {
        cout << "YES" << el;
    } else{
        cout << "NO" << el;
    }

    return 0;
}
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

const int N = 2e5 + 10, M = 18;
const int INF = 1e9 + 7;

int tc, q;
int n;
int ar[N];

vector<int> adl[N];

int timer;
int tin[N], tout[N];
pair<int, pii> up[N][M]; // node naik, minimum1, minimum2

pii addto(pii a, int baru){
    if (a.fi > baru){
        a.se = a.fi;
        a.fi = baru;
    } else if (a.se > baru){
        a.se = baru;
    }
    return a;
}

pii merge(pii a, pii b){
    int ar[4] = {a.fi, a.se, b.fi, b.se};
    sort(ar, ar + 4);
    return mp(ar[0], ar[1]);
}

void init(){
    timer = 0;
    tin[0] = -1;
    tout[0] = INF;
    for (int i=1;i<=n;i++){
        adl[i].clear();
        for (int j=0;j<M;j++){
            up[i][j].se = mp(INF, INF);
        }
    }
}

void dfs(int node, int p){
    tin[node] = ++timer;
    up[node][0] = mp(p, addto(up[node][0].se, ar[node]));
    for (int i=1;i<M;i++){
        up[node][i] = mp(up[up[node][i - 1].fi][i - 1].fi, merge(up[node][i - 1].se, up[up[node][i - 1].fi][i - 1].se));
    }
    for (auto x : adl[node]){
        if (x == p) continue;
        dfs(x, node);
    }
    tout[node] = ++timer;
}

bool is_ancestor(int a, int b){
    return tin[a] <= tin[b] && tout[b] <= tout[a];
}

pii LCA(int a, int b){
    if (is_ancestor(b, a)){
        swap(a, b);
    }

    pii ans = mp(INF, INF);
    if (!is_ancestor(a, b)){
        for (int i=M - 1;i>=0;i--){
            if (!is_ancestor(up[a][i].fi, b)){
                ans = merge(ans, up[a][i].se);
                a = up[a][i].fi;
            }
        }
        ans = merge(ans, up[a][0].se);
        a = up[a][0].fi;
    }
    for (int i=M - 1;i>=0;i--){
        if (!is_ancestor(up[b][i].fi, a)){
            ans = merge(ans, up[b][i].se);
            b = up[b][i].fi;
        }
    }
    ans = merge(ans, up[b][0].se);
    cout << a << el;
    return addto(ans, ar[a]);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--){
        cin >> n >> q;
        init();
        for (int i=1;i<=n;i++){
            cin >> ar[i];
        }
        for (int i=1;i<n;i++){
            int a, b;
            cin >> a >> b;
            adl[a].pb(b);
            adl[b].pb(a);
        }
        dfs(1, 1);
        while (q--){
            int u, v;
            cin >> u >> v;
            pii lca = LCA(u, v);
            cout << lca.fi << " " << lca.se << el;
            cout << abs(lca.se - lca.fi) << el;
        }
    }

    return 0;
}
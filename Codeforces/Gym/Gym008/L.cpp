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

const int N = 1e5 + 10, M = 18;

int n, q;
vector<int> adl[N];

int tin[N], tout[N], timer;
int up[N][M], dep[N];

void dfs(int node, int p){
    tin[node] = ++timer;
    dep[node] = dep[p] + 1;
    up[node][0] = p;
    for (int i=1;i<M;i++){
        up[node][i] = up[up[node][i - 1]][i - 1];
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
int LCA(int a, int b){
    if (is_ancestor(a, b)) return a;
    if (is_ancestor(b, a)) return b;
    for (int i=M - 1;i>=0;i--){
        if (!is_ancestor(up[a][i], b)) a = up[a][i];
    }
    return up[a][0];
}
pii inter(int a, int b, int c, int d){ // b dan d LCA a dan c
    pii ret = mp(-1, -1);
    if (is_ancestor(b, d)){
        ret = mp(LCA(a, c), d);
    } else if (is_ancestor(d, b)){
        ret = mp(LCA(a, c), b);
    }
    if (ret != mp(-1, -1)){
        if (dep[ret.fi] < dep[ret.se]) ret = mp(-1, -1);
    }
    return ret;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    for (int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adl[a].pb(b);
        adl[b].pb(a);
    }
    dfs(1, 1);

    while (q--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        int lca1 = LCA(a, b);
        int lca2 = LCA(c, d);
        vector<pii> v; // candidate
        int ans = 0;
        pii temp = inter(a, lca1, c, lca2);
        if (temp != mp(-1, -1)){
            v.pb(temp);
            ans += dep[temp.fi] - dep[temp.se] + 1;
        }
        temp = inter(a, lca1, d, lca2);
        if (temp != mp(-1, -1)){
            v.pb(temp);
            ans += dep[temp.fi] - dep[temp.se] + 1;
        }
        temp = inter(b, lca1, c, lca2);
        if (temp != mp(-1, -1)){
            v.pb(temp);
            ans += dep[temp.fi] - dep[temp.se] + 1;
        }
        temp = inter(b, lca1, d, lca2);
        if (temp != mp(-1, -1)){
            v.pb(temp);
            ans += dep[temp.fi] - dep[temp.se] + 1;
        }
        if (!v.empty()) ans -= v.size() - 1;
        cout << ans << el;
    }

    return 0;
}
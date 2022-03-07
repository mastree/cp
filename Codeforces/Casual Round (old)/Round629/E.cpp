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

const int N = 2e5 + 10;

int n, m;
vector <int> adl[N];
// int par[N];

const int l = 17;

int timer;
int tin[N], tout[N];
int depth[N];
int up[N][l + 1];

void dfs(int v, int p)
{
    tin[v] = ++timer;
    up[v][0] = p;
    depth[v] = depth[p] + 1;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adl[v]) {
        if (u != p)
            dfs(u, v);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adl[a].pb(b);
        adl[b].pb(a);
    }
    // dfsPar(1, 1);
    dfs(1, 1);

    while (m--){
        int k;
        cin >> k;
        pii ask[k + 1];
        for (int i=1;i<=k;i++){
            cin >> ask[i].se;
            ask[i].fi = depth[ask[i].se];
        }
        if (k == 1){
            cout << "YES" << el;
            continue; 
        }

        sort(ask + 1, ask + k + 1);
        pii temp = ask[k];
        int p = up[temp.se][0];
        bool bisa = 1;
        for (int i=k - 1;i>=1;i--){
            if (temp.fi == ask[i].fi){
                if (temp.se == ask[i].se) continue;
                if (up[ask[i].se][0] == p) continue;
                else{
                    bisa = 0;
                    break;
                }
            } else{
                break;
            }
        }

        if (bisa == 0){
            cout << "NO" << el;
            continue;
        }
        // int u = p;

        for (int i=1;i<=k;i++){
            if (is_ancestor(ask[i].se, p) || is_ancestor(up[ask[i].se][0], p)) continue;
            bisa = 0;
            break;
        }
        if (bisa){
            cout << "YES" << el;
        } else{
            cout << "NO" << el;
        }
    }

    return 0;
}
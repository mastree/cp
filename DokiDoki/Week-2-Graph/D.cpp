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

int n, m;
vector<int> adj[N];

int col[N];
bool dfs(int node){
    bool ada[2] = {0, 0};
    for (auto x : adj[node]){
        if (col[x] != -1) ada[col[x]] = 1;
    }
    if (!ada[0]) col[node] = 0;
    else if (!ada[1]) col[node] = 1;
    else return 0;
    bool ret = 1;
    for (auto x : adj[node]){
        if (col[x] == -1){
            ret &= dfs(x);
        }
    }
    return ret;
}
vector<int> ans[2];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    fill(col, col + n + 3, -1);
    for (int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    bool ok = 1;
    for (int i=1;i<=n;i++){
        if (col[i] == -1){
            ok &= dfs(i);
        }
        if (!ok) break;
    }
    if (!ok){
        cout << -1 << el;
        return 0;
    }
    for (int i=1;i<=n;i++){
        ans[col[i]].pb(i);
    }
    for (int i=0;i<2;i++){
        cout << ans[i].size() << el;
        for (auto x : ans[i]) cout << x << " ";
        cout << el;
    }

    return 0;
}
#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 210;

int q;
int n, m;
set<pii> adj[N];
bool ada[N][N];
int deg[N];

bool vis[N];
vector<pii> ans;
void init(){
    for (int i=0;i<N;i++){
        adj[i].clear();
        deg[i] = 0;
        fill(ada[i], ada[i] + N, 0);
        vis[i] = 0;
    }
    ans.clear();
}
vector<int> path;
void dfs(int node){
    vis[node] = 1;
    while (!adj[node].empty()){
        auto nnode = *adj[node].begin();
        adj[node].erase(nnode);
        adj[nnode.fi].erase(mp(node, nnode.se));
        dfs(nnode.fi);
    }
    path.pb(node);
}

void solve(){
    cin >> n >> m;
    init();
    for (int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].insert(mp(b, 0));
        adj[b].insert(mp(a, 0));
        ada[a][b] = ada[b][a] = 1;
        deg[a]++;
        deg[b]++;
    }
    int cnt = 0;
    {
        vector<int> need;
        for (int i=1;i<=n;i++){
            if (deg[i] & 1){
                need.pb(i);
            } else cnt++;
        }
        int len = need.size();
        assert(len & 1 ^ 1);
        for (int i=0;i<len;i+=2){
            int ni = i + 1;
            adj[need[i]].insert(mp(need[ni], 1));
            adj[need[ni]].insert(mp(need[i], 1));
        }
    }
    for (int i=1;i<=n;i++){
        if (!vis[i]){
            path.clear();
            dfs(i);
            int len = path.size();
            for (int j=0;j<len - 1;j++){
                int nj = j + 1;
                if (ada[path[j]][path[nj]]){
                    ada[path[j]][path[nj]] = 0;
                    ada[path[nj]][path[j]] = 0;
                    ans.pb(mp(path[j], path[nj]));
                }
            }
        }
    }
    cout << cnt << el;
    for (auto x : ans){
        cout << x.fi << " " << x.se << el;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        solve();
    }

    return 0;
}
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
vector<int> adl[N], radl[N];
bool vis[N];
vector<int> order;
int component[N];

void dfs1(int node){
    vis[node] = 1;
    for (auto x : adl[node]){
        if (!vis[x]) dfs1(x);
    }
    order.pb(node);
}
void dfs2(int node, int id){
    vis[node] = 1;
    component[node] = id;
    for (auto x : radl[node]){
        if (!vis[x]) dfs2(x, id);
    }
}

void kosaraju(){
    fill(vis, vis + N, 0);
    fill(component, component + N, 0);
    order.clear();
    for (int i=1;i<=n;i++){
        if (!vis[i]) dfs1(i);
    }
    fill(vis, vis + N, 0);
    int comp_id = 0;
    for (int i=n - 1;i>=0;i--){
        int v = order[i];
        if (!vis[v]) dfs2(v, ++comp_id);
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
        adl[a].pb(b);
        radl[b].pb(a);
    }
    kosaraju();
    for (int i=1;i<=n;i++){
        cout << i << " " << component[i] << el;
    }

    return 0;
}
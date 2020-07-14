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
vector<int> adl[N];

int par[N], sz[N];
vector<int> g[N];
vector<int> gcol[N][2];
int color[N];
int ans[N];

void init(){
    for (int i=1;i<=n;i++){
        sz[i] = 1;
        par[i] = i;
        color[i] = -1;
    }
}

int find(int a){
    if (par[a] == a) return a;
    return par[a] = find(par[a]);
}

void make(int a, int b){
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    par[b] = a;
}

void dfs(int node, int p){
    make(node, p);
    for (auto x : adl[node]){
        if (find(x) == find(node)) continue;
        dfs(x, node);
    }
} 

void dfs_color(int node, int p, int id){
    bool ok1 = 1;
    for (auto x : adl[node]){
        if (color[x] == 1) ok1 = 0;
    }
    if (ok1) color[node] = 1;
    else color[node] = 0;
    for (auto x : adl[node]){
        if (color[x] != -1) continue;
        dfs_color(x, node, id);
    }
    if (color[node] == 1) gcol[find(node)][id].pb(node);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    init();
    for (int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        adl[a].pb(b);
        adl[b].pb(a);
    }
    for (int i=1;i<=n;i++){
        if (par[i] == i && sz[i] == 1){
            dfs(i, i);
        }
    }
    for (int i=1;i<=n;i++) g[find(i)].pb(i);
    int temp = 0;
    for (int i=1;i<=n;i++){
        if (par[i] == i){
            temp++;
            dfs_color(i, i, 0);
            if (sz[i] > 1){
                int can = -1;
                for (auto x : g[i]){
                    if (color[x] == 0){
                        can = x;
                        break;
                    } 
                }
                if (can != -1){
                    for (auto x : g[i]){
                        color[x] = -1;
                    }
                    dfs_color(can, can, 1);
                }
            }
        }
    }
    int tot = 0;
    for (int i=1;i<=n;i++){
        if (par[i] == i){
            bool id = 1;
            if (gcol[i][0].size() > gcol[i][1].size()){
                id = 0;
            }
            tot += (int) gcol[i][id].size();
            for (auto x : gcol[i][id]) ans[x] = 1;
        }
    }
    cout << tot << el;
    for (int i=1;i<=n;i++) cout << ans[i] << " ";
    cout << el; 

    return 0;
}
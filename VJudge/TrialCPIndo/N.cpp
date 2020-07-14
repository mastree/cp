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
vector<int> v[N];

int par[N], sz[N], color[N], parent[N];
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
void init(){
    for (int i=1;i<=n;i++){
        par[i] = i;
        sz[i] = 1;
    }
}

void dfs_cycle(int node, int p){
    if (color[node] == 2) return;
    if (color[node]){
        int cur = p;
        while (find(cur) != find(node)){
            make(cur, parent[cur]);
            cur = parent[cur];
        }
        return;
    }
    parent[node] = p;
    color[node] = 1;
    for (auto x : adl[node]){
        if (x == p) continue;
        dfs_cycle(x, node);
    }
    color[node] = 2;
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
        if (color[i] == 0){
            dfs_cycle(i, i);
        }
    }
    int ans = 0;
    for (int i=1;i<=n;i++){
        v[find(i)].pb(i);
    }
    for (int i=1;i<=n;i++){
        if ((int) v[i].size() >= 3){
            int tot = 0;
            for (auto x : v[i]){
                tot += (int) adl[x].size();
            }
            if (sz[i] * 2 == tot) ans++;
        }
    }
    cout << ans << el;

    return 0;
}
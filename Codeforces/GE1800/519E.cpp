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

const int N = 1e5 + 10;
const int M = 19;

int n, q;
vector <int> adl[N];

int timer, tin[N], tout[N], dep[N], sz[N];
int up[N][M];

void dfs_init(int node, int p){
    if (node != p) dep[node] = dep[p] + 1;
    timer++;
    tin[node] = timer;
    up[node][0] = p;
    sz[node] = 1;
    for (auto x : adl[node]){
        if (x == p) continue;
        dfs_init(x, node);
        sz[node] += sz[x];
    }
    timer++;
    tout[node] = timer;
}

void init(){
    dfs_init(1, 1);
    for (int j=1;j<M;j++){
        for (int i=1;i<=n;i++){
            up[i][j] = up[up[i][j - 1]][j - 1];
        }
    }
}

// a is ancestor of b
int is_ancestor(int a, int b){
    return tin[a] <= tin[b] && tout[b] <= tout[a];
}

int LCA(int a, int b){
    if (is_ancestor(a, b)) return a;
    else if (is_ancestor(b, a)) return b;

    for (int i=M - 1;i>=0;i--){
        if (is_ancestor(up[a][i], b)) continue;
        a = up[a][i];
    }
    return up[a][0];
}

int naikx(int a, int x){
    for (int i=M - 1;i>=0;i--){
        if (x < (1 << i)) continue;
        a = up[a][i];
        x -= (1 << i);
    }
    return a;
}

int fmid(int a, int b){
    int c = LCA(a, b);
    int ja = dep[a] - dep[c];
    int jb = dep[b] - dep[c];
    if ((ja + jb) & 1) return -1;
    int jarak = (ja + jb) / 2;
    if (dep[a] < dep[b]) swap(a, b);
    return naikx(a, jarak);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adl[a].pb(b);
        adl[b].pb(a);
    }
    init();
    cin >> q;
    while (q--){
        int a, b;
        cin >> a >> b;
        if (a == b){
            cout << n << el;
            continue;
        }
        if (dep[a] < dep[b]) swap(a, b);
        int mid = fmid(a, b);
        if (mid == -1){
            cout << 0 << el;
            continue;
        }
        int jarak = dep[a] - dep[mid];
        int ans = 0;
        if (!is_ancestor(mid, b)){
            ans = sz[mid] - sz[naikx(a, jarak - 1)];
        } else{
            int na = naikx(a, jarak - 1);
            int nb = naikx(b, jarak - 1);
            ans = n - sz[na] - sz[nb];
        }
        cout << ans << el;
    }

    return 0;
}
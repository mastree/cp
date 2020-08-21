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

int n, m, k;
vector<int> adl[N];

int ambil[N];
vector<int> vans;
int root;

int par[N], sz[N], parent[N], color[N];

int find(int a){
    if (par[a] == a) return a;
    return par[a] = find(par[a]);
}
void make(int a, int b){
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
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
        while(find(cur) != find(node)){
            make(cur, node);
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

void dfs_iset(int node){
    bool ada = 0;
    for (auto x : adl[node]){
        if (ambil[x]){
            if (ambil[x] == 1){
                ada = 1;
            } 
            continue;
        }
    }
    if (ada) ambil[node] = -1;
    else ambil[node] = 1;
    for (auto x : adl[node]){
        if (!ambil[x]){
            dfs_iset(x);
        }
    }
}

pii dp[N]; // min jarak, node parent
void bfs(int root){
    dp[0] = mp(-1, 0);
    for (int i=1;i<=n;i++){
        dp[i] = mp(MOD, 0);
    }
    queue<pii> qu;
    qu.push(mp(root, 0)); // node, parent
    int nemu1 = 0, nemu2 = 0;
    int lup = 0;
    while (!nemu1){
        auto temp = qu.front();
        qu.pop();
        int node = temp.fi;
        int p = temp.se;
        if (dp[node].fi <= dp[p].fi + 1) continue;
        dp[node] = mp(dp[p].fi + 1, p);

        for (auto x : adl[node]){
            if (x == p) continue;
            if (dp[x].fi != MOD){
                if (dp[x].fi + dp[node].fi + 1 <= k){
                    nemu1 = node;
                    nemu2 = x;
                    break;
                }
            }
            if (dp[x].fi > dp[node].fi + 1){
                qu.push(mp(x, node));
            }
        }
    }

    vans.pb(nemu1);
    while (nemu1 != root){
        nemu1 = dp[nemu1].se;
        vans.pb(nemu1); 
    }
    reverse(vans.begin(), vans.end());
    while (nemu2 != root){
        vans.pb(nemu2);
        nemu2 = dp[nemu2].se;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    init();
    for (int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        adl[a].pb(b);
        adl[b].pb(a);
    }
    vector<int> v;
    int iset = (k + 1) / 2;
    dfs_iset(1);
    for (int i=1;i<=n;i++){
        if (ambil[i] == 1){
            v.pb(i);
        }
    }
    if ((int) v.size() >= iset){
        cout << 1 << el;
        for (int i=0;i<iset;i++){
            cout << v[i] << " ";
        }
        cout << el;
        return 0;
    }
    v.clear();
    fill(ambil, ambil + n + 2, 0);
    dfs_iset(adl[1][0]);
    for (int i=1;i<=n;i++){
        if (ambil[i] == 1){
            v.pb(i);
        }
    }
    if ((int) v.size() >= iset){
        cout << 1 << el;
        for (int i=0;i<iset;i++){
            cout << v[i] << " ";
        }
        cout << el;
        return 0;
    }
    dfs_cycle(1, 1);
    for (int i=1;i<=n;i++){
        if (par[i] == i && sz[i] >= 3){
            root = i;
            break;
        }
    }
    bfs(root);
    cout << 2 << el;
    cout << vans.size() << el;
    for (auto x : vans){
        cout << x << " ";
    }
    cout << el;

    return 0;
}
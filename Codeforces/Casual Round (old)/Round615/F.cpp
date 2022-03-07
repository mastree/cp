#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define ll long long
#define el '\n'

using namespace std;

const int N = 2e5 + 10;

int n;
vector <int> adl[N];

int u, v, h, curh;
int par[N];

bool jalur[N];

int w;

void dfs_u(int node, int p){
    if (curh<h){
        curh = h;
        u = node;
    }
    h++;
    for (auto x : adl[node]){
        if (x != p){
            dfs_u(x, node);
        }
    }
    h--;
}

void dfs_v(int node, int p){
    if (curh<h){
        curh = h;
        v = node;
    }
    par[node] = p;
    h++;
    for (auto x : adl[node]){
        if (x != p){
            dfs_v(x, node);
        }
    }
    h--;
}

void dfs(int node, int p){
    if (curh<h){
        curh = h;
        w = node;
    }
    h++;
    for (auto x : adl[node]){
        if (x != p && jalur[x] == 0){
            dfs(x, node);
        }
    }
    h--;
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

    dfs_u(1, 0);
    curh = 0;h = 0;
    dfs_v(u, 0);

    int cur = v;
    int ans = curh;
    while (cur != 0){
        jalur[cur] = 1;
        // ans++;
        cur = par[cur];
    }

    curh = 0;
    w = par[v];
    for (int i=1;i<=n;i++){
        if (jalur[i]){
            h = 0;
            dfs(i, 0);
        }
    }

    cout << ans + curh << el;
    cout << u << " " << v << " " << w << el;

    return 0;
}
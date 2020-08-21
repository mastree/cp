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
vector <int> adl1[N], adl2[N];

int par[N], sz[N];

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

void dfs1(int node){
    for (auto x : adl1[node]){
        if (find(node) == find(x)) continue;
        make(node, x);
        dfs1(x);
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    for (int i=1;i<=n;i++){
        par[i] = i;
        sz[i] = 1;
    }
    for (int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        adl1[a].pb(b);
        adl1[b].pb(a);
    }

    for (int i=1;i<=k;i++){
        int a, b;
        cin >> a >> b;
        adl2[a].pb(b);
        adl2[b].pb(a);
    }

    for (int i=1;i<=n;i++){
        if (find(i) == i && sz[i] == 1){
            dfs1(i);
        }
    }

    for (int i=1;i<=n;i++){
        int kur = 0;
        int p = find(i);
        for (auto x : adl2[i]){
            if (find(x) == p) kur++;
        }
        cout << sz[p] - kur - (int)adl1[i].size() - 1 << " ";
    }
    cout << el;

    return 0;
}
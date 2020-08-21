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

int n;
set <int> adl[N];
int sz[N];
int cpar[N]; // centroid parent
vector <int> vadl[N];
int dep[N];

void dfs_subtree(int node, int p){
    sz[node] = 1;
    for (auto x : adl[node]){
        if (x == p) continue;
        dfs_subtree(x, node);
        sz[node] += sz[x];
    }
}

int centroid(int node, int p, int size){
    for (auto x : adl[node]){
        if (x == p) continue;
        if (sz[x] > size / 2) return centroid(x, node, size);
    }
    return node;
}

void decomp(int node, int p){
    dfs_subtree(node, p);
    int ctr = centroid(node, p, sz[node]);
    cpar[ctr] = p;
    for (auto x : adl[ctr]){
        adl[x].erase(ctr);
        decomp(x, ctr);
    }
    adl[ctr].clear();
}

void dfs_dep(int node, int p){
    if (p != -1) dep[node] = dep[p] + 1;
    for (auto x : vadl[node]){
        if (x == p) continue;
        dfs_dep(x, node);
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adl[a].insert(b);
        adl[b].insert(a);
    }
    decomp(1, -1);
    int root = 0;
    for (int i=1;i<=n;i++){
        if (cpar[i] == -1) root = i;
        if (cpar[i] == -1 || cpar[i] == i) continue;
        vadl[cpar[i]].pb(i);
        vadl[i].pb(cpar[i]);
    }
    dfs_dep(root, -1);
    int mx = 0;
    for (int i=1;i<=n;i++){
        mx = max(mx, dep[i]);
    }
    if (mx >= 26){
        cout << "IMPOSSIBLE" << el;
    } else{
        for (int i=1;i<=n;i++){
            char ch = dep[i] + 'A';
            cout << ch << " ";
        }
        cout << el;
    }

    return 0;
}
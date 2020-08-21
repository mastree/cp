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
const int INF = 1e9;

int n, m;
set <int> adl[N];

int timer;
int tin[N], tout[N];
int up[N][18];
int depth[N];

int sz[N];
int ans[N];
int cpar[N];


void bLCA(int node, int p){
    if (node != p) depth[node] = depth[p] + 1;
    tin[node] = ++timer;
    up[node][0] = p;
    for (int i = 1; i < 18; ++i)
        up[node][i] = up[up[node][i-1]][i-1];

    for (auto x : adl[node]){
        if (x != p){
            bLCA(x, node);
        }
    }
    tout[node] = ++timer;
}

bool isAncestor(int a, int b){
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int LCA(int a, int b){
    if (isAncestor(a, b)) return a;
    if (isAncestor(b, a)) return b;

    for (int i=17;i>=0;i--){
        if (!isAncestor(up[a][i], b)){
            a = up[a][i];
        }
    }
    return up[a][0];
}

int dist(int a, int b){
    return depth[a] + depth[b] - 2 * depth[LCA(a, b)];
}

void dfsSubtree(int node, int p){
    sz[node] = 1;
    for (auto x : adl[node]){
        if (x != p){
            dfsSubtree(x, node);
            sz[node] += sz[x];
        }
    }
}

int dfsCentroid(int node, int p, int size){
    for (auto x : adl[node]){
        if (x != p){
            if (sz[x] > size / 2) return dfsCentroid(x, node, size);
        }
    }
    return node;
}

void decompose(int node, int p){
    dfsSubtree(node, p);
    int ctr = dfsCentroid(node, node, sz[node]);
    if (p == -1) p = ctr;
    cpar[ctr] = p;
    for (auto x : adl[ctr]){
        adl[x].erase(ctr);
        decompose(x, ctr);
    }
    adl[ctr].clear();
}

int ask(int a){
    int start = a;
    int res = INF;
    while (1){
        res = min(res, dist(start, a) + ans[a]);
        if (a == cpar[a]) break;
        a = cpar[a];
    }
    return res;
}

void update(int a){
    int newR = a;
    while (1){
        ans[a] = min(ans[a], dist(newR, a));
        if (a == cpar[a]) break;
        a = cpar[a];
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adl[a].insert(b);
        adl[b].insert(a);
    }

    bLCA(1, 1);
    decompose(1, -1);
    fill(ans, ans + n + 2, INF);
    update(1);

    while (m--){
        int t, a;
        cin >> t >> a;
        if (t == 1){
            update(a);
        } else{
            cout << ask(a) << el;
        }
    }

    return 0;
}
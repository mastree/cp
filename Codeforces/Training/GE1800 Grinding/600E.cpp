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
vector <int> adl[N];
ll col[N];
int root;

map <int, int> cnt[N]; // node, color, count
int sz[N];
int par[N];
pair<ll, int> ans[N]; // total, count
pair<ll, int> cur; // total, count

ll jawab[N];

int find(int a){
    if (par[a] == a) return a;
    return par[a] = find(par[a]);
}

void merge(int u, int v){
    u = find(u);
    v = find(v);
    if (sz[u] > sz[v]) swap(u, v);
    cur = ans[v];

    for (auto x : cnt[u]){
        cnt[v][x.fi] += x.se;
        if (cnt[v][x.fi] > cur.se){
            cur = mp(x.fi, cnt[v][x.fi]);
        } else if (cnt[v][x.fi] == cur.se){
            cur.fi += x.fi;
        }
    }

    par[u] = v;
    sz[v] += sz[u];
    ans[v] = cur;
}

void dfs(int node, int p){
    for (auto child : adl[node]){
        if (child == p) continue;
        dfs(child, node);
        merge(node, child);
    }

    jawab[node] = ans[find(node)].fi;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i=1;i<=n;i++){
        cin >> col[i];
        par[i] = i;
        cnt[i][col[i]]++;
        sz[i] = 1;
        ans[i] = mp(col[i], 1);
    }
    for (int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adl[a].pb(b);
        adl[b].pb(a);
    }

    root = 1;
    dfs(root, root);
    for (int i=1;i<=n;i++){
        cout << jawab[i] << " ";
    }
    cout << el;

    return 0;
}
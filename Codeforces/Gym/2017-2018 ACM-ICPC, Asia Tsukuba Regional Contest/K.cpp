#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e5 + 10;

int n, m;
vector<int> adj[N];

int par[N], sz[N];
bool simple[N];

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
    sz[a] += b;
    simple[a] = (simple[a] && simple[b]);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for (int i=1;i<=n;i++){
        int deg = adj[i].size();
        par[i] = i;
        sz[i] = 1;
        simple[i] = (deg == 2);
    }
    for (int i=1;i<=n;i++){
        for (auto& x : adj[i]){
            make(i, x);
        }
    }
    int ans = 0;
    for (int i=1;i<=n;i++){
        if (par[i] == i){
            ans += simple[i];
        }
    }
    cout << ans << el;

    return 0;
}
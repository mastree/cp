#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 3e5 + 10;

int q;
int n, m;
vector<vector<int>> adj;

int par[N], sz[N];
int find(int x){
    return (par[x] == x) ? x : par[x] = find(par[x]);
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

void solve(){
    cin >> n >> m;
    init();
    adj.clear();
    adj.resize(n + 1);
    for (int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
        make(a, b);
    }
    if (sz[find(1)] != n){
        cout << "NO" << el;
        return;
    }
    {
        vector<bool> vis(n + 1, 0);
        vector<int> col(n + 1, -1);
        queue<int> qu;
        
        qu.push(1);
        while (!qu.empty()){
            int node = qu.front();
            qu.pop();
            if (vis[node]) continue;
            bool ada = 0;
            for (auto x : adj[node]){
                if (vis[x] && col[x]){
                    ada = 1;
                    break;
                }
            }
            vis[node] = 1;
            if (!ada){
                col[node] = 1;
            } else{
                col[node] = 0;
            }
            for (auto x : adj[node]){
                if (!vis[x]){
                    qu.push(x);
                }
            }
        }
        init();
        for (int i=1;i<=n;i++){
            for (auto x : adj[i]){
                if (col[i] == 1 || col[x] == 1) make(i, x);
            }
        }
        if (sz[find(1)] == n){
            cout << "YES" << el;
            vector<int> warna;
            for (int i=1;i<=n;i++){
                if (col[i] == 1) warna.pb(i);
            }
            cout << warna.size() << el;
            for (auto x : warna) cout << x << " ";
            cout << el;
            return;
        }
    }
    {
        vector<bool> vis(n + 1, 0);
        vector<int> col(n + 1, -1);
        queue<int> qu;
        
        int cnt = 0;
        qu.push(adj[1][0]);
        while (!qu.empty()){
            int node = qu.front();
            qu.pop();
            if (vis[node]) continue;
            bool ada = 0;
            for (auto x : adj[node]){
                if (col[x] && col[x]){
                    ada = 1;
                    break;
                }
            }
            vis[node] = 1;
            if (!ada){
                col[node] = 1;
            } else{
                col[node] = 0;
            }
            for (auto x : adj[node]){
                if (!vis[x]){
                    qu.push(x);
                }
            }
        }
        init();
        for (int i=1;i<=n;i++){
            for (auto x : adj[i]){
                if (col[i] == 1 || col[x] == 1) make(i, x);
            }
        }
        if (sz[find(1)] == n){
            cout << "YES" << el;
            vector<int> warna;
            for (int i=1;i<=n;i++){
                if (vis[i] == 1) warna.pb(i);
            }
            cout << warna.size() << el;
            for (auto x : warna) cout << x << " ";
            cout << el;
            return;
        }
    }
    cout << "NO" << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        solve();
    }

    return 0;
}
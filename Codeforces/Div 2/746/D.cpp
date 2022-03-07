#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e3 + 10;

int n;
vector<int> adj[N];
bool masih[N];
int root;

int sz[N], parent[N];

void dfs_size(int node, int p){
    sz[node] = 1;
    parent[node] = p;
    for (auto& x : adj[node]){
        if (x == p || !masih[node]) continue;
        dfs_size(x, node);
        sz[node] += sz[x];
    }
}
void dfs_take(int node, int p, vector<bool>& taken){
    taken[node] = 1;
    for (auto& x : adj[node]){
        if (x == p || !masih[node]) continue;
        dfs_take(x, node, taken);
    }
}

vector<int> t[2];

void init_query(){
    for (int i=1;i<=n;i++){
        if (masih[i]){
            root = i;
            dfs_size(i, i);
            break;
        }
    }
    pii cand = {-1, -1}; // size, node
    for (int i=1;i<=n;i++){
        if (masih[i] && parent[i] != i){
            if (abs(sz[root] - (sz[i] + 1)* 2) <= 1){
                cand = max(cand, mp(sz[i] + 1, i));
                break;
            }
        }
    }
    vector<bool> taken(n, 0);
    dfs_take(cand.se, parent[cand.se], taken);
    t[0].clear();
    t[1].clear();
    for (int i=1;i<=n;i++){
        if (masih[i]){
            t[taken[i]].pb(i);
            if (i == parent[cand.se]) t[1].pb(i);
        }
    }
}

int ask(const vector<int>& vec){
    cout << "? " << vec.size() << ' ';
    for (auto& x : vec) cout << x << ' ';
    cout << endl;
    int res;
    cin >> res;
    return res; 
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    int mx;
    {
        vector<int> vec;
        for (int i=1;i<=n;i++) vec.pb(i);
        mx = ask(vec);
    }

    fill(masih, masih + n + 1, 1);
    while (1){
        init_query();
        int temp = ask(t[0]);
        if (temp == mx){
            for (auto& x : t[1]) masih[x] = 0;
            for (auto& x : t[0]) masih[x] = 1;
        } else{
            for (auto& x : t[0]) masih[x] = 0;
            for (auto& x : t[1]) masih[x] = 1;
        }
        vector<int> sisa;
        for (int i=1;i<=n;i++) if (masih[i]) {
            sisa.pb(i);
        }
        if (sisa.size() <= 2){
            cout << "! ";
            for (auto& x : sisa) cout << x << ' ';
            cout << endl;
            return 0;
        }
    }

    return 0;
}
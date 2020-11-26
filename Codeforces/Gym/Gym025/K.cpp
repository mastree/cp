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

int n, root;
vector<int> adj[N];
vector<pii> ans;

int sz[N];

vector<int> leaf;
bool is_leaf[N];

void dfs(int node, int p){
    if (adj[node].size() == 1 && node != p){
        is_leaf[node] = 1;
        sz[node] = 1;
        return;
    }
    for (auto x : adj[node]){
        if (x == p) continue;
        dfs(x, node);
        sz[node] += sz[x];
    }
}
int ltot = 0;
int find_center(int node, int p){
    for (auto x : adj[node]){
        if (x == p) continue;
        if (sz[x] > ltot - sz[x]) return find_center(x, node);
    }
    return node;
}

int cab[N];
int tcab;
void dfs_cab(int node, int p){
    cab[node] = tcab;
    for (auto x : adj[node]){
        if (x == p) continue;
        dfs_cab(x, node);
    }
}
vector<int> vcab[N];
bool path[N];

int bikin(int node, int p){
    if (adj[node].size() == 1){
        is_leaf[node] = 0;
        return node;
    }
    for (auto x : adj[node]){
        if (x == p || path[x]) continue;
        int temp = bikin(x, node);
        if (temp) return temp;
    }
    return 0;
}
bool tandai(int node, int p, int nroot){
    if (node == nroot){
        path[node] = 1;
        return 1;
    }
    bool ret = 0;
    for (auto x : adj[node]){
        if (x == p) continue;
        ret |= tandai(x, node, nroot);
    }
    if (ret) path[node] = 1;
    return ret;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> root;
    int rroot = root;
    for (int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(root, root);
    ltot = (adj[root].size() == 1);
    for (int i=0;i<n;i++) if (is_leaf[i]) ltot++;
    {   
        if (sz[root] > 1){
            int nroot = find_center(root, root);
            if (nroot != root){
                tandai(root, root, nroot);
                int a = bikin(root, root);
                root = nroot;
                int b = bikin(root, root);
                ans.pb(mp(a, b));
            }
        }
        for (int i=0;i<n;i++){
            if (is_leaf[i]) leaf.pb(i);
        }
    }
    for (auto x : adj[root]){
        tcab = x;
        dfs_cab(x, root);
    }
    for (auto x : leaf){
        vcab[cab[x]].pb(x);
    }
    {
        set<pii> setdah;
        for (auto x : leaf){
            setdah.insert(mp((int)vcab[cab[x]].size(), cab[x]));
        }
        while (setdah.size() > 1){
            auto fr = *setdah.begin();
            auto bc = *setdah.rbegin();
 
            setdah.erase(fr);
            setdah.erase(bc);
            int a = vcab[fr.se].back();
            int b = vcab[bc.se].back();
            vcab[fr.se].pop_back();
            vcab[bc.se].pop_back();
            ans.pb(mp(a, b));
            if (vcab[fr.se].size()){
                setdah.insert(mp((int)vcab[fr.se].size(), fr.se));
            }
            if (vcab[bc.se].size()){
                setdah.insert(mp((int)vcab[bc.se].size(), bc.se));
            }
        }
        if (setdah.size()){
            int pos = setdah.begin()->se;
            for (auto x : vcab[pos]){
                ans.pb(mp(x, root));
            }
        }
    }
    assert((int)ans.size() == (ltot + 1) / 2);
    cout << ans.size() << el;
    for (auto x : ans){
        cout << x.fi << " " << x.se << el;
    }

    return 0;
}
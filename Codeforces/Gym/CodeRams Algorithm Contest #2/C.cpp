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

int n;
vector<int> adj[N];
bool leaf[N];

void dfs_leaf(int node, int p){
    if (node != 1) leaf[node] = 1;
    for (auto& x : adj[node]){
        if (x == p) continue;
        leaf[node] = 0;
        dfs_leaf(x, node);
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
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs_leaf(1, 1);
    int ans = 0;
    for (int i=2;i<=n;i++){
        if (adj[i].size() == 2){
            for (auto& x : adj[i]){
                if (leaf[x]){
                    ans++;
                    break;
                }
            }
        }
    }
    cout << ans << el;

    return 0;
}
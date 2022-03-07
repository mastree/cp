#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 55;

int q;
int n, k;
int ar[N];
vector<vector<int>> adj;
vector<vector<int>> path;
bool isleaf[N];

void dfs_init(int node, int p, vector<int>& cur_path){
    cur_path.pb(node);
    path[node] = cur_path;
    isleaf[node] = 1;
    for (auto& x : adj[node]){
        if (x == p) continue;
        isleaf[node] = 0;
        dfs_init(x, node, cur_path);
    }
    cur_path.pop_back();
}

void solve(){
    cin >> n >> k;
    adj.clear();
    adj.resize(n + 2, vector<int>());
    path.clear();
    path.resize(n + 2, vector<int>());
    fill(isleaf, isleaf + n + 2, 0);
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    for (int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    if (n == 1 || k == 0){
        cout << ar[1] << el;
        return;
    }
    n++;
    ar[n] = 0;
    adj[1].pb(n);
    adj[n].pb(1);
    {
        vector<int> cpath;
        dfs_init(1, 1, cpath);
    }
    for (int i=1;i<=n;i++){
        cout << i << " " << isleaf[i] << " => ";
        for (auto& x : path[i]) cout << x << ' ';
        cout << el;
    }
    int ans = ar[1];
    int leafcnt = 0;
    for (int i=1;i<=n;i++) if (isleaf[i]) leafcnt++;
    for (int last=1;last<=n;last++){
        if (!isleaf[last]) continue;
        vector<bool> vis(n + 1, 0);
        int skipc = 0;//path[last][1];

        int tot = 0;
        for (auto& x : path[last]){
            tot += ar[x];
            vis[x] = 1;
        }
        // cout << "last di: " << last << " => " << tot << el;
        int taken = 0;
        while (taken < k && taken < leafcnt - 1){
            vector<pii> cand; // score, node
            for (int i=1;i<=n;i++){
                if (!isleaf[i] || i == last || vis[i] || path[i][1] == skipc) continue;
                cand.emplace_back(0, i);
                for (auto& x : path[i]){
                    cand.back().fi += vis[x] ? 0 : ar[x];
                }
            }
            sort(cand.begin(), cand.end(), greater<pii>());
            if (cand.empty()) break;
            tot += cand[0].fi;
            for (auto& x : path[cand[0].se]) vis[x] = 1;
            taken++;
        }
        ans = max(ans, tot);
    }
    cout << ans << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    for (int i=1;i<=q;i++){
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}
#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e5 + 10;

int q;
int n;
pii ar[N];
vector<pii> adj[N];
unordered_map<int, int> arah[N];

bool vis[N], vis2[N];

void init(){
    fill(vis, vis + n + 2, 0);
    fill(vis2, vis2 + n + 2, 0);
    for (int i=1;i<=n;i++){
        adj[i].clear();
        arah[i].clear();
    }
}

int cur, sz;
void dfs(int node, int p){
    vis[node] = 1;
    sz++;
    for (auto x : adj[node]){
        if (x.fi == p) continue;
        if (vis[x.fi]){
            cur += x.se;
            continue;
        }
        cur += x.se;
        dfs(x.fi, node);
    }
}
void dfs2(int node, int p){
    vis2[node] = 1;
    for (auto x : adj[node]){
        if (x.fi == p) continue;
        if (vis2[x.fi]){
            arah[node][x.fi] = 1;
            continue;
        }
        arah[node][x.fi] = 1;
        dfs2(x.fi, node);
    }
}

void solve(){
    cin >> n;
    init();

    int cnt[n + 2];
    bool ok = 1;
    fill(cnt, cnt + n + 2, 0);
    for (int i=1;i<=n;i++){
        cin >> ar[i].fi;
        cnt[ar[i].fi]++;
        if (cnt[ar[i].fi] > 2) ok = 0;
    }
    for (int i=1;i<=n;i++){
        cin >> ar[i].se;
        cnt[ar[i].se]++;
        if (cnt[ar[i].se] > 2) ok = 0;
    }
    if (!ok){
        cout << -1 << el;
        return;
    }
    for (int i=1;i<=n;i++){
        adj[ar[i].fi].pb(mp(ar[i].se, 0));
        adj[ar[i].se].pb(mp(ar[i].fi, 1));
    }
    for (int i=1;i<=n;i++){
        if (!vis[i]){
            if (adj[i][0].fi == adj[i][1].fi){
                vis[i] = 1;
                vis[adj[i][0].fi] = 1;
                arah[i][adj[i][0].fi]++;
                arah[adj[i][0].fi][i]++;
                continue;
            }
            sz = cur = 0;
            dfs(i, adj[i][0].fi);
            if (cur <= sz / 2){
                dfs2(i, adj[i][0].fi);
            } else{
                dfs2(i, adj[i][1].fi);
            }
        }
    }

    vector<int> ans;
    for (int i=1;i<=n;i++){
        if (arah[ar[i].fi][ar[i].se]){
            arah[ar[i].fi][ar[i].se]--;
        } else{
            ans.pb(i);
        }
    }
    cout << ans.size() << el;
    for (auto x : ans) cout << x << " "; cout << el;
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
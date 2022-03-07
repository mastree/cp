#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 60;

int q;
int n;
int ar[N];
vector<vector<int>> adj;

pii dp[N]; // score, anc that are direct child-of-root
void dfs(int node, int p, int cr = -1){
    dp[node].fi = dp[p].fi + ar[node];
    dp[node].se = cr;
    for (auto& x : adj[node]){
        if (x == p) continue;
        dfs(x, node, (cr == -1) ? x : cr);
    }
}

void solve(){
    cin >> n;
    adj.clear();
    adj.resize(n + 1, vector<int>());
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    for (int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    if (n == 1){
        cout << ar[1] << el;
        return;
    }
    for (int i=1;i<=n;i++){
        dp[i] = {0, -1};
    }
    dfs(1, 1);
    int ans = 0;
    for (int i=1;i<=n;i++){
        ans = max(ans, dp[i].fi);
        for (int j=1;j<=n;j++){
            if (i == j) continue;
            if (dp[i].se != -1 && dp[j].se != -1 && dp[i].se != dp[j].se){
                ans = max(ans, dp[i].fi + dp[j].fi - ar[1]);
            }
        }
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
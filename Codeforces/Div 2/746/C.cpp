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

int q;
int n, k;
int ar[N];

vector<vector<int>> adj;

int dp[N];

void dfs(int node, int p){
    dp[node] = ar[node];
    for (auto& x : adj[node]){
        if (x == p) continue;
        dfs(x, node);
        dp[node] ^= dp[x];
    }
}
pii dfs_find(int node, int p){ // carry xor, cnt
    pii ret = mp(0, 0);
    for (auto& x : adj[node]){
        if (x == p) continue;
        auto temp = dfs_find(x, node);
        ret.fi ^= temp.fi;
        ret.se += temp.se;
    }
    int cur = (dp[node] ^ ret.fi);
    if (cur == dp[1]){
        ret.fi = dp[node];
        ret.se++;
        return ret;
    }
    return ret;
}

void init(){
    adj.clear();
    adj.resize(n + 1, vector<int>());
    dp[1] = 0;
}
void solve(){
    cin >> n >> k;
    init();
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    for (int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(1, 1);
    if (dp[1] == 0){
        cout << "YES" << el;
        return;
    }
    int temp = dfs_find(1, 1).se;
    if (temp >= 3 && k >= 3){
        cout << "YES" << el;
    } else{
        cout << "NO" << el;
    }
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
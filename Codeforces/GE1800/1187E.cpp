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

const int N = 2e5 + 10;

int n;
vector<int> adl[N];
ll dp[N], sz[N];

void dfs_sz(int node, int p){
    sz[node] = 1;
    for (auto x : adl[node]){
        if (x == p) continue;
        dfs_sz(x, node);
        sz[node] += sz[x];
    }
}

void dfs_dp(int node, int p){
    dp[node] = sz[node];
    for (auto x : adl[node]){
        if (x == p) continue;
        dfs_dp(x, node);
        dp[node] += dp[x];
    }
}

void dfs_dp2(int node, int p){
    if (node == p){
        for (auto x : adl[node]){
            if (x == p) continue;
            dfs_dp2(x, node);
        }
    } else{
        dp[node] = dp[p] - sz[node] + n - sz[node];
        for (auto x : adl[node]){
            if (x == p) continue;
            dfs_dp2(x, node);
        }
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
        adl[a].pb(b);
        adl[b].pb(a);
    }
    dfs_sz(1, 1);
    dfs_dp(1, 1);
    dfs_dp2(1, 1);
    ll ans = 0;
    for (int i=1;i<=n;i++){
        ans = max(ans, dp[i]);
    }
    cout << ans << el;

    return 0;
}
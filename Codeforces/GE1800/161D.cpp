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

const int N = 5e4 + 5, K = 505;

int ans[N];
int n, k;
vector <int> adl[N];
int dp[N][K];
int root = 1;

void dfs(int node, int p){
    dp[node][0] = 1;
    for (auto x : adl[node]){
        if (x==p) continue;
        dfs(x, node);
        for (int i=1;i<=k;i++){
            dp[node][i] += dp[x][i-1];
        }
    }
}

void sol(int node, int p){
    if (node != root){
        vector <int> v(k+2);
        for (int i=1;i<k;i++){
            v[i+1] = dp[p][i] - dp[node][i-1];
        }
        v[1] = 1;
        for (int i=0;i<=k;i++){
            dp[node][i] += v[i];
        }
    }

    for (auto x : adl[node]){
        if (x != p) sol(x, node);
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adl[a].pb(b);
        adl[b].pb(a);
    }
    dfs(root, 0);
    sol(root, 0);
    ll ans = 0;
    for (int i=1;i<=n;i++){
        ans = ans + (ll)(dp[i][k]);
    }
    ans/=2;
    cout << ans << el;

    return 0;
}
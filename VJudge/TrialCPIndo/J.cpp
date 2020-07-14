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

const int N = 1e5 + 10;

int n;
vector<int> adl[N];
int dp[N];
int ans;

void dfs(int node, int p){
    dp[node] = 1;
    for (auto x : adl[node]){
        if (x == p) continue;
        dfs(x, node);
        dp[node] += dp[x];
    }
    if (dp[node] % 2 == 0) ans++;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    if (n & 1){
        cout << -1 << el;
        return 0;
    }
    for (int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adl[a].pb(b);
        adl[b].pb(a);
    }
    dfs(1, 1);
    cout << ans - 1 << el;

    return 0;
}
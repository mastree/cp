#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
// #define MOD 1000000007
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'

using namespace std;

const ll MOD = 1e9 + 7;
const int N = 2e5 + 10;

int n, d;
set<int> adl[N];

int ar[N];
pii sar[N];
ll dp[N];

void dfs(int node, int p, int mn){
    if (ar[node] - mn > d){
        dp[node] = 0;
        return;
    }
    dp[node] = 1;
    for (auto x : adl[node]){
        if (x == p) continue;
        dfs(x, node, mn);
        dp[node] = (dp[node] * (dp[x] + 1)) % MOD;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> d >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        sar[i] = mp(ar[i], i);
    }
    sort(sar + 1, sar + n + 1);
    for (int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adl[a].insert(b);
        adl[b].insert(a);
    }
    ll ans = 0;
    for (int ur=1;ur<=n;ur++){
        int i = sar[ur].se;
        dfs(i, i, ar[i]);
        for (auto x : adl[i]){
            adl[x].erase(i);
        }
        ans = (ans + dp[i]) % MOD;
    }
    cout << ans << el;

    return 0;
}
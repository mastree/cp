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

double dp[N];

void dfs(int node, int p){
    double ret = 0.0;
    int cnt = 0;
    for (auto x : adl[node]){
        if (x == p) continue;
        dfs(x, node);
        ret += dp[x] + 1;
        cnt++;
    }
    if (cnt) dp[node] = ret / ((double) cnt);
    else dp[node] = 0;
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
    dfs(1, 1);
    cout << fixed << setprecision(11) << dp[1] << el;

    return 0;
}
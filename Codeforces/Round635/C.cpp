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

int n, k;
vector <int> adl[N];
int dp[N], par[N], kurang[N], child[N];
int take;
bool vis[N];
ll ans;

void dfs(int node, int p){
    par[node] = p;
    if (node == p) dp[node] = 0;
    else dp[node] = dp[p] + 1;
    for (auto x : adl[node]){
        if (x == p) continue;
        child[node]++;
        dfs(x, node);
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

    dfs(1, 1);
    priority_queue <pii> pq;
    for (int i=1;i<=n;i++){
        if (child[i] == 0){
            pq.push(mp(dp[i], i));
        }
    }

    while (!pq.empty()){
        auto temp = pq.top();
        pq.pop();
        if (take < k){
            take++;
            ans += (ll)temp.fi;
        } else break;
        if (temp.se == 1) break;
        int p = par[temp.se];
        kurang[p] += kurang[temp.se] + 1;
        child[p]--;
        if (child[p] == 0){
            pq.push(mp(dp[p] - kurang[p], p));
        }
    }
    cout << ans << el;

    return 0;
}
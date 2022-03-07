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
const int INF = 1e9;

int q;
int n, m;

vector<int> adj[N], radj[N];
int dist[N], dp[N];

void init(){
    for (int i=1;i<=n;i++){
        adj[i].clear();
        radj[i].clear();
    }
}
void init2(){
    queue<pii> qu;
    fill(dist, dist + n + 2, INF);
    dist[1] = 0;
    qu.push(mp(1, 0));
    while (!qu.empty()){
        int node = qu.front().fi;
        int cur = qu.front().se;
        qu.pop();
        for (auto x : adj[node]){
            if (dist[x] != INF) continue;
            dist[x] = cur + 1;
            qu.push(mp(x, cur + 1));
        }
    }
    fill(dp, dp + n + 2, INF);
    for (int i=1;i<=n;i++){
        dp[i] = dist[i];
        for (auto x : adj[i]){
            dp[i] = min(dp[i], dist[x]);
        }
    }
}

void solve(){
    cin >> n >> m;
    init();
    for (int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        radj[b].pb(a);
    }
    init2();
    vector<pii> vec;
    for (int i=1;i<=n;i++){
        vec.pb(mp(dist[i], i));
    }
    sort(vec.begin(), vec.end(), greater<pii>());
    for (auto x : vec){
        for (auto y : radj[x.se]){
            if (dist[y] < dist[x.se]) dp[y] = min(dp[y], dp[x.se]);
        }
    }
    for (int i=1;i<=n;i++){
        cout << dp[i] << " ";
    }
    cout << el;
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
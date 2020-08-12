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

int n, m;
vector<int> adj[N], radj[N];
int dp[N], rdp[N];
int in[N], rin[N];

int col[N];

int dfs(int node){
    if (col[node] == 1) return 1;
    col[node] = 1;
    for (auto x : adj[node]){
        if (col[x] == 2) continue;
        if (dfs(x)) return 1;
    }
    col[node] = 2;
    return 0;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        radj[b].pb(a);
        in[b]++;
        rin[a]++;
    }
    for (int i=1;i<=n;i++){
        if (!col[i]){
            if (dfs(i)){
                cout << -1 << el;
                return 0;
            }
        }
    }
    fill(dp, dp + n + 2, INF);
    fill(rdp, rdp + n + 2, INF);
    queue<int> q;
    for (int i=1;i<=n;i++){
        if (in[i] == 0){
            q.push(i);
        }
    }
    while (!q.empty()){
        int node = q.front();
        dp[node] = min(dp[node], node);
        q.pop();
        for (auto x : adj[node]){
            dp[x] = min(dp[x], dp[node]);
            if (--in[x] == 0){
                q.push(x);
            }
        }
    }
    for (int i=1;i<=n;i++){
        if (rin[i] == 0){
            q.push(i);
        }
    }
    while (!q.empty()){
        int node = q.front();
        rdp[node] = min(rdp[node], node);
        q.pop();
        for (auto x : radj[node]){
            rdp[x] = min(rdp[x], rdp[node]);
            if (--rin[x] == 0){
                q.push(x);
            }
        }
    }
    int ans = 0;
    bool cek[n + 2];
    for (int i=1;i<=n;i++){
        if (dp[i] == rdp[i]){
            ans++;
            cek[i] = 1;
        } else cek[i] = 0;
    }
    cout << ans << el;
    for (int i=1;i<=n;i++){
        if (cek[i]) cout << 'A';
        else cout << 'E';
    }
    cout << el;

    return 0;
}
#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 105;
const int INF = 1e9;

int q;

// tree ============
int n, k;
vector<vector<int>> adj;
//==================

int dist[N][N], fromto[N][N];
void bfs(int sc){
    fill(dist[sc] + 1, dist[sc] + n + 1, INF);
    dist[sc][sc] = 0;
    queue<int> qu;
    qu.push(sc);
    while (!qu.empty()){
        int node = qu.front();
        qu.pop();
        for (auto& x : adj[node]){
            if (dist[sc][x] == INF){
                fromto[x][sc] = node;
                dist[sc][x] = dist[sc][node] + 1;
                qu.push(x);
            }
        }
    }
}

void dfs(int node, int p, vector<bool>& forbid, vector<int>& path, int& sisa){
    path.pb(node);
    if (node != p) sisa--;
    for (auto& x : adj[node]){
        if (forbid[x] || x == p || sisa <= 0) continue;
        dfs(x, node, forbid, path, sisa);
        path.pb(node);
    }
}

void solve(){
    adj.clear();
    cin >> n >> k;
    adj.resize(n + 1);
    for (int i=2;i<=n;i++){
        int p;
        cin >> p;
        adj[p].pb(i);
        adj[i].pb(p);
    }
    for (int i=1;i<=n;i++){
        bfs(i);
    }
    pair<int, pii> mn = {INF, mp(-1, -1)};
    for (int s=1;s<=1;s++){
        for (int e=s;e<=n;e++){
            if (dist[s][e] >= k) continue;
            int outernode = k - (dist[s][e] + 1);
            mn = min(mn, {dist[s][e] + outernode * 2, {s, e}});
        }
    }
    vector<int> mainpath;
    vector<int> ans;
    {
        int a = mn.se.fi;
        int b = mn.se.se;

        while (a != b){
            mainpath.pb(a);
            a = fromto[a][b];
        }
        mainpath.pb(b);

        vector<bool> forbid(N, 0);
        for (auto& x : mainpath){
            forbid[x] = 1;
        }
        int sisa = mn.fi - (k - 1);
        for (auto& x : mainpath){
            dfs(x, x, forbid, ans, sisa);
        }
    }
    cout << mn.fi << el;
    for (auto& x : ans){
        cout << x << ' ';
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
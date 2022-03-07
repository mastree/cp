#pragma gcc optimize ("O2")
#pragma gcc optimize ("unroll-loops")

#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 110;
const int M = 1e3 + 10;
const int INF = 1e9 + 10;

int q;
int n, m;
int cost[2];

vector<pair<pii, int>> edges;
vector<pii> adj[N];

int vis[N];

vector<pii> unimst(int sc){
    vector<pii> mst(n + 1, mp(INF, -1)); // cost, edge id
    fill(vis, vis + n + 2, 0);
    mst[n - 1].fi = 0;
    mst[n].fi = 0;
    mst[sc].fi = cost[sc - (n - 1)];
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(mp(mst[sc].fi, sc));
    
    while (!pq.empty()){
        int node = pq.top().se;
        int cur = pq.top().fi;
        pq.pop();
        if (cur > mst[node].fi) continue;
        vis[node] = 1;
        for (auto& x : adj[node]){
            if (vis[x.fi]) continue;
            auto edge = edges[x.se];
            if (edge.se < mst[x.fi].fi){
                mst[x.fi] = mp(edge.se, x.se);
                pq.push(mp(mst[x.fi].fi, x.fi));
            }
        }
    }
    return mst;
}
vector<pii> binmst(){
    vector<pii> mst(n + 1, mp(INF, -1)); // cost, edge id
    fill(vis, vis + n + 2, 0);
    mst[n - 1].fi = cost[0];
    mst[n].fi = cost[1];
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(mp(mst[n - 1].fi, n - 1));
    pq.push(mp(mst[n].fi, n));

    while (!pq.empty()){
        int node = pq.top().se;
        int cur = pq.top().fi;
        pq.pop();
        if (cur > mst[node].fi) continue;
        vis[node] = 1;
        for (auto& x : adj[node]){
            if (vis[x.fi]) continue;
            auto edge = edges[x.se];
            if (edge.se < mst[x.fi].fi){
                mst[x.fi] = mp(edge.se, x.se);
                pq.push(mp(mst[x.fi].fi, x.fi));
            }
        }
    }
    return mst;
}
bool isbeda(const vector<pii>& a, const vector<pii>& b){
    vector<bool> ada(m + 1, 0);
    for (const auto& x : a){
        if (x.se != -1) ada[x.se] = 1;
    }
    for (const auto& x : b){
        if (x.se != -1 && !ada[x.se]) return 1;
    }
    return 0;
}
ll sumof(const vector<pii>& a){
    ll ret = 0;
    for (int i=1;i<=n;i++){
        ret += a[i].fi;
    }
    return ret;
}

void solve(){
    cin >> n >> m;
    n += 2;
    for (int i=0;i<m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        edges.pb(mp(mp(a, b), c));
        if (b < n - 1) adj[a].pb(mp(b, i));
        adj[b].pb(mp(a, i));
    }
    cin >> cost[0] >> cost[1];
    vector<vector<pii>> best, sbest(3, vector<pii>(n + 1, mp(INF, -1)));
    vector<vector<bool>> edgeada;
    for (int i=0;i<2;i++){
        best.pb(unimst(n - 1 + i));
        edgeada.pb(vector<bool>(m + 1, 0));
        for (int j=1;j<=n;j++){
            if (best[i][j].se != -1) edgeada[i][best[i][j].se] = 1;
        }
    }
    {
        best.pb(binmst());
        edgeada.pb(vector<bool>(m + 1, 0));
        for (int j=1;j<=n;j++){
            if (best[2][j].se != -1) edgeada[2][best[2][j].se] = 1;
        }
    }
    for (int i=0;i<m;i++){
        int temp = edges[i].se;
        edges[i].se = INF;

        for (int j=0;j<2;j++){
            if (!edgeada[j][i]) continue;
            auto vec = unimst(n - 1 + j);
            bool beda = 0;
            if (isbeda(vec, best[j])){
                if (sumof(vec) < sumof(sbest[j])) sbest[j].swap(vec);
            }
        }
        if (edgeada[2][i]){
            auto vec = binmst();
            bool beda = 0;
            if (isbeda(vec, best[2])){
                if (sumof(vec) < sumof(sbest[2])) sbest[2].swap(vec);
            }
        }

        edges[i].se = temp;
    }
    // for (auto& x : best) cout << sumof(x) << ' ';cout << el;
    // for (auto& x : sbest) cout << sumof(x) << ' ';cout << el;
    vector<vector<pii>> ans(2, vector<pii>(n + 1, mp(INF, -1)));
    for (int i=0;i<2;i++){
        for (auto& y : best){
            if (i == 1 && !isbeda(ans[0], y)) continue;
            if (sumof(y) < sumof(ans[i])) ans[i].swap(y);
        }
        for (auto& y : sbest){
            if (i == 1 && !isbeda(ans[0], y)) continue;
            if (sumof(y) < sumof(ans[i])) ans[i].swap(y);
        }
    }
    cout << sumof(ans[0]) << " " << sumof(ans[1]) << el;
    for (int i=1;i<=n;i++){
        adj[i].clear();
    }
    edges.clear();
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    for (int i=1;i<=q;i++){
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}
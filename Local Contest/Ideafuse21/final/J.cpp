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

const int INF = 1e9 + 10;
const int N = 2e3 + 10;

struct Crane {
    int x, y, r, m;
};

int q;
int n;
Crane ar[N];
vector<pii> adj[N];
pair<pii, int> quers[N];

set<int> allms;
vector<int> allm;

ll edist(pii a, pii b){
    ll delx = abs(a.fi - b.fi);
    ll dely = abs(a.se - b.se);
    return delx * delx + dely * dely;
}

vector<int> dijkstra(int mincap){
    vector<int> dp(n + 1, INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq; // jarak, node
    dp[1] = 0;
    pq.push(mp(0, 1));
    while (!pq.empty()){
        int node = pq.top().se;
        int cur = pq.top().fi;
        pq.pop();
        if (cur > dp[node]) continue;

        for (auto& x : adj[node]){
            if (ar[x.fi].m < mincap) continue;
            if (cur + x.se < dp[x.fi]){
                pq.push(mp(cur + x.se, x.fi));
                dp[x.fi] = cur + x.se;
            }
        }
    }
    return dp;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> ar[1].x >> ar[1].y >> ar[1].r;
    ar[1].m = INF;
    allms.insert(ar[1].m);
    cin >> n;
    for (int i=2;i<=n + 1;i++){
        cin >> ar[i].x >> ar[i].y >> ar[i].r >> ar[i].m;
        allms.insert(ar[i].m);
    }
    {
        for (auto& x : allms) allm.pb(x);   
    }
    n++;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if (i == j) continue;
            ll dist = edist(mp(ar[i].x, ar[i].y), mp(ar[j].x, ar[j].y));
            ll rr = ar[i].r + ar[j].r;
            if (i == 1){
                if (1LL * ar[j].r * ar[j].r >= dist){
                    adj[i].pb(mp(j, 0));
                } else if (rr * rr >= dist){
                    adj[i].pb(mp(j, 1));
                }
            } else if (rr * rr >= dist){
                adj[i].pb(mp(j, 1));
            }
        }
    }

    vector<vector<int>> dps;
    for (auto& x : allm){
        dps.pb(dijkstra(x));
    }

    int q;
    cin >> q;
    for (int i=1;i<=q;i++){
        int x, y, m;
        cin >> x >> y >> m;
        if (x == ar[1].x && y == ar[1].y){
            cout << 0 << el;
            continue;
        }
        int id = 0;
        while (allm[id] < m) id++;
        int ans = INF;
        for (int j=1;j<=n;j++){
            if (ar[j].m < m) continue;
            ll dist = edist(mp(x, y), mp(ar[j].x, ar[j].y));
            if (1LL * ar[j].r * ar[j].r >= dist){
                ans = min(ans, dps[id][j] + 1);
            }
        }
        if (ans >= INF){
            cout << -1 << el;
        } else{
            cout << ans << el;
        }
    }

    return 0;
}
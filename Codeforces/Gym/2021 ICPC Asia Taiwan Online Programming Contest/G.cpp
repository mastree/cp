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

int n;
vector<pii> adj[N];
vector<pair<int, array<int, 2>>> edges;
int pos[N][2];

ll dp[N][2][2];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=0;i<n - 1;i++){
        int a, b, c;
        cin >> a >> b >> c;
        array<int, 2> temp = {a, b};
        edges.emplace_back(mp(c, temp));
    }
    sort(edges.begin(), edges.end());
    {
        int id = 0;
        for (auto& x : edges){
            pos[id][0] = adj[x.se[0]].size();
            adj[x.se[0]].emplace_back(id, 1);
            pos[id][1] = adj[x.se[1]].size();
            adj[x.se[1]].emplace_back(id, 0);
            id++;
        }
    }
    // id edges, 0 1 in edge, take?
    // id edges, take?, 0 1 in edge
    set<pair<pii, pii>> setdah;
    auto add = [&](int id, int eid, int take, ll val) -> void {
        dp[id][eid][take] += val;
        setdah.insert(mp(mp(edges[id].fi, take), mp(id, eid)));
    };
    for (int i=1;i<=n;i++){
        int id = adj[i][0].fi;
        int eid = (adj[i][0].se ^ 1);
        add(id, eid, 0, 1);
    }
    ll ans = 0;
    while (!setdah.empty()){
        auto tp = *setdah.begin();
        setdah.erase(tp);
        int id = tp.se.fi;
        int eid = tp.se.se;
        int take = tp.fi.se;
        ll val = dp[id][eid][take];
        int node = edges[id].se[eid];

        int pnode = pos[id][eid];

        if (pnode + 1 < adj[node].size()){
            pii nedge = adj[node][pnode + 1];
            int nid = nedge.fi;
            int neid = !nedge.se;
            int ntake = edges[id].fi >= edges[nid].fi ? take : 0;
            if (ntake) dp[id][eid][take] -= val;
            add(nid, neid, ntake, val);
        }
        if (!take){
            int neid = !eid;
            int ntake = 1;
            add(id, neid, ntake, val);
        }
    }
    for (int id=0;id<n - 1;id++){
        for (int eid=0;eid<2;eid++){
            ans += dp[id][eid][1];
        }
    }
    cout << ans << el;

    return 0;
}
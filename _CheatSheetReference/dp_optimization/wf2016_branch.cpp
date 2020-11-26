#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;

const int N = 5e3 + 10;
const ll INF = 1e18;

int n, b, s, r;
vector<pil> adj[N], radj[N];
ll cost[N];

void dijkstra(){
    ll dp[n + 2];
    fill(dp, dp + n + 2, INF);
    set<pli> setdah;
    dp[b + 1] = 0;
    setdah.insert(mp(0, b + 1));
    while (!setdah.empty()){
        auto tp = *setdah.begin();
        setdah.erase(tp);
        for (auto x : adj[tp.se]){
            if (dp[x.fi] > tp.fi + x.se){
                setdah.erase(mp(dp[x.fi], x.fi));
                dp[x.fi] = tp.fi + x.se;
                setdah.insert(mp(dp[x.fi], x.fi));
            }
        }
    }
    for (int i=1;i<=b;i++){
        cost[i] += dp[i];
    }
    fill(dp, dp + n + 2, INF);
    dp[b + 1] = 0;
    setdah.insert(mp(0, b + 1));
    while (!setdah.empty()){
        auto tp = *setdah.begin();
        setdah.erase(tp);
        for (auto x : radj[tp.se]){
            if (dp[x.fi] > tp.fi + x.se){
                setdah.erase(mp(dp[x.fi], x.fi));
                dp[x.fi] = tp.fi + x.se;
                setdah.insert(mp(dp[x.fi], x.fi));
            }
        }
    }
    for (int i=1;i<=b;i++){
        cost[i] += dp[i];
    }
}

ll dp[N][N];
ll C(int a, int b){
    return cost[b] - cost[a - 1];
}
void compute(int l, int r, int optl, int optr, int id){
    if (l > r) return;
    int mid = (l + r) / 2;
    pli best = mp(dp[id - 1][mid], mid + 1);

    for (int i=optl;i<=min(optr, mid);i++){
        best = min(best, mp(dp[id - 1][i - 1] + C(i, mid) * (mid - i), i));
    }
    dp[id][mid] = best.fi;
    compute(l, mid - 1, optl, best.se, id);
    compute(mid + 1, r, best.se, optr, id);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> b >> s >> r;
    for (int i=1;i<=r;i++){
        int a, b;
        ll w;
        cin >> a >> b >> w;
        adj[a].emplace_back(b, w);
        radj[b].emplace_back(a, w);
    }
    dijkstra();
    ll ans = 0;
    sort(cost + 1, cost + b + 1);
    for (int i=1;i<=b;i++){
        cost[i] += cost[i - 1];
    }
    for (int i=0;i<=b;i++){
        fill(dp[i] + 1, dp[i] + b + 2, INF);
    }
    for (int i=1;i<=s;i++) compute(1, b, 1, b, i);
    cout << dp[s][b] << el;

    return 0;
}
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
const int BORD = 2e9 + 1;
const ll INF = 1e18;

struct Circ{
    int x, y;
    int r;
    ll c;

    Circ(int a, int b, int c, ll d) : x(a), y(b), r(c), c(d) {}
    Circ() {}
};

int n;
pii st, fin;

Circ ar[N];

vector<pii> hor, ver;

set<pii> shor, sver;

void merge_range(vector<pii>& v){
    vector<pii> res;
    sort(v.begin(), v.end());
    for (auto x : v){
        if (res.empty()){
            res.pb(x);
            continue;
        }
        if (res.back().se >= x.fi){
            res.back().se = max(res.back().se, x.se);
        } else{
            res.pb(x);
        }
    }
    v.swap(res);
}

vector<pair<int, ll>> adj[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> st.fi >> st.se >> fin.fi >> fin.se;
    for (int i=1;i<=n;i++){
        int a, b, c;
        ll d;
        cin >> a >> b >> c >> d;
        ar[i] = Circ(a, b, c, d);
        hor.emplace_back(b - c, b + c);
        ver.emplace_back(a - c, a + c);
    }
    hor.emplace_back(st.se, st.se);
    hor.emplace_back(fin.se, fin.se);
    ver.emplace_back(st.fi, st.fi);
    ver.emplace_back(fin.fi, fin.fi);
    merge_range(hor);
    merge_range(ver);
    {
        int tempid = 1;
        for (auto x : hor){
            shor.insert(mp(x.se, tempid));
            tempid++;
        }
        for (auto x : ver){
            sver.insert(mp(x.se, tempid));
            tempid++;
        }
    }
    for (int i=1;i<=n;i++){
        int id = shor.lower_bound(mp(ar[i].y, 0))->se;
        int id2 = sver.lower_bound(mp(ar[i].x, 0))->se;
        adj[id].emplace_back(id2, ar[i].c);
        adj[id2].emplace_back(id, ar[i].c);
    }
    int tara = shor.lower_bound(mp(fin.se, 0))->se;
    int tarb = sver.lower_bound(mp(fin.fi, 0))->se;

    int mul = shor.lower_bound(mp(st.se, 0))->se;
    ll ans = INF;
    ll dp[N];
    fill(dp, dp + N, INF);
    set<pair<ll, int>> setdah;
    dp[mul] = 0;
    setdah.insert(mp(0, mul));
    while (!setdah.empty()){
        auto tp = *setdah.begin();
        setdah.erase(tp);
        int node = tp.se;
        ll cur = tp.fi;

        for (auto x : adj[node]){
            if (dp[x.fi] > cur + x.se){
                setdah.erase(mp(dp[x.fi], x.fi));
                dp[x.fi] = cur + x.se;
                setdah.insert(mp(dp[x.fi], x.fi));
            }
        }
    }
    ans = min(dp[tara], dp[tarb]);
    if (ans == INF) cout << -1 << el;
    else cout << ans << el;

    return 0;
}
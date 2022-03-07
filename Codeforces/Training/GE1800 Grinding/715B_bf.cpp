#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pil = pair<int, ll>;

const int N = 1e3 + 10;
const ll UNDEF = (ll)1e15 - (ll)10;
const ll INF = 1e18;

int n, m;
ll l;
int s, t; // start, target
set<pil> adj[N];
vector<pii> edges;
set<pii> lost;
ll dps[N], dpt[N];

bool is_lost(int a, int b){
    return lost.find(mp(a, b)) != lost.end() || lost.find(mp(b, a)) != lost.end();
}

void setup(){
    set<pli> setdah;
    fill(dps, dps + N, INF);
    dps[s] = 0;
    setdah.insert(mp(0, s));
    while (!setdah.empty()){
        auto tp = *setdah.begin();
        setdah.erase(tp);
        int node = tp.se;
        ll cur = tp.fi;
        for (auto x : adj[node]){
            if (dps[x.fi] > cur + x.se){
                setdah.erase(mp(dps[x.fi], x.fi));
                dps[x.fi] = cur + x.se;
                setdah.insert(mp(dps[x.fi], x.fi));
            }
        }
    }
    fill(dpt, dpt + N, INF);
    dpt[t] = 0;
    setdah.insert(mp(0, t));
    while (!setdah.empty()){
        auto tp = *setdah.begin();
        setdah.erase(tp);
        int node = tp.se;
        ll cur = tp.fi;
        for (auto x : adj[node]){
            if (dpt[x.fi] > cur + x.se){
                setdah.erase(mp(dpt[x.fi], x.fi));
                dpt[x.fi] = cur + x.se;
                setdah.insert(mp(dpt[x.fi], x.fi));
            }
        }
    }
}

void solve(){
    setup();
    if (dps[t] < l){
        cout << "NO" << el;
        exit(0);
    }
    bool ok = 0;
    for (auto x : lost){
        int a = x.fi;
        int b = x.se;
        if (dps[a] > dps[b]) swap(a, b);
        auto jar = adj[a].lower_bound(mp(b, 0))->se;
        ll temp = dps[a] + jar + dpt[b];
        ll lebih = temp - l;
        if (lebih){
            adj[a].erase(mp(b, jar));
            adj[b].erase(mp(a, jar));
            ll baru = max(1LL, jar - lebih);
            adj[a].insert(mp(b, baru));
            adj[b].insert(mp(a, baru));
        }
        if (dps[t] <= l){
            ok = 1;
            break;
        }
    }
    if (!ok){
        cout << "NO" << el;
        exit(0);
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> l >> s >> t;
    for (int i=1;i<=m;i++){
        int a, b;
        ll w;
        cin >> a >> b >> w;
        if (w == 0){
            lost.insert(mp(a, b));
            w = UNDEF;
        }
        adj[a].insert(mp(b, w));
        adj[b].insert(mp(a, w));
        edges.push_back(mp(a, b));
    }
    solve();
    cout << "YES" << el;
    for (auto x : edges){
        cout << x.fi << " " << x.se << " " << adj[x.fi].lower_bound(mp(x.se, 0))->se << el;
    }

    return 0;
}
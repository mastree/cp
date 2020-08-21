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

const int N = 3e5 + 10;
const ll INF = 1e18;

int tc, q;
int n, m;
pii ar[N];

ll dist[N];
vector<pil> adj[N];

void init(){
    for (int i=0;i<N;i++){
        adj[i].clear();
    }
}

void solve(){
    cin >> n >> m;
    map<int, int> getid;
    getid[1] = 1;
    getid[n] = 1;
    for (int i=1;i<=m;i++){
        cin >> ar[i].fi >> ar[i].se;
        getid[ar[i].fi] = 1;
        getid[ar[i].se] = 1;
    }
    int tempid = 0;
    for (auto x : getid){
        getid[x.fi] = ++tempid;
    }
    init();
    pii bef = mp(-1, -1);
    for (auto x : getid){
        if (bef.fi == -1){
            bef = x;
            continue;
        }
        ll jarak = x.fi - bef.fi;
        adj[bef.se].pb(mp(x.se, jarak));

        bef = x;
    }
    for (int i=1;i<=m;i++){
        int a = ar[i].fi, b = ar[i].se;
        adj[getid[a]].pb(mp(getid[b], 1));
    }
    int f = getid[n];
    for (int i=1;i<=f;i++) dist[i] = INF;
    dist[1] = 0;
    for (int i=1;i<=f;i++){
        for (auto x : adj[i]){
            dist[x.fi] = min(dist[x.fi], dist[i] + x.se);
        }
    }
    cout << dist[f] << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--){
        solve();
    }

    return 0;
}
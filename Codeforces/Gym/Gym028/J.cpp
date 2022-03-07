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
const ll INF = 1e18;

int q;
int n, m;
ll k;
vector<pair<ll, pii>> edges;

int par[N];
int sz[N];

int find(int a){
    return par[a] == a ? a : par[a] = find(par[a]);
}
void make(int a, int b){
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
}

void init(){
    for (int i=1;i<=n;i++){
        par[i] = i;
        sz[i] = 1;
    }
    edges.clear();
}

void solve(){
    cin >> n >> m >> k;
    init();
    for (int i=1;i<=m;i++){
        int a, b;
        ll w;
        cin >> a >> b >> w;
        edges.pb(mp(w, mp(a, b)));
    }
    sort(edges.begin(), edges.end());
    ll atas = 0;
    int cnt = 0;
    for (auto x : edges){
        int a = x.se.fi;
        int b = x.se.se;
        ll w = x.fi;

        if (find(a) != find(b)){
            if (w > k) atas += w - k;
            make(a, b);
            cnt++;
        }
        if (cnt == n - 1) break;
    }
    if (atas){
        cout << atas << el;
    } else{
        ll ans = INF;
        for (auto x : edges){
            ans = min(ans, abs(k - x.fi));
        }
        cout << ans << el;
    }
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
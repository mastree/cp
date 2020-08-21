#pragma gcc optimize ("O3")
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

struct Burl{
    int c;
    ll k, p;
    Burl() {}
    Burl(int c, ll k, ll p) : c(c), k(k), p(p) {}
};
bool comp(const Burl& a, const Burl& b){
    return a.p < b.p;
}

const int N = 5e3 + 10;
const int INF = 2e9;
const ll LINF = (ll)1e18 + 10LL;

int n, m, w;
vector<int> adj[N];
int dist[N][N];
Burl burl[N];

void bfs_dist(int sc){
    dist[sc][sc] = 0;
    queue<int> qu;
    qu.push(sc);
    while (!qu.empty()){
        int tp = qu.front();
        qu.pop();
        for (auto x : adj[tp]){
            if (dist[sc][x] == INF){
                dist[sc][x] = dist[sc][tp] + 1;
                qu.push(x);
            }
        }
    }
}

int g;
ll r, a; // kota, butuh, max total price
ll bisa(int mx){
    ll sisa = r, ret = 0;
    for (int i=1;i<=w;i++){
        if (dist[g][burl[i].c] <= mx){
            ret += min(sisa, burl[i].k) * burl[i].p;
            sisa -= burl[i].k;
        }
        if (sisa <= 0LL) return ret;
    }
    return LINF;
}

void solve(){
    cin >> g >> r >> a;

    int low = 0, high = n - 1;
    while (low < high){
        int m = (low + high) / 2;
        if (bisa(m) <= a){
            high = m;
        } else{
            low = m + 1;
        }
    }
    if (bisa(high) <= a) cout << high << el;
    else cout << -1 << el;
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
        adj[b].pb(a);
    }
    for (int i=1;i<=n;i++){
        fill(dist[i], dist[i] + n + 1, INF);
    }
    for (int i=1;i<=n;i++){
        bfs_dist(i);
    }
    cin >> w;
    for (int i=1;i<=w;i++){
        int a;
        ll b, c;
        cin >> a >> b >> c;
        burl[i] = Burl(a, b, c);
    }
    sort(burl + 1, burl + w + 1, &comp);
    int q;
    cin >> q;
    while (q--){
        solve();
    }

    return 0;
}
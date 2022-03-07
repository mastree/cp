#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 5e5 + 10;
const ll MOD = 1e9 + 7;

int n, m;
vector<pii> all;
set<pii> masuk;

vector<int> adj[N];
ll ans = 1;

int par[N], sz[N];

ll fpow(ll a, ll b){
    ll ret = 1;
    while (b){
        if (b & 1){
            ret = ret * a % MOD;
        }
        b >>= 1;
        a = a * a % MOD;
    }
    return ret;
}

int find(int a){
    return par[a] == a ? a : par[a] = find(par[a]);
}
void make(int a, int b){
    cout << a << " " << b << el;
    int ra = min(a, b);
    int rb = max(a, b);
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
    masuk.insert(mp(ra, rb));
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i=0;i<N;i++){
        par[i] = i;
        sz[i] = 1;
    }
    cin >> n >> m;
    for (int i=1;i<=n;i++){
        int len;
        cin >> len;
        int a, b;
        if (len == 1){
            cin >> a;
            b = 0;
        } else cin >> a >> b;
        all.pb(mp(min(a, b), max(a, b)));
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for (int i=0;i<=m;i++){
        ll cnt = 0;
        for (auto x : adj[i]){
            if (find(i) != find(x)){
                cout << i << " " << x << el;
                cnt++;
            }
            make(adj[i][0], x);
        }
        cout << i << " " << cnt << el << el;
        ans = (ans + fpow(2LL, cnt)) % MOD;
    }
    cout << ans << " " << masuk.size() << el;
    for (int i=0;i<n;i++){
        if (masuk.find(all[i]) != masuk.end()){
            cout << i + 1 << " ";
            masuk.erase(all[i]);
        }
    }
    cout << el;

    return 0;
}
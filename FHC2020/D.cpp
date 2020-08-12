#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e6 + 100;
const ll INF = 1e18;

int q;
int n, m;
ll ar[N];

ll t[4 * N], lazy[4 * N];

void push(int v){
    t[v * 2] = min(t[v * 2], lazy[v]);
    t[v * 2 + 1] = min(t[v * 2 + 1], lazy[v]);
    lazy[v * 2] = min(lazy[v * 2], lazy[v]);
    lazy[v * 2 + 1] = min(lazy[v * 2 + 1], lazy[v]);
    lazy[v] = INF;
}

void update(int v, int tl, int tr, int l, int r, ll x){
    if (l > r || tr < l || r < tl) return;
    else if (l <= tl && tr <= r){
        lazy[v] = min(lazy[v], x);
        t[v] = min(t[v], x);
        return;
    }
    push(v);
    int tm = (tl + tr) / 2;
    update(v * 2, tl, tm, l, r, x);
    update(v * 2 + 1, tm + 1, tr, l, r, x);
}

ll ask(int v, int tl, int tr, int pos){
    if (pos < tl || tr < pos) return INF;
    else if (tl == tr) return t[v];
    push(v);
    int tm = (tl + tr) / 2;
    return min(ask(v * 2, tl, tm, pos), ask(v * 2 + 1, tm + 1, tr, pos));
}

void solve(){
    cin >> n >> m;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        if (ar[i] == 0) ar[i] = INF;
    }
    fill(t, t + n * 4 + 2, INF);
    fill(lazy, lazy + n * 4 + 2, INF);
    update(1, 1, n, 1, min(n, m + 1), 0);
    for (int i=1;i<n;i++){
        ll cur = ask(1, 1, n, i);
        ll ncur = cur + ar[i];
        update(1, 1, n, i, min(n, i + m), ncur);
    }
    ll ans = ask(1, 1, n, n);
    if (ans >= INF) cout << -1 << el;
    else cout << ans << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("running_on_fumes_chapter_1_input.txt", "r", stdin);
    freopen("D.out", "w", stdout);

    cin >> q;
    for (int i=1;i<=q;i++){
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}
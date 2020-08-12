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

const int N = 1e5 + 10;
const ll INF = 1e18;

int n, q, s;
pair<pii, ll> qq[N];
bool udh[N];

vector<int> tq[4 * N]; // segtree for query
void add_query(int v, int tl, int tr, int l, int r, int id){
    if (l > r || tr < l || r < tl) return;
    else if (l <= tl && tr <= r){
        tq[v].pb(id);
        return;
    }
    int tm = (tl + tr) / 2;
    add_query(v * 2, tl, tm, l, r, id);
    add_query(v * 2 + 1, tm + 1, tr, l, r, id);
}
vector<int> vquery;
void askquery(int v, int tl, int tr, int pos){
    if (tr < pos || pos < tl) return;
    for (auto x : tq[v]){
        if (udh[x]) continue;
        vquery.pb(x);
    }
    tq[v].clear();
    if (tl == tr) return;
    int tm = (tl + tr) / 2;
    askquery(v * 2, tl, tm, pos);
    askquery(v * 2 + 1, tm + 1, tr, pos);
}
void askquery(int pos){
    vquery.clear();
    askquery(1, 1, n, pos);
}

pair<ll, int> t[4 * N]; // dist, pos
ll mx[4 * N][2];
ll lazy[4 * N];
void merge(int v){
    set<ll> temp;
    for (int i=0;i<2;i++){
        temp.insert(mx[v * 2][i]);
        temp.insert(mx[v * 2 + 1][i]);
    }
    int id = 0;
    auto it = temp.end();
    it--;
    mx[v][0] = *it;
    it--;
    mx[v][1] = *it;
    if (t[v * 2].fi < t[v * 2 + 1].fi){
        t[v] = t[v * 2];
    } else{
        t[v] = t[v * 2 + 1];
    }
}

void build(int v, int tl, int tr){
    if (tl == tr){
        if (tl == s){
            t[v] = mp(0, tl);
        } else{
            t[v] = mp(INF, tl);
        }
        mx[v][0] = t[v].fi;
        mx[v][1] = -1; 
        lazy[v] = INF;
        return;
    }
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
    merge(v);
    lazy[v] = INF;
}

void push(int v){
    if (lazy[v] < INF){
        if (t[v * 2].fi != INF + 1){
            if (t[v * 2].fi == mx[v * 2][0]){
                t[v * 2].fi = min(t[v * 2].fi, lazy[v]);
            }
            mx[v * 2][0] = min(mx[v * 2][0], lazy[v]);
            lazy[v * 2] = min(lazy[v * 2], lazy[v]);
        }
        if (t[v * 2 + 1].fi != INF + 1){
            if (t[v * 2 + 1].fi == mx[v * 2 + 1][0]){
                t[v * 2 + 1].fi = min(t[v * 2 + 1].fi, lazy[v]);
            }
            mx[v * 2 + 1][0] = min(mx[v * 2 + 1][0], lazy[v]);
            lazy[v * 2 + 1] = min(lazy[v * 2 + 1], lazy[v]);
        }
        lazy[v] = INF;
    }
}

void update(int v, int tl, int tr, int l, int r, ll val){
    if (t[v].fi == INF + 1) return;
    if (l > r || tr < l || r < tl || mx[v][0] <= val) return;
    else if (l <= tl && tr <= r && mx[v][1] < val && val < mx[v][0]){
        if (t[v].fi == mx[v][0]){
            t[v].fi = val;
        }
        mx[v][0] = val;
        lazy[v] = min(lazy[v], val);
        return;
    }
    push(v);
    int tm = (tl + tr) / 2;
    update(v * 2, tl, tm, l, r, val);
    update(v * 2 + 1, tm + 1, tr, l, r, val);
    merge(v);
}

void update2(int v, int tl, int tr, int l, int r){
    if (l > r || tr < l || r < tl) return;
    else if (tl == tr){
        t[v] = mp(INF + 1, tl);
        lazy[v] = INF + 1;
        mx[v][0] = mx[v][1] = INF + 1;
        return;
    }
    push(v);
    int tm = (tl + tr) / 2;
    update2(v * 2, tl, tm, l, r);
    update2(v * 2 + 1, tm + 1, tr, l, r);
    merge(v);
}

pair<ll, int> ask(int v, int tl, int tr, int l, int r){
    if (l > r || tr < l || r < tl) return mp(INF + 1, -1);
    else if (l <= tl && tr <= r) return t[v];
    push(v);
    int tm = (tl + tr) / 2;
    pair<ll, int> temp1, temp2;
    temp1 = ask(v * 2, tl, tm, l, r);
    temp2 = ask(v * 2 + 1, tm + 1, tr, l, r);
    if (temp1.fi < temp2.fi) return temp1;
    return temp2;
}

ll ans[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q >> s;
    for (int i=1;i<=q;i++){
        int tipe;
        cin >> tipe;
        int vl, vr, ul, ur;
        ll w;
        if (tipe == 1){
            cin >> vl >> ul >> w;
            vr = vl;
            ur = ul;
        } else if (tipe == 2){
            cin >> vl >> ul >> ur >> w;
            vr = vl;
        } else{
            cin >> ul >> vl >> vr >> w;
            ur = ul;
        }
        add_query(1, 1, n, vl, vr, i);
        qq[i] = mp(mp(ul, ur), w);
    }
    fill(ans, ans + n + 2, INF);
    build(1, 1, n);
    int ccc = 0;
    while (1){
        pair<ll, int> res = ask(1, 1, n, 1, n);
        if (res.fi >= INF) break;
        ans[res.se] = res.fi;
        askquery(res.se);
        for (auto xx : vquery){
            udh[xx] = 1;
            auto x = qq[xx];
            int l = x.fi.fi, r = x.fi.se;
            ll w = x.se;
            update(1, 1, n, l, r, res.fi + w);
        }
        update2(1, 1, n, res.se, res.se);
    }
    for (int i=1;i<=n;i++){
        if (ans[i] >= INF) cout << -1 << " ";
        else cout << ans[i] << " ";
    }
    cout << el;

    return 0;
}
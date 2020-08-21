#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

struct Node{
    ll mn, mx, tot;
    Node() {}
    Node(ll a, ll b, ll c) : mn(a), mx(b), tot(c) {}
};

const int N = 1e5 + 10;

Node merge(const Node& a, const Node& b){
    Node ret;
    ret.mn = min(a.mn, b.mn);
    ret.mx = max(a.mx, b.mx);
    ret.tot = a.tot + b.tot;
    return ret;
}

int n, m;
ll ar[N];
Node t[4 * N];
ll lazy[4 * N];

void build(int v, int tl, int tr){
    lazy[v] = -1;
    if (tl == tr){
        t[v] = Node(ar[tl], ar[tl], ar[tl]);
        return;
    }
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
    t[v] = merge(t[v * 2], t[v * 2 + 1]);
}
void push(int v, ll range){
    if (lazy[v] == -1) return;
    int l = v * 2;
    int r = v * 2 + 1;
    t[l].mn = t[r].mn = t[l].mx = t[r].mx = lazy[l] = lazy[r] = lazy[v];
    t[l].tot = t[l].mn * ((range + 1) / 2LL);
    t[r].tot = t[r].mn * (range / 2LL);
    lazy[v] = -1;
}
void upd1(int v, int tl, int tr, int l, int r, ll x){ // modulo
    if (tr < l || r < tl || t[v].mx < x) return;
    else if (l <= tl && tr <= r && t[v].mn == t[v].mx){
        ll range = tr - tl + 1;
        t[v].mn %= x;
        t[v].mx = t[v].mn;
        t[v].tot = t[v].mn * range;
        lazy[v] = t[v].mn;
        return;
    }
    ll range = tr - tl + 1;
    push(v, range);
    int tm = (tl + tr) / 2;
    upd1(v * 2, tl, tm, l, r, x);
    upd1(v * 2 + 1, tm + 1, tr, l, r, x);
    t[v] = merge(t[v * 2], t[v * 2 + 1]);
}
void upd2(int v, int tl, int tr, int pos, ll x){
    if (tr < pos || pos < tl) return;
    else if (tl == tr){
        t[v] = Node(x, x, x);
        return;
    }
    ll range = tr - tl + 1;
    push(v, range);
    int tm = (tl + tr) / 2;
    upd2(v * 2, tl, tm, pos, x);
    upd2(v * 2 + 1, tm + 1, tr, pos, x);
    t[v] = merge(t[v * 2], t[v * 2 + 1]);
}
ll ask(int v, int tl, int tr, int l, int r){
    if (l > r || tr < l || r < tl) return 0;
    else if (l <= tl && tr <= r) return t[v].tot;
    ll range = tr - tl + 1;
    push(v, range);
    int tm = (tl + tr) / 2;
    return ask(v * 2, tl, tm, l, r) + ask(v * 2 + 1, tm + 1, tr, l, r);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }   
    build(1, 1, n);
    while (m--){
        int tipe;
        cin >> tipe;
        if (tipe == 1){
            int l, r;
            cin >> l >> r;
            ll ans = ask(1, 1, n, l, r);
            cout << ans << el;
        } else if (tipe == 2){
            int l, r;
            ll x;
            cin >> l >> r >> x;
            upd1(1, 1, n, l, r, x);
        } else{
            int pos;
            ll x;
            cin >> pos >> x;
            upd2(1, 1, n, pos, x);
        }
    }

    return 0;
}
#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int N = 1e5 + 10;
const ll INF = 1e15;

struct Node{
    pll a, b;
    Node(){};
    Node(ll val){
        a = mp(0LL, 0LL);
        b = mp(val, val);
    }
    void merge(Node a, Node b){
        ll temp = max(-b.a.fi, b.b.fi - a.b.se);
        this->a = mp(a.a.fi - temp, b.a.se);
        this->b = mp(a.b.fi + temp, b.b.se);
    }
    ll calc(){
        if (b.fi > 0) return (b.fi + 1) / 2;
        return b.fi / 2;
    }
};

int n, q;
ll ar[N];
Node t[4 * N];
ll lazy[4 * N];

void build(int v, int tl, int tr){
    if (tl == tr){
        t[v] = Node(ar[tl]);
        return;
    }
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
    t[v].merge(t[v * 2], t[v * 2 + 1]);
}
void push(int v){
    t[v * 2].b.fi += lazy[v];
    t[v * 2].b.se += lazy[v];
    t[v * 2 + 1].b.fi += lazy[v];
    t[v * 2 + 1].b.se += lazy[v];
    lazy[v * 2] += lazy[v];
    lazy[v * 2 + 1] += lazy[v];
    lazy[v] = 0;
}
void update(int v, int tl, int tr, int l, int r, ll val){
    if (l > r || tr < l || r < tl) return;
    else if (l <= tl && tr <= r){
        t[v].b.fi += val;
        t[v].b.se += val;
        lazy[v] += val;
        return;
    }
    int tm = (tl + tr) / 2;
    push(v);
    update(v * 2, tl, tm, l, r, val);
    update(v * 2 + 1, tm + 1, tr, l, r, val);
    t[v].merge(t[v * 2], t[v * 2 + 1]);
}
Node ask(int v, int tl, int tr, int l, int r){
    if (l <= tl && tr <= r) return t[v];
    Node ret;
    int tm = (l + r) / 2;
    push(v);
    if (r <= tm) ret = ask(v * 2, tl, tm, l, r);
    else if (tm < l) ret = ask(v * 2 + 1, tm + 1, tr, l, r);
    else ret.merge(ask(v * 2, tl, tm, l, r), ask(v * 2 + 1, tm + 1, tr, l, r));
    return ret;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    cin >> q;
    build(1, 1, n);
    cout << t[1].calc() << el;
    while (q--){
        int l, r;
        ll val;
        cin >> l >> r >> val;
        update(1, 1, n, l, r, val);
        cout << t[1].calc() << el;
    }

    return 0;
}
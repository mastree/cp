#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = (1 << 18) + 10, M = 19;

struct Vertex {
    Vertex *l, *r;
    ll sum;
    bool tuk[M];

    Vertex(ll val) : l(nullptr), r(nullptr), sum(val) {
        for (int i=0;i<M;i++) tuk[i] = 0;
    }
    Vertex(Vertex *l, Vertex *r) : l(l), r(r), sum(0) {
        if (l){
            sum += l->sum;
        }
        if (r){ 
            sum += r->sum;
        }
        for (int i=0;i<M;i++) tuk[i] = 0;
    }
};

Vertex* build(ll a[], int tl, int tr) {
    if (tl == tr)
        return new Vertex(a[tl]);
    int tm = (tl + tr) / 2;
    return new Vertex(build(a, tl, tm), build(a, tm+1, tr));
}
void push(Vertex* v, int tl, int tr){
    int range = tr - tl + 1;
    int p = -1;
    for (int i=0;i<M;i++){
        if (range == (1 << i)){
            p = i;
            break;
        }
    }
    assert(p != -1);
    if (p > 0 && v->tuk[p - 1]){
        swap(v->l, v->r);
        v->tuk[p - 1] = 0;
    }
    if (p){
        for (int i=0;i<M;i++){
            v->l->tuk[i] ^= v->tuk[i];
            v->r->tuk[i] ^= v->tuk[i];
            v->tuk[i] = 0;
        }
    }
}

ll get_sum(Vertex* v, int tl, int tr, int l, int r) {
    if (l > r || tr < l || r < tl)
        return 0;
    if (l <= tl && tr <= r){
        return v->sum;
    }
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    return get_sum(v->l, tl, tm, l, r)
         + get_sum(v->r, tm+1, tr, l, r);
}

void update(Vertex* v, int tl, int tr, int pos, ll new_val) {
    if (tl == tr){
        v->sum = new_val;
        return;
    }
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        update(v->l, tl, tm, pos, new_val);
    else
        update(v->r, tm+1, tr, pos, new_val);
    v->sum = v->l->sum + v->r->sum;
}

int n, q;
void tuker(Vertex* v, int k){
    push(v, 1, n);
    v->tuk[k] ^= 1;
}
void rev(Vertex* v, int k){
    push(v, 1, n);
    for (int i=0;i<k;i++){
        v->tuk[i] ^= 1;
    }
}

ll ar[N];
Vertex * t;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    n = (1 << n);
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    t = build(ar, 1, n);

    while (q--){
        int tipe;
        cin >> tipe;
        if (tipe == 1){
            int pos;
            ll val;
            cin >> pos >> val;
            update(t, 1, n, pos, val);
        } else if (tipe == 2){
            int k;
            cin >> k;
            rev(t, k);
        } else if (tipe == 3){
            int k;
            cin >> k;
            tuker(t, k);
        } else{
            int l, r;
            cin >> l >> r;
            ll ans = get_sum(t, 1, n, l, r);
            cout << ans << el;
        }
    }

    return 0;
}
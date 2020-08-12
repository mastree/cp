#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());

struct item {
    ll key;
    int prior;
    ll val;
    ll tot;
    item * l, * r;
    item() { }
    item(ll key, ll val) : key(key), prior(rng32()), val(val), l(NULL), r(NULL) { }
};
typedef item * pitem;

ll total(pitem t){
    return t ? t->tot : 0;
}
void upd(pitem t){
    if (!t) return;
    t->tot = t->val + total(t->l) + total(t->r);
}

void split(pitem t, pitem& l, pitem& r, ll key) {
    if (!t)
        l = r = NULL;
    else if (key < t->key)
        split(t->l, l, t->l, key),  r = t;
    else
        split(t->r, t->r, r, key),  l = t;
    upd(t);
}

void merge(pitem& t, pitem l, pitem r) {
    if (!l || !r)
        t = l ? l : r;
    else if (l->prior > r->prior)
        merge(l->r, l->r, r),  t = l;
    else
        merge(r->l, l, r->l),  t = r;
    upd(t);
}

void insert(pitem& t, pitem it) {
    if (!t)
        t = it;
    else if (it->prior > t->prior)
        split(t, it->l, it->r, it->key),  t = it;
    else
        insert(it->key < t->key ? t->l : t->r, it);
    upd(t);
}

ll ask(pitem t, ll key){
    if (!t) return 0;
    else if (t->key <= key) return t->val + total(t->l) + ask(t->r, key);
    return ask(t->l, key);
}

pitem treap = NULL;
int q;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    ll last = 0;
    while (q--){
        ll k, val;
        cin >> k >> val;
        k ^= last;
        val ^= last;
        pitem it = new item(k, val);
        if (!treap){
            treap = it;
        } else{
            insert(treap, it);
        }

        last = ask(treap, k);
        cout << k << " " << last << el;
    }

    return 0;
}
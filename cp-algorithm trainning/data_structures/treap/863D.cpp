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

typedef struct item * pitem;
struct item{
    int prior, value, cnt;
    bool rev;
    pitem l, r;
    item(int value) : value(value), prior(rng32()), cnt(1), rev(0), l(NULL), r(NULL) { }
};

int cnt(pitem it){
    if (!it) return 0;
    return it->cnt;
}
void upd_cnt(pitem it){
    if (!it) return;
    it->cnt = 1 + cnt(it->l) + cnt(it->r);
}

void push(pitem it){
    if (it && it->rev){
        it->rev = false;
        swap(it->l, it->r);
        if (it->l) it->l->rev ^= 1;
        if (it->r) it->r->rev ^= 1;
    }
}

void merge(pitem& t, pitem l, pitem r){
    push(l);
    push(r);
    if (!l || !r)
        t = l ? l : r;
    else if (l->prior > r->prior)
        merge(l->r, l->r, r), t = l;
    else 
        merge(r->l, l, r->l), t = r;
    upd_cnt(t);
}

void split(pitem t, pitem& l, pitem& r, int key, int add = 0){
    if (!t) return void(l = r = 0);
    push(t);
    int cur_key = add + cnt(t->l);
    if (key <= cur_key)
        split(t->l, l, t->l, key, add), r = t;
    else
        split(t->r, t->r, r, key, add + 1 + cnt(t->l)), l = t;
    upd_cnt(t);
}

void reverse(pitem t, int l, int r){
    pitem t1, t2, t3;
    split(t, t1, t2, l);
    split(t2, t2, t3, r - l + 1);
    t2->rev ^= 1;
    merge(t, t1, t2);
    merge(t, t, t3);
}

void output(pitem t){
    if (!t) return;
    push(t);
    output(t->l);
    printf("%d ", t->value);
    output(t->r);
}

void insert(pitem& t, int pos, pitem x){
    if (!t){
        t = x;
        return;
    }
    pitem t1, t2;
    split(t, t1, t2, pos);
    merge(t1, t1, x);
    merge(t, t1, t2);
}

void erase_at(pitem& t, int pos){
    if (!t) return;
    pitem t1, t2, t3;
    split(t, t1, t2, pos);
    split(t2, t2, t3, 1);
    merge(t, t1, t3);
}

int get_at(pitem t, int pos){
    if (!t) return -1;
    pitem t1, t2, t3;
    split(t, t1, t2, pos);
    split(t2, t2, t3, 1);
    int ret = t2->value;
    merge(t2, t2, t3);
    merge(t, t1, t2);
    return ret;
}

const int N = 2e5 + 10;

int n, q, m;
pitem treap;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q >> m;
    for (int i=1;i<=n;i++){
        int a;
        cin >> a;
        insert(treap, i - 1, new item(a));
    }
    while (q--){
        int tipe, l, r;
        cin >> tipe >> l >> r;

        if (tipe == 1){
            int val = get_at(treap, r - 1);
            erase_at(treap, r - 1);
            insert(treap, l - 1, new item(val));
        } else{
            reverse(treap, l - 1, r - 1);
        }
    }
    for (int i=1;i<=m;i++){
        int a;
        cin >> a;
        cout << get_at(treap, a - 1) << " ";
    }
    cout << el;

    return 0;
}
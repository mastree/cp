#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 3e5 + 10;
const int INF = 1e9 + 10;

int n, q;
int ar[N];

pii t[N * 4]; // min, -(id-max)
int lazy[N * 4];

void build(int v, int tl, int tr){
    if (tl == tr){
        t[v] = mp(INF, -tl);
        return;
    }
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
    t[v] = min(t[v * 2], t[v * 2 + 1]);
}
void push(int v){
    t[v * 2].fi += lazy[v];
    t[v * 2 + 1].fi += lazy[v];
    lazy[v * 2] += lazy[v];
    lazy[v * 2 + 1] += lazy[v];
    lazy[v] = 0;
}
void update_pos(int v, int tl, int tr, int pos, int val){
    if (tr < pos || pos < tl) return;
    if (pos <= tl && tr <= pos){
        t[v].fi = val;
        return;
    }
    push(v);
    int tm = (tl + tr) / 2;
    update_pos(v * 2, tl, tm, pos, val);
    update_pos(v * 2 + 1, tm + 1, tr, pos, val);
    t[v] = min(t[v * 2], t[v * 2 + 1]);
}
void update(int v, int tl, int tr, int l, int r, int val){
    if (l > r || tr < l || r < tl) return;
    if (l <= tl && tr <= r){
        t[v].fi += val;
        lazy[v] += val;
        return;
    }
    push(v);
    int tm = (tl + tr) / 2;
    update(v * 2, tl, tm, l, r, val);
    update(v * 2 + 1, tm + 1, tr, l, r, val);
    t[v] = min(t[v * 2], t[v * 2 + 1]);
}
pii ask(int v, int tl, int tr, int l, int r){
    if (l > r || tr < l || r < tl) return mp(INF, INF);
    if (l <= tl && tr <= r){
        return t[v];
    }
    push(v);
    int tm = (tl + tr) / 2;
    return min(ask(v * 2, tl, tm, l, r), ask(v * 2 + 1, tm + 1, tr, l, r));
}

int bit[N];
void upd(int x, int val){
    while (x < N){
        bit[x] += val;
        x += (x & (-x));
    }
}
int askbit(int x){
    int ret = 0;
    while (x){
        ret += bit[x];
        x -= (x & (-x));
    }
    return ret;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    build(1, 1, n);
    vector<int> order;
    for (int i=n;i>=1;i--){
        int dist = i - ar[i];
        if (dist >= 0){
            update_pos(1, 1, n, i, dist);
        }
        auto res = ask(1, 1, n, 1, n);
        while (res.fi == 0){
            int id = -res.se;
            order.pb(id);
            update(1, 1, n, id + 1, n, -1);
            update_pos(1, 1, n, id, INF);
            res = ask(1, 1, n, 1, n);
        }
    }
    vector<int> take(n + 1, order.size());
    {
        int len = order.size();
        for (int i=0;i<len;i++){
            if (order[i] < n) take[order[i] + 1] = i;
        }
        for (int i=1;i<=n;i++){
            take[i] = min(take[i], take[i - 1]);
        }
    }

    vector<pair<pii, int>> quers;
    vector<int> ans(q);
    for (int i=0;i<q;i++){
        int a, b;
        cin >> a >> b;
        quers.pb(mp(mp(a + 1, n - b), i));
    }
    sort(quers.begin(), quers.end(), greater<pair<pii, int>>());
    {
        int last = 0;
        for (auto& x : quers){
            int l = x.fi.fi;
            int r = x.fi.se;

            int clen = take[l];
            while (last < clen){
                upd(order[last++], 1);
            }
            ans[x.se] = askbit(r);
        }
    }
    for (auto& x : ans){
        cout << x << el;
    }

    return 0;
}
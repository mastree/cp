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
const int INF = 1e9;

int n;
int ar[N], ans[N];

pii t[4 * N]; // min, pos
int lazy[4 * N];

int bit[N];

void upd(int x){
    while (x <= n){
        bit[x]++;
        x = x + (x & (-x));
    }
}
int askbit(int x){
    int ret = 0;
    while (x){
        ret += bit[x];
        x = x - (x & (-x));
    }
    return ret;
}
int askbit(int a, int b){
    return askbit(b) - askbit(a - 1);
}

void push(int v){
    if (lazy[v]){
        lazy[v * 2] += lazy[v];
        lazy[v * 2 + 1] += lazy[v];
        t[v * 2].fi += lazy[v];
        t[v * 2 + 1].fi += lazy[v];
        lazy[v] = 0;
    }
}

void build(int v, int tl, int tr){
    if (tl == tr){
        t[v] = mp(tl - ar[tl], tl);
        return;
    }
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
    if (t[v * 2].fi < t[v * 2 + 1].fi) t[v] = t[v * 2];
    else t[v] = t[v * 2 + 1];
}

void update(int v, int tl, int tr, int l, int r, int add){
    if (l > r) return;
    else if (l == tl && tr == r){
        lazy[v] += add;
        t[v].fi += add;
        return;
    }
    int tm = (tl + tr) / 2;
    push(v);
    update(v * 2, tl, tm, l, min(tm, r), add);
    update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, add);
    if (t[v * 2].fi < t[v * 2 + 1].fi) t[v] = t[v * 2];
    else t[v] = t[v * 2 + 1];
}

pii ask(int v, int tl, int tr, int l, int r){
    if (l > r) return mp(INF, -1);
    else if (l == tl && tr == r){
        return t[v];
    }
    int tm = (tl + tr) / 2;
    push(v);
    pii temp1, temp2;
    temp1 = ask(v * 2, tl, tm, l, min(tm, r));
    temp2 = ask(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    if (temp1.fi < temp2.fi) return temp1;
    return temp2;
}

void init(){
    fill(t, t + 4 * n, mp(0, 0));
    fill(lazy, lazy + 4 * n, 0);
    fill(bit, bit + n + 3, 0);
}

void solve(){
    cin >> n;
    init();
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    build(1, 1, n);
    for (int i=1;i<=n;i++){
        pii temp = ask(1, 1, n, 1, n);
        ans[temp.se] = i;
        update(1, 1, n, temp.se, temp.se, INF);
        update(1, 1, n, temp.se + 1, n, -1);
    }
    for (int i=1;i<=n;i++){
        int temp = askbit(ans[i], n);
        if (temp != ar[i]){
            cout << -1 << el;
            return;
        }
        upd(ans[i]);
    }

    for (int i=1;i<=n;i++){
        cout << ans[i] << " ";
    }
    cout << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> q;
    for (int cas=1;cas<=q;cas++){
        cout << "Test : " << cas << el;
        solve();
    }

    return 0;
}
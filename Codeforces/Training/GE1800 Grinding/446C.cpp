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
using matrix = vector<vector<ll>>;

const int N = 3e5 + 10;
const ll MOD = 1e9 + 9;

matrix base = {
    {1, 1},
    {1, 0}
};

int n, m;
ll ar[N];
matrix premat[N + 2];

matrix mult(const matrix& a, const matrix& b){
    matrix ret = {{0, 0}, {0, 0}};
    for (int i=0;i<2;i++){
        for (int j=0;j<2;j++){
            for (int k=0;k<2;k++){
                ret[i][k] = (ret[i][k] + a[i][j] * b[j][k]) % MOD;
            }
        }
    }
    return ret;
}
pll next(pll a, int x){
    if (x == 0) return a;
    return mp((premat[x][0][0] * a.fi + premat[x][0][1] * a.se) % MOD, (premat[x][1][0] * a.fi + premat[x][1][1] * a.se) % MOD);
}
ll getrange(pll a, int x){
    return (next(a, x + 1).fi - (a.fi + a.se) + MOD) % MOD;
}
void addpair(pll& a, const pll& b){
    a.fi = (a.fi + b.fi + MOD) % MOD;
    a.se = (a.se + b.se + MOD) % MOD;
}

ll t[N * 4];
pll lazy[N * 4];

void build(int v, int tl, int tr){
    if (tl == tr){
        t[v] = ar[tl];
        return;
    }
    int tm = (tl + tr) / 2;
    int vl = v + v;
    int vr = vl + 1;
    build(vl, tl, tm);
    build(vr, tm + 1, tr);
    t[v] = (t[vl] + t[vr]) % MOD;
}
void push(int v, int tl, int tr){
    if (lazy[v].fi || lazy[v].se){
        int tm = (tl + tr) / 2;
        int vl = v + v;
        int vr = vl + 1;
        t[vl] = (t[vl] + getrange(lazy[v], tm - tl + 1)) % MOD;
        pll rbase = next(lazy[v], tm - tl + 1);
        t[vr] = (t[vr] + getrange(rbase, tr - tm)) % MOD;
        addpair(lazy[vl], lazy[v]);
        addpair(lazy[vr], rbase);
        lazy[v] = mp(0LL, 0LL);
    }
}
void update(int v, int tl, int tr, int l, int r){
    if (l > r || r < tl || tr < l) return;
    else if (l <= tl && tr <= r){
        pll fibbase = next(mp(1, 0), tl - l);
        t[v] = (t[v] + getrange(fibbase, tr - tl + 1)) % MOD;
        addpair(lazy[v], fibbase);
        return;
    }
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    int vl = v + v;
    int vr = vl + 1;
    update(vl, tl, tm, l, r);
    update(vr, tm + 1, tr, l, r);
    t[v] = (t[vl] + t[vr]) % MOD;
}
ll ask(int v, int tl, int tr, int l, int r){
    if (l > r || r < tl || tr < l) return 0;
    else if (l <= tl && tr <= r){
        return t[v];
    }
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    return ask(v + v, tl, tm, l, r) + ask(v + v + 1, tm + 1, tr, l, r);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    premat[0] = {
        {1, 0},
        {0, 1}
    };
    for (int i=1;i<N;i++){
        premat[i] = mult(base, premat[i - 1]);
    }
    cin >> n >> m;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    build(1, 1, n);
    while (m--){
        int tipe;
        int l, r;
        cin >> tipe >> l >> r;
        if (tipe == 1){
            update(1, 1, n, l, r);
        } else{
            cout << (ask(1, 1, n, l, r) % MOD + MOD) % MOD << el;
        }
    }

    return 0;
}
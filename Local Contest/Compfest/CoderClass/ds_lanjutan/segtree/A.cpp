#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 5e4 + 10, M = 31;

int n, q;
int ar[N];
int t[4 * N][M];
bool lazy[4 * N][M];

void merge(int v){
    for (int i=0;i<M;i++){
        t[v][i] = t[v * 2][i] + t[v * 2 + 1][i];
    }
}
void build(int v, int tl, int tr){
    if (tl == tr){
        for (int i=0;i<M;i++){
            if (ar[tl] & (1 << i)){
                t[v][i] = 1;
            } else t[v][i] = 0;
        }
        return;
    }
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
    merge(v);
}
void push(int v, int range){
    int rl = (range + 1) / 2;
    int rr = range / 2;
    for (int i=0;i<M;i++){
        if (lazy[v][i]){
            lazy[v * 2][i] ^= 1;
            lazy[v * 2 + 1][i] ^= 1;
            t[v * 2][i] = rl - t[v * 2][i];
            t[v * 2 + 1][i] = rr - t[v * 2 + 1][i];
            lazy[v][i] = 0;
        }
    }
}
void update(int v, int tl, int tr, int l, int r, int b){
    if (l > r || tr < l || r < tl) return;
    else if (l <= tl && tr <= r){
        int range = tr - tl + 1;
        t[v][b] = range - t[v][b];
        lazy[v][b] ^= 1;
        return;
    }
    push(v, tr - tl + 1);
    int tm = (tl + tr) / 2;
    update(v * 2, tl, tm, l, r, b);
    update(v * 2 + 1, tm + 1, tr, l, r, b);
    merge(v);
}
ll accum(int v){
    ll ret = 0;
    for (int i=0;i<M;i++){
        ret += 1LL * t[v][i] * (1LL << i);
    }
    return ret;
}
ll ask(int v, int tl, int tr, int l, int r){
    if (l > r || tr < l || r < tl) return 0;
    else if (l <= tl && tr <= r){
        return accum(v);
    }
    push(v, tr - tl + 1);
    int tm = (tl + tr) / 2;
    return ask(v * 2, tl, tm, l, r) + ask(v * 2 + 1, tm + 1, tr, l, r);
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
    while (q--){
        int tipe;
        cin >> tipe;
        if (tipe == 1){
            int l, r, b;
            cin >> l >> r >> b;
            update(1, 1, n, l, r, b);
        } else{
            int l, r;
            cin >> l >> r;
            cout << ask(1, 1, n, l, r) << el;
        }
    }

    return 0;
}
#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 5e5 + 10;
const int INF = 1e9;

int q;
int n;
int ar[N];

int t[2][N * 4]; // last = length
int lazy[2][N * 4];
int lazy1[2][N * 4];

void build(int id, int v, int tl, int tr){
    if (tl == tr){
        t[id][v] = 0;
        return;
    }
    int tm = (tl + tr) / 2;
    build(id, v * 2, tl, tm);
    build(id, v * 2 + 1, tm + 1, tr);
    t[id][v] = max(t[id][v * 2], t[id][v * 2 + 1]);
}
void push(int id, int v){
    if (lazy1[id][v]){
        t[id][v * 2] += lazy1[id][v];
        t[id][v * 2 + 1] += lazy1[id][v];
        lazy[id][v * 2] += lazy1[id][v];
        lazy[id][v * 2 + 1] += lazy1[id][v];
        lazy1[id][v * 2] += lazy1[id][v];
        lazy1[id][v * 2 + 1] += lazy1[id][v];
        lazy1[id][v] = 0;
    }
    if (lazy[id][v]){
        t[id][v * 2] = max(t[id][v * 2], lazy[id][v]);
        t[id][v * 2 + 1] = max(t[id][v * 2 + 1], lazy[id][v]);
        lazy[id][v * 2] = max(lazy[id][v * 2], lazy[id][v]);
        lazy[id][v * 2 + 1] = max(lazy[id][v * 2 + 1], lazy[id][v]);
        lazy[id][v] = 0;
    }
}
void update(int id, int v, int tl, int tr, int l, int r, int val){
    if (l > r || tr < l || r < tl) return;
    else if (l <= tl && tr <= r){
        lazy[id][v] = max(lazy[id][v], val);
        t[id][v] = max(t[id][v], val);
        return;
    }
    push(id, v);
    int tm = (tl + tr) / 2;
    update(id, v * 2, tl, tm, l, r, val);
    update(id, v * 2 + 1, tm + 1, tr, l, r, val);
    t[id][v] = max(t[id][v * 2], t[id][v * 2 + 1]);
}
void update1(int id, int v, int tl, int tr, int l, int r, int val){
    if (l > r || tr < l || r < tl) return;
    else if (l <= tl && tr <= r){
        lazy1[id][v] += val;
        lazy[id][v] += val;
        t[id][v] += val;
        return;
    }
    push(id, v);
    int tm = (tl + tr) / 2;
    update1(id, v * 2, tl, tm, l, r, val);
    update1(id, v * 2 + 1, tm + 1, tr, l, r, val);
    t[id][v] = max(t[id][v * 2], t[id][v * 2 + 1]);
}
int ask(int id, int v, int tl, int tr, int l, int r){
    if (l > r || tr < l || r < tl) return -INF;
    else if (l <= tl && tr <= r){
        return t[id][v];
    }
    push(id, v);
    int tm = (tl + tr) / 2;
    return max(ask(id, v * 2, tl, tm, l, r), ask(id, v * 2 + 1, tm + 1, tr, l, r));
}


void init(){
    fill(lazy[0], lazy[0] + (n + 1) * 4, 0);
    fill(lazy[1], lazy[1] + (n + 1) * 4, 0);
    fill(lazy1[0], lazy1[0] + (n + 1) * 4, 0);
    fill(lazy1[1], lazy1[1] + (n + 1) * 4, 0);
    build(0, 1, 0, n);
    build(1, 1, 0, n);
}

void solve(){
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    init();
    // {
    //     bool on = 0;
    //     cout << "t0: ";
    //     for (int i=0;i<=n;i++){
    //         cout << i << "=" << ask(!on, 1, 0, n, i, i) << " ";
    //     }
    //     cout << el;
    //     cout << "t1: ";
    //     for (int i=0;i<=n;i++){
    //         cout << i << "=" << ask(on, 1, 0, n, i, i) << " ";
    //     }
    //     cout << el;
    // }
    for (int i=1;i<=n;i++){
        bool on = (i & 1);
        int cur = ar[i];

        int temp1 = ask(!on, 1, 0, n, 0, cur); // udh skip
        // int temp2 = ask(!on, 1, 0, n, 0, cur);

        update(!on, 1, 0, n, cur, n, temp1 + 1);
        update1(on, 1, 0, n, 0, cur, 1);
        cout << "iterasi: " << i << el;
        cout << "t0: ";
        for (int i=0;i<=n;i++){
            cout << i << "=" << ask(!on, 1, 0, n, i, i) << " ";
        }
        cout << el;
        cout << "t1: ";
        for (int i=0;i<=n;i++){
            cout << i << "=" << ask(on, 1, 0, n, i, i) << " ";
        }
        cout << el;
    }
    cout << max(ask(0, 1, 0, n, 0, n), ask(1, 1, 0, n, 0, n)) << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        solve();
    }

    return 0;
}
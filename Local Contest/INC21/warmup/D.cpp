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
const int MOD = 1e9 + 7;

// per-update changes
// -i^2 + (a + b) i - ab
// a = l - 1
// b = r + 1

ll prei[N];
ll preii[N];

ll geti(int l, int r){
    return (prei[r] - prei[l - 1] + MOD) % MOD; 
}
ll getii(int l, int r){
    return (preii[r] - preii[l - 1] + MOD) % MOD; 
}

struct Item {
    ll x = 0;
    ll y = 0;
    ll z = 0;

    Item() {}
    Item(ll a, ll b, ll c){
        x = a;
        y = b;
        z = c;
    }
    Item operator+(const Item& oth){
        Item ret;
        ret.x = (x + oth.x + MOD) % MOD;
        ret.y = (y + oth.y + MOD) % MOD;
        ret.z = (z + oth.z + MOD) % MOD;
        return ret;
    }
    void merge(const Item& oth){
        (*this) = (*this) + oth;
    }
    void reset(){
        x = 0, y = 0, z = 0;
    }
    ll calc(ll ii, ll i, ll cnt){
        return ((x * ii % MOD + y * i % MOD - z * cnt % MOD) % MOD + MOD) % MOD;
    }
};

int n, q;
ll t[N * 4];
Item lazy[N * 4];
void push(int v, int l, int r){
    lazy[v * 2].merge(lazy[v]);
    lazy[v * 2 + 1].merge(lazy[v]);
    int m = (l + r) / 2;
    t[v * 2] = (t[v * 2] + lazy[v].calc(getii(l, m), geti(l, m), m - l + 1)) % MOD;
    t[v * 2 + 1] = (t[v * 2 + 1] + lazy[v].calc(getii(m + 1, r), geti(m + 1, r), r - m)) % MOD;
    lazy[v].reset();
}
void update(int v, int tl, int tr, int l, int r, Item val){
    if (l > r || r < tl || tr < l) return;
    if (l <= tl && tr <= r){
        t[v] = (t[v] + val.calc(getii(tl, tr), geti(tl, tr), tr - tl + 1)) % MOD;
        lazy[v].merge(val);
        return;
    }
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    update(v * 2, tl, tm, l, r, val);
    update(v * 2 + 1, tm + 1, tr, l, r, val);
    t[v] = (t[v * 2] + t[v * 2 + 1]) % MOD;
}
ll ask(int v, int tl, int tr, int l, int r){
    if (l > r || r < tl || tr < l) return 0;
    if (l <= tl && tr <= r) return t[v];
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    return (ask(v * 2, tl, tm, l, r) + ask(v * 2 + 1, tm + 1, tr, l, r)) % MOD;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    for (int i=1;i<=n;i++){
        prei[i] = (prei[i - 1] + i) % MOD;
        preii[i] = (preii[i - 1] + 1LL * i * i) % MOD;
    }
    while (q--){
        int tipe;
        int l, r;
        cin >> tipe;
        cin >> l >> r;
        if (tipe == 1){
            ll a = l - 1;
            ll b = r + 1;
            Item val = {-1LL, a + b, a * b % MOD};
            update(1, 1, n, l, r, val);
        } else{
            cout << ask(1, 1, n, l, r) << el;
        }
    }

    return 0;
}
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

ll fpow(ll a, ll b){
    ll ret = 1;
    while (b){
        if (b & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ret;
}
ll inv(ll x){
    return fpow(x, MOD - 2);
}
ll calc(ll x, ll k){
    return (x / k) + 1;
}

int q;
int n;
ll x;

ll t[N * 4], lazy[N * 4];
void push(int v){
    t[v * 2] = t[v * 2] * lazy[v] % MOD;
    t[v * 2 + 1] = t[v * 2 + 1] * lazy[v] % MOD;
    lazy[v * 2] = lazy[v * 2] * lazy[v] % MOD;
    lazy[v * 2 + 1] = lazy[v * 2 + 1] * lazy[v] % MOD;
    lazy[v] = 1;
}
void update(int v, int tl, int tr, int l, int r, ll val){
    if (l > r || r < tl || tr < l) return;
    if (l <= tl && tr <= r){
        t[v] = t[v] * val % MOD;
        lazy[v] = lazy[v] * val % MOD;
        return;
    }
    int tm = (tl + tr) / 2;
    push(v);
    update(v * 2, tl, tm, l, r, val);
    update(v * 2 + 1, tm + 1, tr, l, r, val);
    t[v] = (t[v * 2] + t[v * 2 + 1]) % MOD;
}
ll ask(int v, int tl, int tr, int l, int r){
    if (l > r || r < tl || tr < l) return 0;
    if (l <= tl && tr <= r) return t[v];
    int tm = (tl + tr) / 2;
    push(v);
    return (ask(v * 2, tl, tm, l, r) + ask(v * 2 + 1, tm + 1, tr, l, r)) % MOD;
}

void solve(){
    cin >> n >> x;
    fill(t, t + (n + 1) * 4 + 5, 1);
    fill(lazy, lazy + (n + 1) * 4 + 5, 1);
    if (n > x + 1){
        cout << 0 << el;
        return;
    }
    for (int i=2;i<=n;i++){
        ll temp = (ask(1, 0, n, 0, (x - 1) % i) * calc(x - 1, i) % MOD + ask(1, 0, n, (x - 1) % i + 1, i - 2) * (calc(x - 1, i) - 1) % MOD) % MOD;
        update(1, 0, n, i - 1, i - 1, temp);
        update(1, 0, n, 0, i - 2, calc((x - 1) - (i - 1), i) % MOD);
    }
    cout << ask(1, 0, n, 0, n - 1) * inv(fpow(x, n - 1)) % MOD << el;
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
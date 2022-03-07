#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
// #define MOD 1000000007
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'

using namespace std;

const int N = 5e3 + 10;
const ll MOD = 998244353;

int n;
ll ans[N];
ll fac[N];

ll fpow(ll a, ll b){
    if (b <= 0) return 1;
    ll temp = fpow(a, b / 2);
    temp = temp * temp % MOD;
    if (b & 1) temp = temp * a % MOD;
    return temp;
}

ll inv(ll a){
    return fpow(a, MOD - 2);
}

ll t[N * 4], lazy[N * 4];
void push(int v, ll range){
    t[v * 2] = (t[v * 2] + lazy[v] * ((range + 1) / 2) % MOD) % MOD;
    lazy[v * 2] = (lazy[v * 2] + lazy[v]) % MOD;
    t[v * 2 + 1] = (t[v * 2 + 1] + lazy[v] * (range / 2) % MOD) % MOD;
    lazy[v * 2 + 1] = (lazy[v * 2 + 1] + lazy[v]) % MOD;
    lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, ll add){
    if (l > r){
        return;
    } else if (tl == l && tr == r){
        t[v] += add * (ll)(r - l + 1);
        lazy[v] += add;
        t[v] %= MOD;
        lazy[v] %= MOD;
        return;
    } 
    push(v, tr - tl + 1);
    int tm = (tl + tr) / 2;
    update(v * 2, tl, tm, l, min(tm, r), add);
    update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, add);
    t[v] = (t[v * 2] + t[v * 2 + 1]) % MOD;
}

ll query(int v, int tl, int tr, int l, int r){
    if (l > r){
        return 0;
    } else if (l <= tl && tr <= r){
        return t[v];
    } 
    push(v, tr - tl + 1);
    int tm = (tl + tr) / 2;
    return (query(v * 2, tl, tm, l, min(r, tm)) + query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r)) % MOD;
}

ll comb(ll n, ll k){
    return fac[n] * inv(fac[n - k] * fac[k] % MOD) % MOD;
}

ll perm(ll n, ll k){
    return fac[n] * inv(fac[k]) % MOD;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    fac[0] = 1;
    for (ll i=1;i<N;i++){
        fac[i] = fac[i - 1] * i % MOD;
    }
    cin >> n;
    for (ll r=1;r<=n;r++){
        if (r == 1){
            update(1, 1, n, 1, 1, n);
            continue;
        }
        ll tambah = 0;
        ll temp = 1;
        for (ll i=1;i * r <= n;i++){
            ll temp = ((fac[i * r] * inv(fpow(fac[r], i)) % MOD) * inv(fpow(fac[i], r)) % MOD) * comb(n, i * r) % MOD;
            // ll p1 = n - i * r + i;
            ll kosong = n - i * r;
            cout << temp * fpow(r, kosong) % MOD << " ";
            if (i & 1) tambah = (tambah + (temp * fpow(r, kosong) % MOD) * (i + kosong * inv(r) % MOD) % MOD) % MOD; 
            else tambah = (tambah - (temp * fpow(r, kosong) % MOD) * (i + kosong * inv(r) % MOD) % MOD) % MOD;  
            // if (i & 1) tambah = (tambah + (((comb(p1, i) * fpow(r, kosong) % MOD) * (i + kosong * inv(r) % MOD) % MOD) * max(1LL, i - 1LL)) % MOD + MOD) % MOD; 
            // else tambah = (tambah - (((comb(p1, i) * fpow(r, kosong) % MOD) * (i + kosong * inv(r) % MOD) % MOD) * max(1LL, i - 1LL)) % MOD + MOD) % MOD; 
        }
        cout << ", jadi => " << tambah << el;
        update(1, 1, n, 1, r, tambah);
    }
    for (int i=1;i<=n;i++){
        cout << query(1, 1, n, i, i) << " ";
    }
    cout << el;

    return 0;
}
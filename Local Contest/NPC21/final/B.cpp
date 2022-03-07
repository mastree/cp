#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using matrix = vector<vector<ll>>;

const ll MOD = 1e9 + 7;

ll fpow(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) { ret = (ret * a) % MOD; }
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ret;
}

ll inv(ll a) {
    return fpow(a, MOD - 2);
}

matrix mul(matrix a, matrix b) {
    int sz = a.size();
    matrix res(sz, vector<ll>(sz));
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            for (int k = 0; k < sz; k++) {
                res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    return res;
}

matrix fpow(matrix a, ll pow) {
    int sz = a.size();
    matrix res(sz, vector<ll>(sz));
    for (int i = 0; i < sz; i++) {
        res[i][i] = 1;
    }
    while (pow) {
        if (pow & 1) {
            res = mul(res, a);
        }
        a = mul(a, a);
        pow >>= 1;
    }
    return res;
}

void solve() {
    ll i, j, k, l;
    cin >> i >> j >> k >> l;
    i %= MOD, j %= MOD, k %= MOD, l %= MOD;
    if (i < 0) i += MOD;
    if (j < 0) j += MOD;
    if (k < 0) k += MOD;
    if (l < 0) l += MOD;

    ll inv2 = inv(2), inv3 = inv(3), inv4 = inv(4);

    ll sym1, sym2, sym3, sym4;
    ll s1, s2, s3, s4;

    sym1 = i;
    s1 = sym1;

    sym2 = (i * i - j) % MOD;
    sym2 = (sym2 * inv2) % MOD;
    if (sym2 < 0) sym2 += MOD;
    s2 = (MOD - sym2) % MOD;

    sym3 = (k + sym2 * i - i * j) % MOD;
    sym3 = (sym3 * inv3) % MOD;
    if (sym3 < 0) sym3 += MOD;
    s3 = sym3;

    sym4 = (sym1 * k) % MOD;
    sym4 = (sym4 - sym2 * j) % MOD;
    sym4 = (sym4 + sym3 * i) % MOD;
    sym4 = (sym4 - l) % MOD;
    sym4 = (sym4 * inv4) % MOD;
    if (sym4 < 0) sym4 += MOD;
    s4 = (MOD - sym4) % MOD;

    matrix magic = {
        {s1, s2, s3, s4},
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0}
    };

    vector<ll> haha(5);
    haha[0] = 4;
    haha[1] = i;
    haha[2] = j;
    haha[3] = k;
    haha[4] = l;

    int TC;
    cin >> TC;
    while (TC--) {
        ll n;
        cin >> n;
        ll ans;
        if (n <= 4LL) {
            ans = haha[n];
        } else {
            matrix lol = fpow(magic, n - 4);
            ans = (lol[0][0] * l + lol[0][1] * k + lol[0][2] * j + lol[0][3] * i) % MOD;
            if (ans < 0) ans += MOD;
        }
        cout << "a^" << n << " + b^" << n << " + c^" << n << " + d^" << n << " = " << ans << '\n'; 
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    for(int i = 1; i <= TC; i++) {
        solve();
    }

    return 0;
}
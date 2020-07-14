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

const int K = 200;
const ll MOD = 998244353;

typedef vector<vector<ll>> matrix;

ll kk;
ll b[K];
ll n, m;

matrix mfac;

// ll fpow(ll a, ll b){
//     if (b == 0) return 1;
//     ll temp = fpow(a, b / 2);
//     temp = temp * temp % MOD;
//     if (b & 1) temp = temp * a % MOD;
//     return temp;
// }

matrix multi(matrix a, matrix b){
    matrix ret(kk, vector<ll>(kk, 0));
    for (int i=0;i<kk;i++){
        for (int k=0;k<kk;k++){
            for (int j=0;j<kk;j++){
                ret[i][j] += a[i][k] * b[k][j];
                ret[i][j] %= MOD - 1; // untuk pangkat
            }
        }
    }
    return ret;
}

matrix matexpo(matrix a, ll b){
    matrix ret(kk, vector<ll>(kk, 0));
    if (b == 0){
        for (int i=0;i<kk;i++){
            ret[i][i] = 1;
        }
        return ret;
    }
    matrix temp = matexpo(a, b / 2);
    temp = multi(temp, temp);
    if (b & 1) temp = multi(temp, a);
    return temp;
}

ll gcd(ll a, ll b) {
    return a ? gcd(b % a, a) : b;
}

ll powmod(ll a, ll b, ll p) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) {
            res = res * a % p;
        }
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

// Finds the primitive root modulo p
ll generator(ll p) {
    vector<ll> fact;
    ll phi = p-1, n = phi;
    for (ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            fact.push_back(i);
            while (n % i == 0)
                n /= i;
        }
    }
    if (n > 1)
        fact.push_back(n);

    for (ll res = 2; res <= p; ++res) {
        bool ok = true;
        for (ll factor : fact) {
            if (powmod(res, phi / factor, p) == 1) {
                ok = false;
                break;
            }
        }
        if (ok) return res;
    }
    return -1;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> kk;
    for (int i=1;i<=kk;i++){
        cin >> b[i];
    }
    cin >> n >> m;
    mfac.resize(kk, vector<ll>(kk, 0));
    for (int i=0;i<kk;i++){
        mfac[0][i] = b[i + 1]; 
        if (i > 0){
            mfac[i][i - 1] = 1;
        }
    }
    matrix result = matexpo(mfac, n - kk);
    ll pw = result[0][0];

    ll n, k, a;
    n = MOD;
    // cin >> k >> a;
    k = pw;
    a = m;
    // cout << k << " " << a << endl;
    if (a == 0) {
        cout << 0 << el;
        // puts("1\n0");
        return 0;
    }

    ll g = generator(n);

    // Baby-step giant-step discrete logarithm algorithm
    ll sq = (ll) sqrt (n + .0) + 1;
    vector<pair<ll, ll>> dec(sq);
    for (ll i = 1; i <= sq; ++i)
        dec[i-1] = {powmod(g, i * sq * k % (n - 1), n), i};
    sort(dec.begin(), dec.end());
    ll any_ans = -1;
    for (ll i = 0; i < sq; ++i) {
        ll my = powmod(g, i * k % (n - 1), n) * a % n;
        auto it = lower_bound(dec.begin(), dec.end(), make_pair(my, 0LL));
        if (it != dec.end() && it->first == my) {
            any_ans = it->second * sq - i;
            break;
        }
    }
    if (any_ans == -1) {
        cout << -1 << el;
        // puts("0");
        return 0;
    }

    // Prll all possible answers
    ll delta = (n-1) / gcd(k, n-1);
    vector<ll> ans;
    for (ll cur = any_ans % delta; cur < n-1; cur += delta){
        cout << powmod(g, cur, n) % MOD << el;
        return 0;
        ans.push_back(powmod(g, cur, n));
    }
    // sort(ans.begin(), ans.end());
    // cout << ans[0] << el;

    return 0;
}
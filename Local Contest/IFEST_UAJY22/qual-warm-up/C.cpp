#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int C = 256 + 10;
const int N = 3e5 + 10;
const int MOD = 1e9 + 7;

int n;
string s;
ll fac[N];

ll fpow(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ret;
}
ll inv(ll a) {
    return fpow(a, MOD - 2);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    fac[0] = 1;
    for (int i = 1; i < N; i++) {
        fac[i] = fac[i - 1] * i % MOD;
    }

    cin >> s;
    n = s.size();
    assert(n < N);
    unordered_map<char, ll> cnt;
    for (auto& x : s) {
        cnt[x]++;
    }
    ll ans = fac[n];
    // for (auto& x : cnt) {
    //     ans = ans * inv(fac[x.se]) % MOD;
    // }
    cout << (ans - 1 + MOD) % MOD << '\n';

    return 0;
}
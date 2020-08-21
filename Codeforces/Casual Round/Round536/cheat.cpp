#include <bits/stdc++.h>

#define ll long long

using namespace std;

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

// This program finds all numbers x such that x^k = a (mod n)
int main() {
    ll n, k, a;
    cin >> n >> k >> a;
    if (a == 0) { // only one possible ans
        puts("1\n0");
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
    if (any_ans == -1) { // no possible ans
        puts("0");
        return 0;
    }

    // Prll all possible answers
    ll delta = (n-1) / gcd(k, n-1);
    vector<ll> ans;
    for (ll cur = any_ans % delta; cur < n-1; cur += delta)
        ans.push_back(powmod(g, cur, n));
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (ll answer : ans)
        cout << answer << endl;
}
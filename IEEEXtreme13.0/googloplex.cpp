#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
ll x, y;
ll p2[15], p5[15], pp2[15], pp5[15];

ll phi(ll x) {
    ll ret = x;
    for (ll i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            ret -= ret / i;
            while (x % i == 0) x /= i;
        }
    }
    if (x > 1) ret -= ret / x;
    return ret;
}

ll egcd(ll a, ll b, ll &x, ll &y) {
    if (a == 0) {
        x = 0, y = 1;
        return b;
    }
    ll x1, y1;
    ll d = egcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

ll inv(ll a, ll b) {
    ll x, y;
    egcd(a, b, x, y);
    return (x % b + b) % b;
}

ll fast(ll x, ll y, ll p) {
    ll ret = 1;
    while (y > 0) {
        if (y & 1) ret = (ret * x) % p;
        y >>= 1;
        x = (x * x) % p;
    }
    return (ret % p + p) % p;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    p2[0] = p5[0] = 1;
    for (int i = 1; i <= 9; i++) {
        p2[i] = 2 * p2[i - 1];
        p5[i] = 5 * p5[i - 1];
        pp2[i] = phi(p2[i]);
        pp5[i] = phi(p5[i]);
        //cerr << i << " => " << p2[i] << " ==> " << pp2[i] << " => " << p5[i] << " ==> " << pp5[i] << '\n';
    }

    cin >> n;
    while (n--) {
        cin >> x >> y;
        if (x % 10 == 0) {
            cout << 0 << '\n';
        } else if (x % 2 == 0) {
            ll get = 1e18;
            for (int t = 0; t <= 86399; t++) {
                ll rm2 = 0;
                ll rm5 = fast(x, t, p5[y]);
                ll prod = p2[y] * p5[y];
                ll crt = rm2 * inv(p5[y], p2[y]) * p5[y];
                crt %= prod;
                crt += (rm5 * inv(p2[y], p5[y]) * p2[y]);
                crt %= prod;
                get = min(get, crt);
            }
            cout << get << '\n';
        } else if (x % 5 == 0) {
            ll get = 1e18;
            for (int t = 0; t <= 86399; t++) {
                ll rm2 = fast(x, t, p2[y]);
                ll rm5 = 0;
                ll prod = p2[y] * p5[y];
                ll crt = rm2 * inv(p5[y], p2[y]) * p5[y];
                crt %= prod;
                crt += (rm5 * inv(p2[y], p5[y]) * p2[y]);
                crt %= prod;
                get = min(get, crt);
            }
            cout << get << '\n';
        } else {
            ll get = 1e18;
            for (int t = 0; t <= 86399; t++) {
                ll rm2 = fast(x, t, p2[y]);
                ll rm5 = fast(x, t, p5[y]);
                ll prod = p2[y] * p5[y];
                ll crt = rm2 * inv(p5[y], p2[y]) * p5[y];
                crt %= prod;
                crt += (rm5 * inv(p2[y], p5[y]) * p2[y]);
                crt %= prod;
                get = min(get, crt);
            }
            cout << get << '\n';
        }
    }

    return 0;
}

#pragma gcc optimize ("O2")
#pragma gcc optimize ("unroll-loops")

#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const ll INF = 1e18;

int q;

void solve() {
    int n;
    ll ub;
    cin >> n >> ub;
    vector<ll> vec(n);
    vector<ll> pre(n + 1, 0);
    for (auto& x : vec) {
        cin >> x;
    }
    sort(vec.begin(), vec.end());
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + vec[i - 1];
    }
    auto cek = [&](ll mx) -> ll {
        ll kur = max(0LL, mx - (n - 1));
        if (mx > 0) {
            if (vec.size() > 1 && vec[0] >= vec[1] && vec[0] > 0) {
                kur = max(kur, 1LL);
            }
        }
        ll change = mx - kur;
        ll mn = vec[0] - kur;
        ll cur = pre[n] - pre[1] + mn - (pre[n] - pre[n - change]) + (mn * change);
        return cur;
    };
    ll l = 0, r = INF;
    ll ans = INF;
    while (l <= r) {
        ll m = (l + r) / 2;
        if (cek(m) <= ub) {
            r = m - 1;
            ans = m;
        } else {
            l = m + 1;
        }
    }
    cout << ans << '\n';
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    for (int i = 1; i <= q; i++) {
        solve();
    }

    return 0;
}
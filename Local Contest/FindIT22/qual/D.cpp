#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e3 + 10;
const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    ll ans = 1;
    for (int i = 1; i <= n; i++) {
        ll cur = 0;
        for (int j = 1; j < 10; j++) {
            if (i % j) continue;
            cur++;
        }
        ans = ans * (max(cur, 1LL)) % MOD;
    }
    cout << ans << '\n';
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        solve();
    }

    return 0;
}
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
const int MOD = 998244353;

ll perm[N];

void solve() {
    int n;
    cin >> n;
    if (n & 1) {
        cout << 0 << '\n';
        return;
    }
    cout << perm[n / 2] * perm[n / 2] % MOD << '\n';
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    perm[0] = 1;
    for (ll i = 1; i < N; i++) {
        perm[i] = perm[i - 1] * i % MOD;
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        solve();
    }

    return 0;
}
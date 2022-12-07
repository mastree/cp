#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const string C = ".-";

void solve() {
    int n;
    string s;
    cin >> n >> s;

    char pre, suf;
    for (const auto& c : C) {
        if (s[0] != c) {
            pre = c;
        }
        if (s.back() != c) {
            suf = c;
        }
    }
    for (int mask = 0; mask < n - 1; mask++) {
        string mid;
        for (int i = 0; i < 8; i++) {
            mid.push_back(C[(mask & (1 << i)) > 0]);
        }
        cout << pre << mid << suf << '\n';
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        cout << "Case #" << i << ":\n";
        solve();
    }

    return 0;
}
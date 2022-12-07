#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int q;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == '0' && s[i + 1] == '0') {
            ans += 2;
        }
    }
    for (int i = 1; i < n - 1; i++) {
        if (s[i] == '1' && s[i - 1] == '0' && s[i + 1] == '0') {
            ans++;
        }
    }
    cout << ans << '\n';
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    for (int i = 0; i < q; i++) {
        solve();
    }

    return 0;
}
#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int S = 110;

void solve() {
    int n, k;
    cin >> n >> k;
    
    vector<int> count(S, 0);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        count[a]++;
    }
    int c[3] = {0, 0, 0};
    for (auto& x : count) {
        if (x > 2) {
            cout << "NO\n";
            return;
        }
        if (x) c[x]++;
    }
    if ((c[1] + 1) / 2 + c[2] > k) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}
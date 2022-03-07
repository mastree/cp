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
const ll INF = 1e18;

int q;
int n, k;
ll ar[N];

void solve() {
    cin >> n >> k;

    for (int i=1;i<=n;i++) {
        cin >> ar[i];
    }
    sort(ar + 1, ar + n + 1);
    for (int i=1;i<=n;i++) {
        ar[i] += ar[i - 1];
    }
    ll ret = INF;
    for (int i=n;i>=1;i--) {
        ret = min(ret, ar[i] / k);
        k--;
        if (k == 0) break;
    }
    cout << ret << '\n';
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    for (int i=1;i<=q;i++) {
        cout << "Case " << i << ": ";
        solve();
    }

    return 0;
}
#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e3 + 10;
const ll INF = 1e18;

int n, q;
int ar[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
    }
    while (q--){
        int l, r;
        ll mx;
        cin >> l >> r >> mx;
        ll cur = 0;
        ll mn = 0;
        ll ans = -INF;
        for (int i = l; i <= r; i++){
            cur += ar[i];
            ans = max(ans, cur - mn);
            mn = min(mn, cur);
        }
        if (ans == -INF) cout << "NONE" << el;
        else cout << ans << el;
    }

    return 0;
}
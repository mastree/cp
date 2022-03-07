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

void solve(){
    ll a, b;
    cin >> a >> b;
    if (b == 1LL){
        cout << "NO" << el;
        return;
    }
    cout << "YES" << el;
    ll ans[3];
    ans[0] = a;
    ans[1] = a * (2 * b - 1);
    ans[2] = ans[0] + ans[1];
    cout << ans[0] << " " << ans[1] << " " << ans[2] << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        solve();
    }

    return 0;
}
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
ll n, x, t;

ll hitung(ll a){
    a--;
    return (a + 1LL) * a / 2;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n >> x >> t;
        ll temp = t / x;
        ll ans = temp * max(0LL, n - temp);
        if (n >= temp) n = temp;
        ans += hitung(n);
        cout << ans << el;
    }

    return 0;
}
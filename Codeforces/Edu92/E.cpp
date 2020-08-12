#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAX = 4e4;

int q;

ll m, d, w; // months per year, days per month, days per week
ll n;

void solve(){
    cin >> m >> d >> w;

    n = min(m, d);

    if (d == 1){
        cout << n * (n - 1) / 2LL << el;
        return;
    }
    ll ans = 0;
    w /= __gcd(w, d - 1);
    ll temp = n / w;
    ll c2 = n % w;
    ll c1 = w - c2;
    ans += c1 * temp * (temp - 1) / 2LL;
    ans += c2 * (temp + 1) * (temp) / 2LL;
    cout << ans << el;
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
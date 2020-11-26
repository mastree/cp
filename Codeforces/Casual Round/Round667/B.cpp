#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const ll INF = (ll)1e18 + 100;

int q;

void solve(){
    ll a, b, x, y, rn;
    cin >> a >> b >> x >> y >> rn;

    ll ans = INF;
    {
        ll n = rn;
        ll cura = a;
        ll curb = b;
        ll kur = min(n, cura - x);
        cura -= kur;
        n -= kur;
        kur = min(n, curb - y);
        curb -= kur;
        n -= kur;
        ans = min(ans, cura * curb);
    }
    {
        ll n = rn;
        ll cura = a;
        ll curb = b;
        ll kur;
        kur = min(n, curb - y);
        curb -= kur;
        n -= kur;
        kur = min(n, cura - x);
        cura -= kur;
        n -= kur;
        ans = min(ans, cura * curb);
    }
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
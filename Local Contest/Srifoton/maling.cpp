#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int M = 2e5 + 10;

ll n, m;
pll ar[M];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=0;i<m;i++){
        cin >> ar[i].se >> ar[i].fi;
    }
    sort(ar, ar + m, greater<pll>());
    ll ans = 0;
    ll sisa = n;
    for (int i=0;i<m;i++){
        ll kur = min(sisa, ar[i].se);
        ans += ar[i].fi * kur;
        sisa -= kur;
    }
    cout << ans << el;

    return 0;
}
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

const int N = 2e5 + 10;

int q;
ll capa, capb;
pll ar[2];

void solve(){
    cin >> capa >> capb;
    for (int i=0;i<2;i++){
        cin >> ar[i].se;
    }
    for (int i=0;i<2;i++){
        cin >> ar[i].fi;
    }
    sort(ar, ar + 2);
    ll tot = capa / ar[0].fi + capb / ar[0].fi;
    if (tot <= ar[0].se){
        cout << tot << el;
        return;
    }
    tot = ar[0].se;
    ll mxa = capa / ar[0].fi;
    ll mxb = capb / ar[0].fi;
    mxa = min(mxa, ar[0].se);
    mxb = min(mxb, ar[0].se);

    ll ans = tot;
    for (ll i=0;i<=mxa;i++){
        ll sisaa = capa - i * ar[0].fi;
        ll sisab = capb - (tot - i) * ar[0].fi;
        if (sisab < 0) continue;
        pll temp = ar[1];
        ll tam = min(sisaa / temp.fi, temp.se);
        temp.se -= tam;
        tam += min(sisab / temp.fi, temp.se);
        ans = max(ans, tot + tam);
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
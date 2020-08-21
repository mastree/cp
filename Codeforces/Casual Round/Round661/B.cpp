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

const int N = 100;
const ll INF = 1e18;

int q;
int n;
pll ar[N];

void solve(){
    cin >> n;
    ll mna = INF, mnb = INF;
    for (int i=1;i<=n;i++){
        cin >> ar[i].fi;
        mna = min(mna, ar[i].fi);
    }
    for (int i=1;i<=n;i++){
        cin >> ar[i].se;
        mnb = min(mnb, ar[i].se);
    }
    ll ans = 0;
    for (int i=1;i<=n;i++){
        ans += max(ar[i].fi - mna, ar[i].se - mnb);
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
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
const ll INF = 1e18;

int q;
ll n, k;
pll ar[2];

void solve(){
    cin >> n >> k;
    for (int i=0;i<2;i++){
        cin >> ar[i].fi >> ar[i].se;
    }
    sort(ar, ar + 2);
    ll dist = max(ar[1].fi - ar[0].se, 0LL);
    ll base = max(min(ar[0].se, ar[1].se) - max(ar[0].fi, ar[1].fi), 0LL);
    ll tot = max(ar[0].se, ar[1].se) - min(ar[0].fi, ar[1].fi);

    if (k <= base * n){
        cout << 0 << el;
        return;
    } 

    ll ans = INF;

    if (tot == 0){
        ans = k * 2LL;
    } else{
        k -= base * n;
        tot -= base;

        ll per = tot + dist; // cost satuan = per / tot
        ll cur = 0, curtot = 0;
        if (tot >= k - curtot) ans = min(ans, cur + dist + (k - curtot));
        for (int i=1;i<=n;i++){
            curtot += tot;
            cur += per;
            if (k >= curtot){
                ans = min(ans, cur + (k - curtot) * 2LL);
                if (i < n){
                    if (tot >= k - curtot) ans = min(ans, cur + dist + (k - curtot));
                }
            } else break;
        }
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
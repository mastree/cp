#pragma gcc optimize ("O2")
#pragma gcc optimize ("unroll-loops")

#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const ll INF = 1e18;

int q;
ll n;

void solve(){
    cin >> n;
    if (n & 1) n++;
    n /= 2;
    if (n < 100){
        ll ans = INF;
        for (ll i=0;i<=n;i++){
            for (ll j=0;j<=n;j++){
                ll tot = i * 3 + j * 4;
                ll sisa = n - tot;
                if (sisa > 0){
                    tot += ((sisa + 4) / 5) * 5;
                }
                ans = min(ans, tot);
            }
        }
        cout << ans * 5 << el;
    } else{
        cout << n * 5 << el;
    }
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
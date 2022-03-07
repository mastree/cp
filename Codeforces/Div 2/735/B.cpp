#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e5 + 10;
const ll INF = 1e18;

int q;
ll n;
ll k;
ll ar[N];

void solve(){
    cin >> n >> k;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    ll ans = -INF;
    for (ll i=max(1LL, n - 210);i<=n;i++){
        for (ll j=i + 1;j<=n;j++){
            ans = max(ans, i * j - k * (ar[i] | ar[j]));
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
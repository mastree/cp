#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e5 + 10;
const ll INF = 1e18;

int n;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    ll tot = 0;
    vector<ll> vec(n + 2);
    vec[0] = -INF;
    for (int i=1;i<=n;i++){
        cin >> vec[i];
        tot += vec[i];
    } 
    vec[n + 1] = INF;
    sort(vec.begin(), vec.end());
    int q;
    cin >> q;
    while (q--){
        ll x, y;
        cin >> x >> y;

        auto pos = lower_bound(vec.begin(), vec.end(), x);
        ll ans = max(0LL, y - (tot - *pos));
        pos--;
        ans = min(ans, max(0LL, y - (tot - *pos)) + max(0LL, x - *pos));
        cout << ans << el;
    }

    return 0;
}
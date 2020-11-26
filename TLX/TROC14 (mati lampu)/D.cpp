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

int n, k;
ll ar[N];
ll pre[N], pref[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        pref[i] = pref[i - 1] + ar[i];
    }   
    for (int i=1;i<n;i++){
        pre[i] = ar[i + 1] - ar[i];
    }
    ll ans = pref[n] - ar[1] * n;
    ll cur = 0;
    for (ll i=1;i<(ll)n;i++){
        cur += pre[i] * min(i, (ll)k);
        ans = min(ans, cur + (pref[n] - pref[i]) - ar[i + 1] * (n - i));
    }
    cout << ans << el;

    return 0;
}
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

int n;
ll d;
ll ar[N];

ll pref[N], suf[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> d;
    ar[0] = -INF;
    ar[n + 1] = INF;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    sort(ar + 1, ar + n + 1);

    ll cur = 0;
    for (int i=2;i<n;i++){
        // pref[i] = max(0LL, d - (ar[i + 1] - ar[i])) * i + pref[i - 1];
        ll jar = (ar[i] - ar[i - 1]) - d;
        if (jar >= 0){
            pref[i] = pref[i - 1];
            cur += jar * (i - 1);
        } else{
            jar = -jar;
            ll but = jar * (i - 1);
            ll ncur = max(0LL, cur - but);
            pref[i] = pref[i - 1] + 
        }
    }
    for (int i=n;i>1;i--){
        suf[i] = max(0LL, d - (ar[i] - ar[i - 1])) * (n - i + 1) + suf[i + 1];
    }
    ll ans = INF;
    for (int i=1;i<n;i++){
        // ll surple = max(0LL, ar[i] - ar[i - 1] - d);
        // ll surpri = max(0LL, ar[i + 2] - ar[i + 1] - d);
        // ans = min(ans, pref[i - 1] + suf[i + 2] + max(0LL, d - (ar[i + 1] - ar[i]) - (surple + surpri)));
        // cout << i << " " << pref[i - 1] + suf[i + 2] + max(0LL, d - (ar[i + 1] - ar[i]) - (surple + surpri)) << el;
    }
    cout << ans << el;

    return 0;
}
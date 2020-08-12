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
ll n, m;
pair<ll, ll> ar[N];
ll pre[N];

void solve(){
    cin >> n >> m;
    ar[m + 1] = mp(-1, -1);
    fill(pre, pre + m + 2, 0);
    for (int i=1;i<=m;i++){
        cin >> ar[i].fi >> ar[i].se;
    }
    sort(ar + 1, ar + m + 1, greater<pair<ll, ll>>());
    for (int i=1;i<=m;i++){
        pre[i] = pre[i - 1] + ar[i].fi;
    }
    if (n == 1){
        cout << pre[1] << el;
        return;
    }
    ll ans = -INF;
    for (int i=1;i<=m;i++){
        ll sisa = n;
        ll cur = 0;
        
        cur += ar[i].fi;
        sisa--;
        ll low = 0, high = m;
        while (low < high){
            ll mid = (low + high + 1) / 2;
            if (ar[mid].fi >= ar[i].se){
                low = mid;
            } else{
                high = mid - 1;
            }
        }
        if (low > sisa){
            if (i <= sisa){
                cur += pre[sisa] - ar[i].fi;
                sisa = 1;
                cur += ar[i].se;
            } else{
                cur += pre[sisa];
                sisa = 0;
            }
        } else{
            if (i <= low){
                cur += pre[low] - ar[i].fi;
                sisa -= low - 1LL;
                cur += ar[i].se * sisa;
            } else{
                cur += pre[low];
                sisa -= low;
                cur += ar[i].se * sisa;
            }
        }
        ans = max(ans, cur);
    }
    cout << ans << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    ar[0] = mp(INF, INF);
    while (q--){
        solve();
    }

    return 0;
}
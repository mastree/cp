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
int ar[N];
map<int, int> accum;
vector<pii> setdah;

ll le[N], ri[N]; // front payment

ll ans = INF;
void solve(){
    int len = setdah.size();

    fill(le, le + N, INF);
    fill(ri, ri + N, INF);

    ll tot = 0;
    pair<ll, ll> last = mp(0, 0); // dig, totcnt
    for (int i=0;i<len;i++){
        pii x = setdah[i];
        ll dig = x.fi;
        ll cnt = x.se;
        if (cnt + last.se < k){
            le[i + 1] = tot + (dig - last.fi - 1LL) * last.se;
            tot += (dig - last.fi) * last.se;
            last = mp(dig, cnt + last.se);
        } else{
            ll kur = k - cnt;
            tot += (dig - last.fi) * kur;
            last = mp(dig, cnt + kur);
            break;
        }
    }
    if (last.se >= k){
        ans = min(ans, tot);
    }
    tot = 0;
    last = mp(0, 0); // dig, totcnt
    for (int i=len - 1;i>=0;i--){
        pii x = setdah[i];
        ll dig = x.fi;
        ll cnt = x.se;
        if (cnt + last.se < k){
            ri[i + 1] = tot + (last.fi - dig - 1LL) * last.se;
            tot += (last.fi - dig) * last.se;
            last = mp(dig, cnt + last.se);
        } else{
            ll kur = k - cnt;
            tot += (last.fi - dig) * kur;
            last = mp(dig, cnt + kur);
            break;
        }
    }
    if (last.se >= k){
        ans = min(ans, tot);
    }

    for (int i=1;i<=len;i++){
        ans = min(ans, le[i] + ri[i] + (ll)(k - setdah[i - 1].se));
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        accum[ar[i]]++;
    }
    for (auto x : accum){
        if (x.se >= k){
            cout << 0 << el;
            return 0;
        }
        setdah.pb(x);
    }
    solve();
    cout << ans << el;

    return 0;
}
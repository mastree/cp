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

const int N = 1e5 + 10;
const ll INF = 1e18;

int n;
ll m;
vector<pll> vec;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    vec.resize(n);
    for (int i=0;i<n;i++){
        cin >> vec[i].fi;
        vec[i].fi %= m;
    }
    ll tot = 0, totb = 0;
    for (int i=0;i<n;i++){
        cin >> vec[i].se;
        tot += vec[i].fi * vec[i].se;
        totb += vec[i].se;
    }
    ll ans = tot;
    sort(vec.begin(), vec.end());
    {
        vector<pll> cvec;
        ll bef = -1;
        for (auto& x : vec){
            if (bef != x.fi){
                cvec.pb(x);
                bef = x.fi;
            } else{
                cvec.back().se += x.se;
            }
        }
        n = cvec.size();
        vec.swap(cvec);
        // for (auto& x : vec){
        //     cout << x.fi << " " << x.se << el;
        // } cout << el;
    }
    ll cur = 0;
    // cout << ans << el;
    for (int i=n - 1;i>=0;i--){
        ll but = m - vec[i].fi - 1;
        tot = tot + totb * (but - cur);
        ans = max(ans, tot);
        tot -= vec[i].se * m;
        cur = but;
    }
    cout << ans << el;

    return 0;
}
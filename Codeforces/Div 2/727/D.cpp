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

int n;
vector<pll> vec;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    vec.resize(n);
    for (int i=0;i<n;i++){
        cin >> vec[i].se >> vec[i].fi;
    }
    sort(vec.begin(), vec.end());
    int l = 0, r = n - 1;
    ll ans = 0;
    ll tot = 0;
    while (l <= r){
        if (tot >= vec[l].fi){
            tot += vec[l].se;
            ans += vec[l].se;
            l++;
        } else{
            ll butuh = vec[l].fi - tot;
            if (butuh < vec[r].se){
                tot += butuh;
                ans += butuh + butuh;
                vec[r].se -= butuh;
            } else{
                tot += vec[r].se;
                ans += vec[r].se + vec[r].se;
                r--;
            }
        }
    }
    cout << ans << el;

    return 0;
}
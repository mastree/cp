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

const int N = 210;
const ll INF = 1e18;

int n;
pll ar[N];
set<pll> setdah;
pll ans[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i].fi >> ar[i].se;
    }
    setdah.insert(mp(0LL, 0LL));
    setdah.insert(mp(1LL, INF - 1LL));
    setdah.insert(mp(INF, INF));
    for (int i=1;i<=n;i++){
        auto it = setdah.lower_bound(mp(ar[i].fi + 1LL, 0LL));
        it--;
        if (it->fi <= ar[i].fi && it->se - ar[i].fi + 1LL >= ar[i].se){
            pll temp = *it;
            setdah.erase(temp);
            ans[i] = mp(ar[i].fi, ar[i].fi + ar[i].se - 1LL);
            pll depan = mp(temp.fi, ans[i].fi - 1LL);
            if (depan.se >= depan.fi){
                setdah.insert(depan);
            }
            pll bel = mp(ans[i].se + 1LL, temp.se);
            if (bel.se >= bel.fi){
                setdah.insert(bel);
            }
        }
    }
    for (int i=1;i<=n;i++){
        if (ans[i] == mp(0LL, 0LL)){
            pll temp;
            for (auto x : setdah){
                if (x.se - x.fi + 1LL >= ar[i].se){
                    temp = x;
                    break;
                }
            }
            ans[i] = mp(temp.fi, temp.fi + ar[i].se - 1LL);
            setdah.erase(temp);
            pll bel = mp(ans[i].se + 1LL, temp.se);
            if (bel.se >= bel.fi){
                setdah.insert(bel);
            }
        }
    }
    for (int i=1;i<=n;i++){
        cout << ans[i].fi << " " << ans[i].se << el;
    }

    return 0;
}
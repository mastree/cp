#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'

using namespace std;

typedef pair<ll, ll> pll;

const int N = 1e5 + 10;

int n;
vector <pll> v;
vector <pll> vans;
ll ans;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        ll a, b;
        cin >> a >> b;

        v.pb(mp(a, b));
    }
    sort(v.begin(), v.end());
    pll cur = mp(0, 0);
    for (auto x : v){
        if (cur.se < x.fi){
            vans.pb(cur);
            cur = x;
        } else{
            cur.se = max(cur.se, x.se);
        }
    }
    vans.pb(cur);
    for (auto x : vans){
        ans += (x.fi + x.se) * (x.se - x.fi + 1) / 2;
    }
    cout << ans << el;

    return 0;
}
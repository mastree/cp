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
const ll MX = 2e9;

int n;
ll m;
pll ar[N];

bool bisa(ll day){
    ll tot = 0;
    for (int i=1;i<=n;i++){
        tot += max(ar[i].se * day - ar[i].fi, 0LL);
        if (tot >= m) return 1;
    }
    return 0;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=n;i++){
        cin >> ar[i].se >> ar[i].fi;
    }
    ll l = 1, r = MX;
    while (l < r){
        ll m = (l + r) / 2;
        if (bisa(m)){
            r = m;
        } else{
            l = m + 1;
        }
    }
    cout << r << el;

    return 0;
}
#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const ll INF = 1e18;

int n;
vector<pii> vec;

ll dist(pii a, pii b) {
    ll dx = a.fi - b.fi;
    ll dy = a.se - b.se;
    return dx * dx + dy * dy;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        vec.emplace_back(a, b);
    }
    int ans = 0;
    ll mxans = INF;
    for (int i = 0; i < n; i++) {
        ll mx = 0;
        for (int j = 0; j < n; j++) {
            mx = max(mx, dist(vec[i], vec[j]));
        }
        if (mxans > mx) {
            ans = i;
            mxans = mx;
        }
    }
    cout << vec[ans].fi << " " << vec[ans].se << '\n';

    return 0;
}
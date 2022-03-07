#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using ld = long double;

const ld EPS = 1e-8;

int q;

void solve(){
    double tic, tim, tip, tv;
    cin >> tic >> tim >> tip >> tv;
    ld ic, im, ip, v;
    ic = tic;
    im = tim;
    ip = tip;
    v = tv;

    map<pair<ld, ld>, ld> dp;
    ld ans = 0;
    dp[mp(ic, im)] = 1;
    while (dp.size()){
        map<pair<ld, ld>, ld> ndp;
        for (auto& x : dp){
            ans += x.se;
            if ((x.fi.fi <= EPS && x.fi.se <= EPS)) continue;
            ld c = x.fi.fi;
            ld m = x.fi.se;
            if (c <= EPS){
                // ambil m
                ld tempm = max((ld)0, m - v);
                ndp[mp(c, tempm)] += x.se * m;
            } else if (m <= EPS){
                // ambil c
                ld tempc = max((ld)0, c - v);
                ndp[mp(tempc, m)] += x.se * c;
            } else{
                {
                    // ambil c
                    ld tempc = max((ld)0, c - v);
                    ld tempm = m + min(c, v) / 2.0;
                    ndp[mp(tempc, tempm)] += x.se * c;
                }
                {
                    // ambil m
                    ld tempm = max((ld)0, m - v);
                    ld tempc = c + min(m, v) / 2.0;
                    ndp[mp(tempc, tempm)] += x.se * m;
                }
            }
        }
        dp.swap(ndp);
    }
    cout << ans << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);
    cin >> q;
    while (q--){
        solve();
    }

    return 0;
}
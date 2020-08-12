/*
Problem from codeforces blog: 
https://codeforces.com/blog/entry/81136
*/

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

const int N = 30;
const ll MOD = 1e9 + 7;

int a, b, c, d;

// count for 1, 0
vector<pll> get_dp(int a){
    vector<pll> ret(N);

    ll beda = 0, sama = 1;
    for (int i=N - 1;i>=0;i--){
        int bit = (1 << i);
        if (a & bit){
            ret[i].fi = sama + beda;
            beda += beda + sama;
        } else{
            ret[i].fi = beda;
            beda += beda;
        }
        ret[i].se = (ll)a - ret[i].fi;
    }
    return ret;
}
vector<pll> get_dp(int a, int b){
    vector<pll> ret = get_dp(b);
    vector<pll> temp = get_dp(a - 1);
    for (int i=0;i<N;i++){
        ret[i].fi -= temp[i].fi;
        ret[i].se -= temp[i].se;
    }
    return ret;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b >> c >> d;
    auto temp1 = get_dp(a, b);
    auto temp2 = get_dp(c, d);
    ll ans = 0;
    for (int i=0;i<N;i++){
        ll bit = (1LL << i);
        ans = (ans + (temp1[i].fi * temp2[i].se % MOD + temp1[i].se * temp2[i].fi % MOD) * bit % MOD) % MOD;
    }
    cout << ans << el;

    return 0;
}
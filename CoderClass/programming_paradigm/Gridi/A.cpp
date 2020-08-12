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

const int M = 19;

ll c;
vector<pll> ans;
ll pp[M];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    pp[0] = 1;
    for (int i=1;i<M;i++){
        pp[i] = pp[i - 1] * 10LL;
    }

    cin >> c;
    while (c){
        ll len = to_string(c).size();
        ll dig = c / pp[len - 1];
        ll pilih = pp[len - 1];
        ll tot = 0;
        if (dig >= 5) pilih *= 5;
        else if (dig >= 2) pilih *= 2;
        tot = c / pilih;
        c %= pilih;
        // cout << pilih << " " << tot << el;
        ans.pb(mp(pilih, tot));
    }
    cout << ans.size() << el;
    for (auto x : ans){
        cout << x.fi << " " << x.se << el;
    }

    return 0;
}
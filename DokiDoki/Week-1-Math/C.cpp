#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll n;
ll calc(vector<ll> v, ll bag){
    ll ret = 1;
    for (auto& x : v){
        ll temp = __gcd(x, bag);
        x /= temp;
        bag /= temp;
        ret *= x;
    }
    return ret;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    ll b = 1;
    vector<ll> temp;
    for (ll i=1;i<=7;i++){
        b *= i;
        temp.pb(n - i + 1LL);
    }
    ll ans = 0;
    for (int i=0;i<3;i++){
        ans += calc(temp, b);
        b /= (ll)(7LL - i);
        temp.pop_back();
    }
    cout << ans << el;

    return 0;
}
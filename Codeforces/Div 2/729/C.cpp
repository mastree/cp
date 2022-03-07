#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;

int q;
ll n;

ll fpb(ll a, ll b){
    return __gcd(a, b);
}
ll kpk(ll a, ll b){
    ll temp = fpb(a, b);
    a /= temp;
    return a * b;
}

void solve(){
    cin >> n;
    ll ans = 0;
    ll cur = 2;
    ll all_cur = 1;
    while (n){
        ll bagi = cur / fpb(all_cur, cur);
        ans = (ans + (n - (n / bagi)) * cur) % MOD;
        // cout << cur << " " << ans << " " << n << " " << bagi << el;
        n /= bagi;
        all_cur = kpk(all_cur, cur);
        cur++;
    }
    cout << ans << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        solve();
    }

    return 0;
}
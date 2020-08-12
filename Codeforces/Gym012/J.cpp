#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const ll MX = 1e18, M = 61;

int q;
ll n;

void solve(){
    cin >> n;
    ll ans = 0;
    ll cursama = 1, curbeda = 0;
    for (int i=M;i>=0;i--){
        ll bit = (1LL << i);
        if (n & bit){
            curbeda += cursama + curbeda;
        } else{
            ans += curbeda * bit;
        }
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
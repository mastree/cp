#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int q;
void solve(){
    ll a, b;
    cin >> a >> b;
    ll ans = 0;
    while (a != b && a && b){
        if (a < b) swap(a, b);
        ll temp = (a - 1) / b;
        ans += temp;
        a -= temp * b;
    }
    if (a == 1 && b == 1){
        cout << ans << el;
    } else{
        cout << -1 << el;
    }
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
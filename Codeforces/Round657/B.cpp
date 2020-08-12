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

int q;
ll l, r, m;

void solve(){
    cin >> l >> r >> m;
    ll range = r - l;
    ll a = -1, b, c;
    for (ll i=l;i<=r;i++){
        if ((m >= i) && (m % i <= range)){
            a = i;
            b = l + m % a;
            c = l;
            break;  
        }
        if (((i - m % i) <= range)){
            a = i;
            b = l;
            c = l + a - m % a;
            break;  
        }
    }
    assert(a != -1);
    cout << a << " " << b << " " << c << el;
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
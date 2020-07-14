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
ll n, r;

ll calc(ll a){
    if (a < 0) return 0;
    return (a + 1LL) * a / 2LL;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n >> r;
        if (n == 1){
            cout << 1 << el;
            continue;
        }
        if (n == 2){
            if (r >= n){
                cout << 2 << el;
            } else{
                cout << 1 << el;
            }
            continue;
        }
        
        ll mxcon = (n / 2LL) + 1LL;
        ll temp1 = min(mxcon, r);
        if (r <= mxcon){
            cout << calc(temp1) << el;
            continue;
        }
        ll tambah = 0;
        if (r >= n){
            tambah = 1;
        }
        r = min(r, n - 1);
        cout << calc(temp1) + calc(r) - calc(mxcon) + tambah << el;
    }

    return 0;
}
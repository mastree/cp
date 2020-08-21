#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'

using namespace std;

int tc, q;
ll a, b, l, r;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--){
        cin >> a >> b >> q;
        if (a > b) swap(a, b);
        ll gg = a * b / __gcd(a, b); 
        while (q--){
            cin >> l >> r;
            l = max(l, b);
            if (b % a == 0 || l > r){
                cout << 0 << " ";
                continue;
            }
            ll ans = r - l + 1;
            ll dr = (r / gg) * gg + b - 1;
            ll plus = -(r / gg - (l - 1) / gg) * b;
            if (dr > r) plus += dr - r;
            ll rl = ((l - 1) / gg) * gg;
            if (rl + b - 1 >= l) plus -= b - (l - rl);
            cout << ans + plus << " ";
        }
        cout << el;
    }

    return 0;
}
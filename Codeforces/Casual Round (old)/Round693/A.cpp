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
ll a, b, n;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> a >> b >> n;
        ll ans = 1;
        while (a % 2 == 0 && ans < n){
            ans *= 2;
            a /= 2;
        }
        while (b % 2 == 0 && ans < n){
            ans *= 2;
            b /= 2;
        }
        if (ans >= n){
            cout << "YES" << el;
        } else{
            cout << "NO" << el;
        }
    }

    return 0;
}
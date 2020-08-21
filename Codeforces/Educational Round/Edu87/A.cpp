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

int q;
ll a, b, c, d;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> a >> b >> c >> d;

        ll ans = b;
        a -= b;
        if (a <= 0){
            cout << ans << el;
            continue;
        }
        if (d >= c){
            cout << -1 << el;
            continue;
        }
        ll beda = c - d;
        ll kali = (a + beda - 1) / beda;
        cout << ans + kali * c << el;
    }

    return 0;
}
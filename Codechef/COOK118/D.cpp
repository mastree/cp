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
ll n;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n;
        ll rn = n;
        if (n - (n & (-n)) == 0){
            cout << -1 << el;
            continue;
        }
        ll ans = 0;
        ll cur = 1;
        while (n){
            if (cur != 1) ans += cur;
            ans += (((n + 1) / 2) - 1) * cur;
            // cout << (((n + 1) / 2) - 1) * cur << " ";
            cur <<= 1;
            n >>= 1;
        }
        cout << ans << el;
    }

    return 0;
}
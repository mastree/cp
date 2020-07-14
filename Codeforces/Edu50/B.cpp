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
ll n, m, k;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n >> m >> k;
        if (n > k || m > k){
            cout << -1 << el;
            continue;
        }
        ll ans = 0;
        if (n < m) swap(n, m);
        ans += m;
        k -= m;
        n -= m; // sisa jarak
        if (n % 2 == 0 && k % 2 == 0){
            ans += k;
        } else if ((n & 1) && k % 2 == 0){
            ans += k - 1;
        } else if ((n & 1) && (k & 1)){
            ans += k - 1;
        } else{
            ans += k - 2;
        }
        cout << ans << el;
    }

    return 0;
}
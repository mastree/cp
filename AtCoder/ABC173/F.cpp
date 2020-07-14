#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e5 + 10;

ll n;
ll ans;

ll hitung(ll a, ll b){
    if (a > b) swap(a, b);
    return a * (n - b + 1LL); 
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (ll i=1;i<=n;i++){
        ans += i * ((ll)n - i + 1LL);
    }
    for (ll i=1;i<n;i++){
        ll a, b;
        cin >> a >> b;
        ans -= hitung(a, b);
    }
    cout << ans << el;

    return 0;
}
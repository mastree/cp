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

const int N = 1e5 + 10;

ll n;
pair<ll, ll> ar[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (ll i=1;i<=n;i++){
        ll a, b;
        cin >> a >> b;
        ar[i] = mp(a - b, n * b - a);
    }
    sort(ar + 1, ar + n + 1);
    ll ans = 0;
    for (ll i=1;i<=n;i++){
        ans += ar[i].fi * (n - i + 1) + ar[i].se;
    }
    cout << ans << el;

    return 0;
}
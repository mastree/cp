#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 3e5 + 10;

int n;
ll p, k;
ll ar[N];

ll calc(ll a){
    ll aa = a * a % p;
    return ((aa * aa % p - k * a % p) % p + p) % p;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> p >> k;
    unordered_map<ll, ll> cek;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        cek[calc(ar[i])]++;
    }
    ll ans = 0;
    for (auto x : cek){
        ans += x.se * (x.se - 1LL) / 2LL;
    }
    cout << ans << el;

    return 0;
}
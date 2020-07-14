#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
// #define MOD 1000000007
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'

using namespace std;

const ll MOD = 1e9 + 7;
const int H = 1e5 + 10;
const int N = 2e3 + 10;

ll h, w, n;
pair<ll, ll> ar[N];

ll fac[2 * H];

map<pair<ll, ll>, ll> cek;

ll fpow(ll a, ll b){
    if (b == 0) return 1LL;
    ll temp = fpow(a, b / 2);
    temp = temp * temp % MOD;
    if (b & 1) temp = temp * a % MOD;
    return temp;
}

ll inv(ll a){
    return fpow(a, MOD - 2);
}

ll comb(ll a, ll b){
    return fac[a] * inv(fac[a - b] * fac[b] % MOD) % MOD;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> h >> w >> n;
    fac[0] = 1;
    for (ll i=1;i<2 * H;i++){
        fac[i] = fac[i - 1] * i % MOD;
    }
    for (int i=1;i<=n;i++){
        cin >> ar[i].fi >> ar[i].se;
    }
    sort(ar + 1, ar + n + 1);
    ll ans = comb(h + w - 2, h - 1);
    for (int i=1;i<=n;i++){
        ll kur = comb(ar[i].fi + ar[i].se - 2, ar[i].fi - 1);
        for (int j=1;j<i;j++){
            pair<ll, ll> x = ar[j];
            if (x.se > ar[i].se) continue;
            pair<ll, ll> temp = mp(ar[i].fi - x.fi, ar[i].se - x.se);
            kur = (kur - cek[x] * comb(temp.fi + temp.se, temp.fi) % MOD + MOD) % MOD;
        }
        cek[ar[i]] = kur;
        kur = (kur * comb(h + w - ar[i].fi - ar[i].se, h - ar[i].fi) % MOD);
        ans = (ans - kur + MOD) % MOD;
    }
    cout << ans << el;

    return 0;
}
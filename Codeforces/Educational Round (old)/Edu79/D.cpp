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

const int N = 1e6 + 7;
const ll MOD = 998244353;

int n;
vector <ll> v[N];
ll chance[N];
ll app[N];

ll fpow(ll a, ll b){
    if (b == 0) return 1;
    ll tm = fpow(a, b/2);
    tm = (tm * tm) % MOD;
    if (b & 1) tm = (tm * a) % MOD;
    return tm;
}

ll inv(ll a){
    return fpow(a, MOD - 2);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i=1;i<=n;i++){
        int k;
        cin >> k;
        // ll invk = inv(k);
        for (int j=0;j<k;j++){
            ll x;
            cin >> x;
            v[i].pb(x);

            app[x]++;
        }
    }

    ll invn = inv(n);
    ll ans = 0;
    for (int i=1;i<=n;i++){
        int k = v[i].size();
        ll invk = inv(k);
        for (int j=0;j<k;j++){
            ll x = v[i][j];

            ll tm = invn * invk % MOD;
            tm = (tm * app[x] % MOD) * invn % MOD;
            chance[x] = (chance[x] + tm) % MOD;
        }
    }

    for (int i=1;i<N;i++){
        ans = (ans + chance[i]) % MOD;
    }
    cout << ans << el;

    return 0;
}
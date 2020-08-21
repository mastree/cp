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

const int N = 2e5 + 10;
const ll MOD = 998244353;

int n, m;
ll fac[N];

ll fpow(ll a, ll b){
    if (b == 0) return 1;
    ll temp = fpow(a, b/2);
    temp = temp * temp % MOD;
    if (b & 1){
        temp = temp * a % MOD;
    }
    return temp;
}

ll comb(ll n, ll k){
    return fac[n] * fpow(fac[k] * fac[n - k] % MOD, MOD - 2) % MOD;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    fac[0] = 1;
    for (int i=1;i<N;i++){
        fac[i] = fac[i-1] * i % MOD;
        // if (i < 10) cout << fac[i] << el;
    }
    cout << comb(m, n - 1) * (n - 2) % MOD * fpow(2, (n - 3)) % MOD << el;

    return 0;
}
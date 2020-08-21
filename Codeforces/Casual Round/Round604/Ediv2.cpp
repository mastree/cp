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

const int N = 2e5 + 7;
const ll MOD = 998244353;


int n;
ll ar[N];
ll dp[N];

ll fpow(ll a, ll b){
    if (b==0) return 1;
    ll tm = fpow(a, b/2);
    tm=(tm*tm)%MOD;
    if (b&1){
        tm=tm*a%MOD;
    }
    return tm;
}

ll inv(ll a){
    return fpow(a, MOD-2);
}

ll sol(ll base, ll a, ll b){
    ll res = b * inv(a) % MOD;
    // cout << res << el;
    return (res + (res * base)) % MOD;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=0;i<n;i++){
        cin >> ar[i];
    }

    dp[0] = 0;
    for (int i=0;i<n;i++){
        ll gcc = __gcd(ar[i],(ll)100);
        ll a = ar[i]/gcc, b = (ll)100/gcc;
        // cout << i+1 << " => " << dp[i] << " " << b << " " << a << el;
        dp[i+1] = sol(dp[i], a, b); 
    }

    cout << dp[n] << el;

    return 0;
}
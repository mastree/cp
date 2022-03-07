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

ll n;
ll pow10[N];

ll ans[N];

ll sol(ll a){
    if (a == n) return 10;
    return (2LL * 10LL * 9LL * pow10[n - a - 1] % MOD + 10LL * 9LL * 8LL * (n - a - 1LL) * pow10[n - a - 2]) % MOD;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    pow10[0] = 1;
    for (int i=1;i<N;i++){
        pow10[i] = (pow10[i - 1] * 10) % MOD;
    }

    cin >> n;
    for (ll i=1;i<=n;i++){
        cout << (sol(i) + MOD) % MOD << " ";
    }
    cout << el;

    return 0;
}
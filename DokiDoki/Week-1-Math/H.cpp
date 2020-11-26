#pragma gcc optimize ("O2")
#pragma gcc optimize ("unroll-loops")

#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e5 + 10;
const ll MOD = 1e9 + 7;

int n, k;
ll cnt[N];
vector<int> fac[N];

ll fpow(ll a, ll b){
    ll ret = 1;
    while (b){
        if (b & 1){
            ret = ret * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return ret;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i=1;i<=k;i++){
        for (int j=i + i;j<=k;j+=i){
            fac[j].pb(i);
        }
    }
    ll ans = 0;
    for (int i=k;i>=1;i--){
        ll bag = k / i;
        ll temp = fpow(bag, n);
        cnt[i] = (cnt[i] + temp + MOD) % MOD;
        ans = (ans + cnt[i] * i) % MOD;

        for (auto x : fac[i]){
            cnt[x] = (cnt[x] - cnt[i] + MOD) % MOD;
        }
    }
    cout << ans << el;

    return 0;
}
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

const ll MOD = 998244353;
const int N = 1e6 + 10;

int n;
vector<int> want[N];
int cnt[N];
ll per[N];

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

    for (ll i=1;i<=N;i++){
        per[i] = fpow(i, MOD - 2);
    }
    cin >> n;
    for (int i=1;i<=n;i++){
        int len;
        cin >> len;
        for (int j=0;j<len;j++){
            int x;
            cin >> x;
            want[i].pb(x);
            cnt[x]++;
        }
    }
    ll ans = 0;
    for (int i=1;i<=n;i++){
        int len = (int)want[i].size();
        for (auto x : want[i]){
            ll cur = (per[n] * per[len] % MOD) * (cnt[x] * per[n] % MOD) % MOD;
            ans = (ans + cur) % MOD;
        }
    }
    cout << ans << el;

    return 0;
}
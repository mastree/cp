#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e6 + 10, M = 20;
const ll MOD = 1e9 + 7;

ll n;
ll cnt[N];
ll ans;

ll fpow(ll a, ll b){
    ll ret = 1;
    while (b){
        if (b & 1){
            ret = ret * a % MOD;
        }
        b >>= 1;
        a = a * a % MOD;
    }
    return ret;
}


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        int a;
        cin >> a;
        cnt[a]++;
    }
    for (int i=0;i<M;i++){
        int bit = (1 << i);
        for (int j=1;j<N;j++){
            if (j & bit){
                cnt[j ^ bit] += cnt[j];
            }
        }
    }
    ans = (fpow(2, n) - 1LL + MOD) % MOD;
    for (int i=1;i<N;i++){
        if (cnt[i] == 0) continue;
        int bcnt = __builtin_popcount(i);
        if (bcnt & 1){
            ans = (ans - (fpow(2, cnt[i]) - 1LL + MOD) % MOD + MOD) % MOD; 
        } else{
            ans = (ans + (fpow(2, cnt[i]) - 1LL + MOD) % MOD) % MOD; 
        }
    }
    cout << ans << el;

    return 0;
}
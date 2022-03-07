#pragma gcc optimize ("O2")
#pragma gcc optimize ("unroll-loops")

#include <bits/stdc++.h>

#define el '\n'
#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

const int N = 1e6 + 10;
const int MOD = 1e9 + 7;

int n;
unordered_map<int, int> cnt;
vector<pii> vec;

ll fpow(ll a, ll b){
    ll ret = 1;
    while (b){
        if (b & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); 

    cin >> n;
    for (int i=1;i<=n;i++){
        int a;
        cin >> a;
        cnt[a]++;
    }
    {
        unordered_map<int, int> ccnt;
        for (auto& x : cnt){
            ccnt[x.se]++;
        }
        for (auto& x : ccnt){
            vec.pb(x);
        }
    }
    n = vec.size();
    unordered_map<int, ll> dp;
    dp[0] = 1;
    for (int id=0;id<n;id++){
        auto x = vec[id];
        unordered_map<int, ll> ndp;
        ll pang = fpow(2, x.se - 1);
        for (auto& y : dp){
            ndp[y.fi] = (ndp[y.fi] + y.se * pang) % MOD;
            ndp[(y.fi ^ x.fi)] = (ndp[(y.fi ^ x.fi)] + y.se * pang) % MOD;
        }
        dp.swap(ndp);
    }
    cout << dp[0] << el;

    return 0;
}
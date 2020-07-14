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

const int M = 20, B = (1 << 10);
const ll MOD = 998244353;

ll l, r, k;
pair<ll, ll> dp[M][B][2]; // cnt, cnt ans
int bitCnt[B];

ll fpow(ll a, ll b){
    if (b == 0) return 1;
    ll temp = fpow(a, b / 2);
    temp = temp * temp % MOD;
    if (b & 1) temp = temp * a % MOD;
    return temp;
}

ll calc(string s){
    int len = s.length();

    for (int i=0;i<M;i++){
        for (int j=0;j<B;j++){
            for (int k=0;k<2;k++){
                dp[i][j][k] = mp(0LL, 0LL);
            }
        }
    }
    dp[0][0][1] = mp(1LL, 0LL); // initial prefix ada 1;
    for (int i=0;i<len;i++){
        int dig = s[i] - '0';
        for (int j=0;j<B;j++){
            pair<ll, ll> cnt0 = dp[i][j][0];
            pair<ll, ll> cnt1 = dp[i][j][1];
            for (int k=(i == 0);k<10;k++){
                int temp = (1 << k);
                int nj = j | temp;
                dp[i + 1][nj][0].fi = (dp[i + 1][nj][0].fi + cnt0.fi) % MOD;
                dp[i + 1][nj][0].se = (dp[i + 1][nj][0].se + (cnt0.fi * ((ll)k) % MOD) * fpow(10LL, (ll)(len - i - 1)) % MOD + cnt0.se) % MOD;
            }
            for (int k=(i == 0);k<=dig;k++){
                int temp = (1 << k);
                int nj = j | temp;
                if (k != dig){
                    dp[i + 1][nj][0].fi = (dp[i + 1][nj][0].fi + cnt1.fi) % MOD;
                    dp[i + 1][nj][0].se = (dp[i + 1][nj][0].se + (cnt1.fi * ((ll)k) % MOD) * fpow(10LL, (ll)(len - i - 1)) % MOD + cnt1.se) % MOD;
                } else{
                    dp[i + 1][nj][1].fi = (dp[i + 1][nj][1].fi + cnt1.fi) % MOD;
                    dp[i + 1][nj][1].se = (dp[i + 1][nj][1].se + (cnt1.fi * ((ll)k) % MOD) * fpow(10LL, (ll)(len - i - 1)) % MOD + cnt1.se) % MOD;
                }
            }
        }
    }
    ll ret = 0;
    for (int i=0;i<B;i++){
        if (bitCnt[i] > k) continue;
        ret += dp[len][i][0].se;
        ret += dp[len][i][1].se;
        ret %= MOD;
    }
    return (ret % MOD + MOD) % MOD;
}

ll sol(ll a){
    ll ret = 0;
    string s = to_string(a);
    int len = s.length();
    ret = (ret + calc(s)) % MOD;

    string temp;
    for (int i=1;i<len;i++){
        temp.pb('9');
        ret = (ret + calc(temp)) % MOD;
    }
    return ret;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < B; ++i) {
		bitCnt[i] = __builtin_popcount(i);
	}

    cin >> l >> r >> k;
    cout << (sol(r) - sol(l - 1) + MOD) % MOD << el;

    return 0;
}
#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 19, M = 9, MX = 3000;

int q;
ll p10[N];
ll angmask[(1 << M)];
int bitCnt[(1 << M)];
ll dp[(1 << M)][N][MX][2];

ll calc(ll a){
    ll ret = a;
    string s = to_string(a);
    int n = s.length();
    memset(dp, 0, sizeof(dp));

    for (int mask=1;mask<(1 << M);mask++){
        dp[mask][0][0][0] = 1;
        for (int i=0;i<n;i++){
            int cur = (int)(s[i] - '0');
            int pang = n - i - 1;
            for (int j=0;j<(int)angmask[mask];j++){
                for (int dig=0;dig<=M;dig++){
                    if (dig == 0 || ((1 << (dig - 1)) & mask)){
                        if (dig < cur){
                            int tam = (1LL * dig * p10[pang]) % angmask[mask];
                            int nsisa = (j + tam) % angmask[mask];
                            dp[mask][i + 1][nsisa][1] += dp[mask][i][j][0] + dp[mask][i][j][1];
                        } else{
                            int tam = (1LL * dig * p10[pang]) % angmask[mask];
                            int nsisa = (j + tam) % angmask[mask];
                            dp[mask][i + 1][nsisa][1] += dp[mask][i][j][1];
                        }
                        if (dig == cur){
                            int tam = (1LL * dig * p10[pang]) % angmask[mask];
                            int nsisa = (j + tam) % angmask[mask];
                            dp[mask][i + 1][nsisa][0] += dp[mask][i][j][0];
                        }
                    }
                }
            }
        }
    }
    for (int mask=1;mask<(1 << M);mask++){
        for (int i=0;i<2;i++){
            if (dp[mask][n][0][i]){
                cout << mask << " " << i << " " << dp[mask][n][0][i] << el;
            }
            if (bitCnt[mask] & 1){
                ret -= dp[mask][n][0][i];
            } else{
                ret += dp[mask][n][0][i];
            }
        }
    }
    return ret;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (ll i=1;i<(1 << M);i++){
        ll cur = 1;
        bitCnt[i] = __builtin_popcount(i);
        for (ll j=0;j<(ll)M;j++){
            if ((1 << j) & i){
                cur = cur * (j + 1) / __gcd(cur, j + 1);
            }
        }
        angmask[i] = cur;
    }

    p10[0] = 1;
    for (int i=1;i<N;i++){
        p10[i] = p10[i - 1] * 10LL;
    }
    cin >> q;
    while (q--){
        ll l, r;
        cin >> l >> r;
        cout << calc(r) - calc(l - 1) << el;
    }

    return 0;
}
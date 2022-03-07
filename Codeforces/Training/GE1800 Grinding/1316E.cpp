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
const int MASK = (1 << 7);
const ll INF = 1e18;

int n, p, k;
ll ar[N];
ll s[N][7];
pair<ll, int> vec[N];
int mapid[N];

int bitCnt[MASK];

ll dp[MASK], ndp[MASK];
ll rdp[N][MASK];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i=0;i<MASK;i++){
        bitCnt[i] = __builtin_popcount(i);
    }
    cin >> n >> p >> k;
    {
        for (int i=1;i<=n;i++){
            ll a;
            cin >> a;
            vec[i] = mp(a, i);
        }
        sort(vec + 1, vec + n + 1, greater<pair<ll, int>>());
        for (int i=1;i<=n;i++){
            ar[i] = vec[i].fi;
            mapid[vec[i].se] = i;
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=0;j<p;j++){
            cin >> s[mapid[i]][j];
        }
    }
    int maskmx = (1 << p);
    fill(dp, dp + MASK, -INF);
    dp[0] = 0LL;
    for (int i=0;i<N;i++){
        fill(rdp[i], rdp[i] + MASK, -INF);
    }
    rdp[n + 1][0] = 0LL;
    for (int i=n;i>=1;i--){
        for (int j=0;j<maskmx;j++){
            rdp[i][j] = rdp[i + 1][j];
        }
        for (int mask=0;mask<maskmx;mask++){
            for (int j=0;j<p;j++){
                int bit = (1 << j);
                if (!(mask & bit)){
                    rdp[i][mask + bit] = max(rdp[i][mask + bit], rdp[i + 1][mask] + s[i][j]);
                }
            }
        }
    }
    ll ans = -INF;
    for (int i=1;i<=p + k;i++){
        for (int j=0;j<maskmx;j++){
            ndp[j] = dp[j];
        }
        for (int mask=0;mask<maskmx;mask++){
            dp[mask] = max(dp[mask], ndp[mask] + ar[i]); 
            for (int j=0;j<p;j++){
                int bit = (1 << j);
                if (!(mask & bit)){
                    dp[mask + bit] = max(dp[mask + bit], ndp[mask] + s[i][j]);
                }
            }
        }
        for (int mask=0;mask<maskmx;mask++){
            if (i - bitCnt[mask] == k){
                ans = max(ans, dp[mask] + rdp[i + 1][maskmx - mask - 1]);
            }
        }
    }
    cout << ans << el;

    return 0;
}
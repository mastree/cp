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

const int N = 5e3 + 10;
const int M = 18;
const int MASK = (1 << M);

int q;
int dp[MASK];

void solve(){
    int n, m;
    cin >> n >> m;
    int mxmask = (1 << m);
    fill(dp, dp + mxmask, 0);
    vector<int> vec(n);
    for (int i=0;i<n;i++){
        int a = 0;
        for (int j=0;j<m;j++){
            char c;
            cin >> c;
            if (c == 'y') a += (1 << j);
        }
        vec[i] = a;
        dp[a]++;
    }
    for (int i=0;i<m;i++){
        int bit = (1 << i);
        for (int j=0;j<mxmask;j++){
            if (j & bit){
                dp[j - bit] += dp[j];
            }
        }
    }
    // for (int mask=0;mask<mxmask;mask++){
    //     cout << bitset<3>(mask) << " => " << dp[mask] << el;
    // }
    ll ans = 0;
    for (int i=0;i<n;i++){
        for (int j=i + 1;j<n;j++){
            int curmask = (vec[i] | vec[j]);
            int need = mxmask - curmask - 1;
            int ada = dp[need] - ((vec[i] & need) == need) - ((vec[j] & need) == need);
            ans += ada;
        }
    }
    assert(ans % 3 == 0);
    cout << ans / 3 << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        solve();
    }

    return 0;
}
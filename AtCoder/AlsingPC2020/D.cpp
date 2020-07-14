#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e5 + 10;

int n;
string s;
int dp[N];

ll base[2];

ll fpow(ll a, ll b, ll mod){
    ll ret = 1;
    while (b){
        if (b & 1){
            ret = (ret * a) % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    dp[0] = 0;
    for (int i=1;i<N;i++){
        int cnt = __builtin_popcount(i);
        dp[i] = 1 + dp[i % cnt];
    }

    cin >> n >> s;
    ll cnt = 0;
    for (auto x : s){
        if (x == '1') cnt++;
    }
    // base -1
    if (cnt > 1){
        for (ll i=n - 1;i>=0;i--){
            if (s[i] == '1') base[0] = (base[0] + fpow(2, n - 1 - i, cnt - 1)) % (cnt - 1);
        }
    } 
    // base +1
    if (cnt < n){
        for (ll i=n - 1;i>=0;i--){
            if (s[i] == '1') base[1] = (base[1] + fpow(2, n - 1 - i, cnt + 1)) % (cnt + 1);
        }
    }

    for (int i=0;i<n;i++){
        ll p = n - 1 - i;
        ll ans = 1;
        if (s[i] == '1'){ // base -1
            if (cnt == 1){
                cout << 0 << el;
                continue;
            }
            ll temp = (base[0] - fpow(2, p, cnt - 1) + (cnt - 1)) % (cnt - 1);
            ans += dp[temp];
        } else{
            ll temp = (base[1] + fpow(2, p, cnt + 1) + (cnt + 1)) % (cnt + 1);
            ans += dp[temp];
        }
        cout << ans << el;
    }

    return 0;
}
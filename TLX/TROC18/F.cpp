#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 310;
const ll MOD = 998244353;

int n;
int ar[N], pos[N];
int butuh[N];
int bit[N];

void upd(int x, int val){
    while (x < N){
        bit[x] += val;
        x += (x & (-x));
    }
}
int ask(int x){
    int ret = 0;
    while (x){
        ret += bit[x];
        x -= (x & (-x));
    }
    return ret;
}
int ask(int a, int b){
    return ask(b) - ask(a - 1);
}
ll get_pre(ll a, ll b, ll c){
    vector<vector<ll>> dp(a + 2, vector<ll>(b + 2, 0));
    dp[0][0] = 1;
    for (int i=0;i<=a;i++){
        dp[i][0] = 1;
        int mx = c + i;
        for (int j=1;j<=mx;j++){
            if (i == 0) dp[i][j] = dp[i][j - 1];
            else dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % MOD;
        }
    }
    return dp[a][b];
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        pos[ar[i]] = i;
    }
    for (int i=1;i<=n;i++){
        upd(ar[i], 1);
        butuh[ar[i]] = ask(ar[i] + 1, n);
    }
    // int tot = 0;
    // for (int i=1;i<=n;i++){
    //     tot += butuh[i];
    // }
    // if (tot >= n){
    //     cout << 0 << el;
    //     return 0;
    // }
    ll ans = 1;
    int cur = 0;
    for (int i=2;i<=n;i++){
        cur += butuh[i - 1];
        if (butuh[i]){
            ans = ans * get_pre(cur, butuh[i], pos[i] - pos[i - 1] - 1) % MOD;
        }
    }
    cout << ans << el;

    return 0;
}
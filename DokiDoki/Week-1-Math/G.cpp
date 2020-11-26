#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e3 + 10;
const ll MOD = 1e9 + 7;

int n;
int ar[N];
bool udh[N];

int slot, bebas;
ll dp[N][N];
ll fac[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    fac[0] = 1;
    for (ll i=1;i<N;i++){
        fac[i] = fac[i - 1] * i % MOD;        
    }

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        if (ar[i] != -1) udh[ar[i]] = 1;
        else slot++;
    }
    for (int i=1;i<=n;i++){
        if (!udh[i]){
            if (ar[i] != -1) bebas++;
        }
    }
    ll ans = 0;
    int a = slot - bebas;
    int b = bebas;
    dp[a][b] = 1;
    for (int i=a;i>=1;i--){
        for (int j=0;j<=slot;j++){
            dp[i - 1][j] = (dp[i - 1][j] + dp[i][j] * j) % MOD;
            if (i >= 2) dp[i - 2][j + 1] = (dp[i - 2][j + 1] + dp[i][j] * (i - 1)) % MOD;
        }
    }
    for (int i=0;i<=slot;i++){
        ans = (ans + dp[0][i] * fac[i]) % MOD;
    }
    cout << ans << el;

    return 0;
}
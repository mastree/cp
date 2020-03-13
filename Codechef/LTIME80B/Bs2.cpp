#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'

using namespace std;

const ll MOD = 1e9 + 7;
const int N = 1e5 + 10;

int q;
ll n, m;
ll dp[N][2]; // 0 = beda, 1 = consecutive

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n >> m;
        dp[1][0] = m;
        dp[1][1] = 0;
        for (int i=2;i<=n;i++){
            dp[i][0] = (dp[i-1][0] * (m - 1) % MOD + dp[i-1][1] * (m - 1) % MOD) % MOD;
            dp[i][1] = dp[i-1][0];
        }
        cout << (dp[n][0] + dp[n][1]) % MOD << el;
    }

    return 0;
}
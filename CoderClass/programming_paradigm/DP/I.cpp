#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e3 + 10, M = 3e4 + 10;
const int INF = 1e9;

int n, m;
int ar[N];
int dp[M];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    fill(dp, dp + m + 2, INF);
    dp[0] = 0;
    for (int i=1;i<=n;i++){
        for (int j=m;j>=ar[i];j--){
            dp[j] = min(dp[j], dp[j - ar[i]] + 1);
        }
    }
    if (dp[m] == INF){
        cout << -1 << el;
        return 0;
    }
    cout << dp[m] << el;

    return 0;
}
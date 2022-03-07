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
const int K = 10;
const int INF = 1e9 + 10;

int n, k;
int ar[N];
int c[K][K];

int dp[N];
int pre[N];

int bef[K];

int cost(int i, int j){
    return pre[j] - pre[i] - c[ar[i]][ar[j]];
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i=1;i<=n;i++){
        char c;
        cin >> c;
        ar[i] = c - '0';
    }
    for (int i=1;i<=k;i++){
        for (int j=1;j<=k;j++){
            cin >> c[i][j];
        }
    }
    for (int i=2;i<=n;i++){
        pre[i] = pre[i - 1] + c[ar[i - 1]][ar[i]];
    }
    fill(dp + 1, dp + n + 2, -INF);
    fill(bef, bef + K, -INF);
    for (int i=1;i<=n;i++){
        dp[i] = max(dp[i], dp[i - 1]);
        for (int j=1;j<=k;j++){
            if (bef[j] != -INF){
                dp[i] = max(dp[i], bef[j] - c[j][ar[i]]);
                bef[j] += c[ar[i]][ar[i + 1]];
            }
        }
        if (i < n) bef[ar[i]] = max(bef[ar[i]], dp[i] + c[ar[i]][ar[i + 1]]);
    }
    cout << dp[n] << el;

    return 0;
}
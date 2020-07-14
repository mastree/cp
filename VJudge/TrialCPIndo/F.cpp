#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'

using namespace std;

const int N = 1e4 + 10;
const int INF = 1e9;

int n, m;
int dp[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=n;i++){
        dp[i] = n - i;
    }
    for (int i=n + 1;i<=m;i++){
        int hi = (i + 1) / 2;
        if (i & 1) dp[i] = dp[hi] + 2;
        else dp[i] = dp[hi] + 1;
    }
    cout << dp[m] << el;

    return 0;
}
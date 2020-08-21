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

const int N = 1e5 + 8;
const int INF = 1e9;

int n;
int ar[N];
int dp[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }

    fill(dp, dp + n + 1, INF);
    dp[0] = -INF;

    for (int i=1;i<=n;i++){
        int j = (int)(upper_bound(dp, dp + n + 1, ar[i]) - dp);
        if (dp[j-1] < ar[i] && ar[i] < dp[j]){
            dp[j] = ar[i];
        }
    }
    int ans = 0;
    for (int i=0;i<=n;i++){
        if (dp[i] < INF) ans = i;
    }
    cout << ans << el;

    return 0;
}
#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define ll long long
#define el '\n'

using namespace std;

int n;
ll dp[2][100005];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    ll ar[2][n+1];
    ar[0][0]=0;
    ar[1][0]=0;
    for (ll i=1;i<=n;i++){
        cin >> ar[0][i];
    }

    for (int i=1;i<=n;i++){
        cin >> ar[1][i];
    }

    dp[0][1]=ar[0][1];
    dp[1][1]=ar[1][1];
    for (int i=2;i<=n;i++){
        dp[0][i]=max(dp[1][i-2]+ar[0][i],dp[1][i-1]+ar[0][i]);
        dp[1][i]=max(dp[0][i-2]+ar[1][i],dp[0][i-1]+ar[1][i]);
    }

    cout << max(dp[0][n],dp[1][n]) << el;

    return 0;
}
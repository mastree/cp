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

const int N = 200;
const int INF = 1e9;

int n;
int ar[N];
int dp[N][2]; // isti, kontes, gym;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    for (int i=0;i<=n;i++){
        for (int j=0;j<2;j++){
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;
    dp[0][1] = 0;
    for (int i=1;i<=n;i++){
        dp[i][0] = dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + 1;
        if (ar[i] == 1){
            dp[i][0] = min(dp[i][0], dp[i - 1][1]);
        } else if (ar[i] == 2){
            dp[i][1] = min(dp[i][1], dp[i - 1][0]);
        } else if (ar[i] == 3){
            dp[i][0] = min(dp[i][0], dp[i - 1][1]);
            dp[i][1] = min(dp[i][1], dp[i - 1][0]);
        }
    }
    cout << min(dp[n][0], dp[n][1]) << el;

    return 0;
}
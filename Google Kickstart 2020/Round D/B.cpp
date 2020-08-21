#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e4 + 10;
const int INF = 1e9;

int n, q;
int ar[N];
int dp[N][4];

void solve(){
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    for (int i=2;i<=n;i++){
        fill(dp[i], dp[i] + 4, INF);
    }
    for (int i=2;i<=n;i++){
        for (int j=0;j<4;j++){
            if (ar[i - 1] == ar[i]){
                dp[i][j] = dp[i - 1][j];
            } else if (ar[i - 1] < ar[i]){
                for (int k=0;k<j;k++){
                    dp[i][j] = min(dp[i][j], dp[i - 1][k]);
                }
            } else{
                for (int k=j + 1;k<4;k++){
                    dp[i][j] = min(dp[i][j], dp[i - 1][k]);
                }
            }
            for (int k=0;k<4;k++) dp[i][j] = min(dp[i][j], dp[i - 1][k] + 1);
        }
    }
    int ans = INF;
    for (int i=0;i<4;i++){
        ans = min(ans, dp[n][i]);
    }
    cout << ans << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    for (int cas=1;cas<=q;cas++){
        cout << "Case #" << cas << ": ";
        solve();
    }

    return 0;
}
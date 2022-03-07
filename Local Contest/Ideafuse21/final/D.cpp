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
const int INF = 1e9 + 10;

int q;
int n;
int ar[N];
bool dp[N][N][2][2]; // le, ri, is first player move, is odd = can

int pre[N];

void solve(){
    cin >> n;
    int tot = 0;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        ar[i] %= 2;
        tot += ar[i];
        pre[i] = (pre[i - 1] ^ ar[i]);
    }
    if (tot & 1 ^ 1){
        cout << 0 << el;
        return;
    }
    for (int i=1;i<=n + 1;i++){
        dp[i][i - 1][0][0] = dp[i][i - 1][1][0] = 1;
        dp[i][i - 1][0][1] = dp[i][i - 1][1][1] = 0;
    }
    for (int len=1;len<=n;len++){
        for (int le=1;le + len - 1<=n;le++){
            int ri = le + len - 1;
            if (len == 1){
                for (int p=0;p<2;p++){
                    dp[le][ri][p][ar[le]] = 1;
                    dp[le][ri][p][!ar[le]] = 0;
                }
            } else{
                for (int p=0;p<2;p++){
                    if (dp[le + 1][ri][p][0]){
                        dp[le][ri][p][0] |= !ar[le];
                        dp[le][ri][p][1] |= ar[le];
                    }
                    if (dp[le][ri - 1][p][0]){
                        dp[le][ri][p][0] |= !ar[ri];
                        dp[le][ri][p][1] |= ar[ri];
                    }
                    if (dp[le + 1][ri][p][1]){
                        dp[le][ri][p][0] |= ar[le];
                        dp[le][ri][p][1] |= !ar[le];
                    }
                    if (dp[le][ri - 1][p][1]){
                        dp[le][ri][p][0] |= ar[ri];
                        dp[le][ri][p][1] |= !ar[ri];
                    }

                    if (!dp[le + 1][ri][!p][0]){
                        if (pre[ri] ^ pre[le]) dp[le][ri][p][ar[le]] |= 1;
                        else dp[le][ri][p][!ar[le]] != 1;
                    }
                    if (!dp[le][ri - 1][!p][0]){
                        if (pre[ri - 1] ^ pre[le - 1]) dp[le][ri][p][ar[ri]] |= 1;
                        else dp[le][ri][p][!ar[ri]] != 1;
                    }
                    if (!dp[le + 1][ri][!p][1]){
                        if (pre[ri] ^ pre[le]) dp[le][ri][p][!ar[le]] |= 1;
                        else dp[le][ri][p][ar[le]] != 1;
                    }
                    if (!dp[le][ri - 1][!p][1]){
                        if (pre[ri - 1] ^ pre[le - 1]) dp[le][ri][p][!ar[ri]] |= 1;
                        else dp[le][ri][p][ar[ri]] != 1;
                    }
                    cout << le << " " << ri << " " << p << " => " << dp[le][ri][p][0] << " " << dp[le][ri][p][1] << el;
                }
            }
        }
    }
    int ans = 0;
    for (int i=2;i<=n;i++){
        if (!dp[i][n][0][1]) ans++;
    }
    for (int i=0;i<n;i++){
        if (!dp[1][i][0][1]) ans++;
    }
    cout << ans << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    for (int i=1;i<=q;i++){
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}
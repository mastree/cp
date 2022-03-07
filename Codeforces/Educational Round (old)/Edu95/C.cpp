#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e5 + 10;
const int INF = 1e9;

int n, q;
int ar[N];
int dp[N][2]; // 0 = friend, 1 me

void solve(){
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    for (int i=0;i<=n;i++){
        for (int j=0;j<2;j++){
            dp[i][j] = INF;
        }
    }
    dp[0][1] = 0;
    for (int i=1;i<=n;i++){
        int tam = 0;
        for (int j=1;j<=2;j++){
            int bi = i - j;
            if (bi < 0) break;
            tam += ar[bi + 1];
            // friend
            dp[i][0] = min(dp[i][0], dp[bi][1] + tam);
            // me
            dp[i][1] = min(dp[i][1], dp[bi][0]);
        }
    }
    cout << min(dp[n][0], dp[n][1]) << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        solve();
    }

    return 0;
}
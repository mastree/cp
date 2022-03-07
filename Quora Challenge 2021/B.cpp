#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e3 + 10;
const ll MOD = 1e9 + 7;

int n;
bool ar[N][N];
pair<ll, int> dp[N][N];

pair<ll, int> merge(const pair<ll, int>& a, const pair<ll, int>& b){
    pair<ll, int> ret = mp(0LL, 0);
    if (a.se == b.se){
        ret = mp((a.fi + b.fi) % MOD, a.se);
    } else if (a.se > b.se){
        ret = a;
    } else{
        ret = b;
    }
    return ret;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            char c;
            cin >> c;
            ar[i][j] = (c == '1');
        }
    }   
    dp[1][1] = mp(1LL, ar[1][1]);
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if (i == 1 && j == 1) continue;
            dp[i][j] = merge(dp[i - 1][j], dp[i][j - 1]);
            if (ar[i][j]) dp[i][j].se++;
        }
    }
    cout << dp[n][n].se << " " << dp[n][n].fi << el;

    return 0;
}
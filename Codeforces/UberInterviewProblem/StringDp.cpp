/*
Source: https://codeforces.com/blog/entry/81364
*/
#pragma gcc optimize ("O3")
#pragma gcc optimize ("unroll-loops")

#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 110;
const ll MOD = 1e9 + 7;

int n, m, k;
string a, b, c;
ll dp[N][N][N]; // [pos_a][pos_b][pos_c] = count

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b >> c;
    n = a.size();
    m = b.size();
    k = c.size();

    // 1-indexing
    a = "*" + a;
    b = "*" + b;
    c = "*" + c;

    dp[0][0][0] = 1;
    for (int i=0;i<=n;i++){
        for (int j=0;j<=m;j++){
            for (int len=0;len<k;len++){
                if (dp[i][j][len]){
                    for (int ni=i + 1;ni<=n;ni++){
                        if (a[ni] == c[len + 1]){
                            dp[ni][j][len + 1] = (dp[ni][j][len + 1] + dp[i][j][len]) % MOD;
                        }
                    }
                    for (int nj=j + 1;nj<=m;nj++){
                        if (b[nj] == c[len + 1]){
                            dp[i][nj][len + 1] = (dp[i][nj][len + 1] + dp[i][j][len]) % MOD;
                        }
                    }
                }
            }
        }
    }
    ll ans = 0;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            ans = (ans + dp[i][j][k]) % MOD;
        }
    }
    cout << ans << el;

    return 0;
}
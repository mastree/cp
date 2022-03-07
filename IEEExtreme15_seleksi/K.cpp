#pragma gcc optimize("O2")
#pragma gcc optimize("unroll-loops")

#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 3e4 + 10;
const int R = 500;
const int MOD = 1e9 + 7;

int n, k;

int _dp[N][R + R + 10]; // pulau, last kapal

int& dp(int i, int j){
    return _dp[i][j - k + R];
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    dp(k, k) = 1;
    int l = max(k - R, 1);
    int r = min(k + R, n);
    for (int i=k;i<n;i++){
        for (int j=l;j<=r;j++){
            for (int del=-1;del<=1;del++){
                int nj = j + del;
                if (nj < l || r < nj || i + nj > n) continue;
                int ni = i + nj;
                dp(ni, nj) = (dp(ni, nj) + dp(i, j)) % MOD;
            }
        }
    }
    int ans = 0;
    for (int i=l;i<=r;i++){
        ans = (ans + dp(n, i)) % MOD;
    }
    cout << ans << el;

    return 0;
}
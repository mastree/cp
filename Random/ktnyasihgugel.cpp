#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ll long long
#define el '\n'

using namespace std;

/* Given a Bintree
Output the number of leaf pairs that has maximum distance of DIST
*/

const int N = 20;

int n, DIST;
int ar[(1 << N) * 2 + 10];
ll dp[(1 << N) * 2 + 10][N];

ll dfs(int node, int dep){
    ll ans = 0;
    int le = node * 2;
    int ri = le + 1;

    if (dep == n || (ar[le] == -1 && ar[ri] == -1)){
        dp[node][0] = 1;
        return 0;
    }
    if (ar[le] != -1) ans += dfs(le, dep + 1);
    if (ar[ri] != -1) ans += dfs(ri, dep + 1);

    for (int i=1;i<=N;i++){
        for (int j=1;j<=N;j++){
            if (i + j <= DIST) ans += dp[le][i - 1] * dp[ri][j - 1];
        }
    }
    for (int i=1;i<N;i++){
        dp[node][i] = dp[le][i - 1] + dp[ri][i - 1];
    }
    return ans;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> DIST;
    for (int i=1;i<(1 << n);i++){
        cin >> ar[i];
    }

    cout << dfs(1, 1) << el;

    return 0;
}
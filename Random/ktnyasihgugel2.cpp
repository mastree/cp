#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ll long long
#define el '\n'

using namespace std;

const int N = 110;

int n, m;
int sx, sy, sz, fx, fy, fz;
ll mat[N][N];
ll dp[2][N][N][N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    cin >> sx >> sy >> sz >> fx >> fy >> fz;
    // asumsi sx < sy < sz
    // otherwise, u need to sort the starting position and the end position(as a pair) according to the starting position

    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cin >> mat[i][j];
        }
    }
    dp[0][sx][sy][sz] = mat[1][sx] + mat[1][sy] + mat[1][sz];

    for (int i=2;i<=n;i++){
        int prefId, curId;
        if (i & 1){
            prefId = 1;
            curId = 0;
        } else{
            prefId = 0;
            curId = 1;
        }
        for (int j=1;j<=m;j++) for (int k=1;k<=m;k++) for (int l=1;l<=m;l++) dp[curId][j][k][l] = 0;
        for (int j=1;j<=m;j++){
            for (int k=j + 1;k<=m;k++){
                for (int l=k + 1;l<=m;l++){
                    for (int p1=-1;p1<=1;p1++) for (int p2=-1;p2<=1;p2++) for (int p3=-1;p3<=1;p3++){
                        int _j = j + p1;
                        int _k = k + p2;
                        int _l = l + p3;
                        if (_j < _k && _k < _l){
                            dp[curId][j][k][l] = max(dp[curId][j][k][l], dp[prefId][_j][_k][_l] + ar[curId][j] + ar[curId][k] + ar[curId][l]);
                        }
                    } 
                }
            }
        }
    }
    cout << dp[(n + 1) & 1][fx][fy][fz] << el;

    return 0;
}
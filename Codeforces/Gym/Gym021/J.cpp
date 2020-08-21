#pragma gcc optimize ("O2")
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

struct Merch{
// “greedy”, “honest”, “generous” = 0, 1, 2
    int tipe;
    int pack, cost;
    Merch(){}
    Merch(int a, int b, int c) : tipe(a), pack(b), cost(c) {}
};

const int N = 110;
const int INF = 1e9;

int g, c, n; // gold to silver, gold count, merchants

Merch ar[N];
int dp[N][N * N]; // pos, gold, silver
int bdp[N][N * N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> g >> c >> n;
    for (int i=1;i<=n;i++){
        string tipe;
        int a, b, c;
        cin >> tipe >> b >> c;
        if (tipe[1] == 'r') a = 0;
        else if (tipe[1] == 'o') a = 1;
        else a = 2;
        ar[i] = Merch(a, b, c);
    }
    for (int i=0;i<N;i++){
        fill(dp[i], dp[i] + N * N, -INF);
    }
    dp[c][0] = 0;
    int mxs = g * n;
    for (int pos=1;pos<=n;pos++){
        for (int i=0;i<=c;i++){
            for (int j=0;j<=mxs;j++){
                bdp[i][j] = dp[i][j];
            }
        }
        for (int i=0;i<=c;i++){
            for (int j=0;j<=mxs;j++){
                if (bdp[i][j] == -INF) continue;
                if (j >= ar[pos].cost){
                    dp[i][j - ar[pos].cost] = max(dp[i][j - ar[pos].cost], bdp[i][j] + 1);
                    if (ar[pos].tipe == 2) continue;
                }
                int ni, nj; 
                if (i == 0) continue;
                if (ar[pos].tipe == 0){
                    ni = i - 1;
                    int sisa = g - ar[pos].cost;

                    int balik = (sisa / ar[pos].pack) * ar[pos].pack;
                    nj = j + balik;
                    dp[ni][nj] = max(dp[ni][nj], bdp[i][j] + 1);
                } else if (ar[pos].tipe == 1){
                    ni = i - 1;
                    int sisa = g - ar[pos].cost;

                    int balik = ((sisa + (ar[pos].pack / 2)) / ar[pos].pack) * ar[pos].pack;
                    nj = j + balik;
                    dp[ni][nj] = max(dp[ni][nj], bdp[i][j] + 1);
                } else{
                    ni = i - 1;
                    int sisa = g - ar[pos].cost;

                    int balik = ((sisa + (ar[pos].pack - 1)) / ar[pos].pack) * ar[pos].pack;
                    nj = j + balik;
                    dp[ni][nj] = max(dp[ni][nj], bdp[i][j] + 1);
                }
            }
        }
    }
    int mx = 0;
    for (int i=0;i<=c;i++){
        for (int j=0;j<=mxs;j++){
            mx = max(mx, dp[i][j]);
        }
    }
    cout << mx << el;

    return 0;
}
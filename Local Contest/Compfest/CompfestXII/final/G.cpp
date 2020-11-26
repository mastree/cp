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
const int INF = 1e9;

int n, m;
char ar[N][N];
int dp[2][N][N];

pii awalc, awalm;

int di[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dj[8] = {1, -1, 0, 0, 1, 1, -1, -1};

bool ada[N * 2];

void solve(){
    for (int i=0;i<2;i++){
        for (int j=0;j<N;j++){
            for (int k=0;k<N;k++){
                dp[i][j][k] = INF;
            }
        }
    }
    queue<pii> q;
    dp[0][awalc.fi][awalc.se] = 0;
    q.push(awalc);
    while (!q.empty()){
        auto fr = q.front();
        q.pop();
        for (int i=0;i<8;i++){
            int ni = fr.fi + di[i];
            int nj = fr.se + dj[i];

            if (ar[ni][nj] == '#') continue;
            if (dp[0][ni][nj] > dp[0][fr.fi][fr.se] + 1){
                dp[0][ni][nj] = dp[0][fr.fi][fr.se] + 1;
                q.push(mp(ni, nj));
            }
        }
    }
    dp[1][awalm.fi][awalm.se] = 0;
    q.push(awalm);
    while (!q.empty()){
        auto fr = q.front();
        q.pop();
        for (int i=0;i<8;i++){
            int ni = fr.fi + di[i];
            int nj = fr.se + dj[i];

            if (ar[ni][nj] == '#') continue;
            if (dp[1][ni][nj] > dp[1][fr.fi][fr.se] + 1){
                dp[1][ni][nj] = dp[1][fr.fi][fr.se] + 1;
                q.push(mp(ni, nj));
            }
        }
    }
    bool lolos = 0;
    // int last = 0;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (ar[i][j] == '#') continue;
            if (dp[0][i][j] == INF && dp[1][i][j] != INF){
                lolos = 1;
            }
        }
    }
    // for (int i=1;i<=n;i++){
    //     for (int j=1;j<=m;j++){
    //         if (ar[i][j] == '#') cout << -1 << " ";
    //         else cout << dp[0][i][j] << " ";
    //     }
    //     cout << el;
    // }
    // cout << el;
    // for (int i=1;i<=n;i++){
    //     for (int j=1;j<=m;j++){
    //         if (ar[i][j] == '#') cout << -1 << " ";
    //         else cout << dp[1][i][j] << " ";
    //     }
    //     cout << el;
    // }
    
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=0;i<=n + 1;i++){
        for (int j=0;j<=m + 1;j++){
            ar[i][j] = '#';
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cin >> ar[i][j];
            if (ar[i][j] == 'C') awalc = mp(i, j);
            else if (ar[i][j] == 'M') awalm = mp(i, j);
        }
    }
    solve();

    return 0;
}
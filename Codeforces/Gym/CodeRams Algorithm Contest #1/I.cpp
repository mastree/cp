#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 210;
const int K = 410;
const int INF = 1e9;

vector<int> di = {1, -1, 0, 0};
vector<int> dj = {0, 0, 1, -1};

int n, k;
bool ar[N][N];
bool vis[N][N];
int gaps[K];
vector<pii> belt;

void dfs(pii node){
    vis[node.fi][node.se] = 1;
    belt.pb(node);
    for (int i=0;i<4;i++){
        pii nnode = mp(node.fi + di[i], node.se + dj[i]);
        if (nnode.fi < 1 || n < nnode.fi || nnode.se < 1 || n < nnode.se || !ar[nnode.fi][nnode.se] || vis[nnode.fi][nnode.se]) continue;
        dfs(nnode);
    }
}
int manhat(pii a, pii b){
    return abs(a.fi - b.fi) + abs(a.se - b.se);
}

int dp[K][K]; // take, cap

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    dp[0][0] = INF;
    cin >> n >> k;
    pii awal = mp(-1, -1);
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            char c;
            cin >> c;
            ar[i][j] = (c == 'x');
            if (awal.fi == -1 && ar[i][j]) awal = mp(i, j);
        }
    }
    dfs(awal);
    int len = belt.size();
    for (int gap=0;gap<=len;gap++){
        int cur = INF;
        for (int i=0;i<len;i++){
            int ni = (i + gap) % len;
            cur = min(cur, manhat(belt[i], belt[ni]));
        }
        gaps[gap] = cur;
    }
    for (int i=1;i<=k;i++){
        for (int j=1;j<=len;j++){
            for (int take=1;take<=j;take++){
                dp[i][j] = max(dp[i][j], min(dp[i - 1][j - take], gaps[take]));
            }
        }
    }
    cout << dp[k][len] << el;

    return 0;
}
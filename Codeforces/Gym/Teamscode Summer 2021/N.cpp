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
const int INF = 1e9 + 10;

int n, m, k;
bool gud[N][N];
vector<pii> tele[N][N];
int di[] = {1, -1, 0, 0};
int dj[] = {0, 0, 1, -1};
int dp[N][N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            char c;
            cin >> c;
            gud[i][j] = c == '.';
            dp[i][j] = INF;
        }
    }
    for (int i=1;i<=k;i++){
        int a, b, ta, tb;
        cin >> a >> b >> ta >> tb;
        tele[a][b].pb(mp(ta, tb));
    }
    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;
    pq.push(mp(0, mp(1, 1)));
    while (!pq.empty()){
        int cur = pq.top().fi;
        pii node = pq.top().se;
        pq.pop();
        if (!gud[node.fi][node.se]) continue;
        gud[node.fi][node.se] = 0;
        dp[node.fi][node.se] = cur;
        if (tele[node.fi][node.se].size()){
            for (auto& x : tele[node.fi][node.se]){
                if (gud[x.fi][x.se]) pq.push(mp(cur, mp(x.fi, x.se)));
            }
        } else{
            for (int i=0;i<4;i++){
                int ni = node.fi + di[i];
                int nj = node.se + dj[i];
                if (ni < 1 || n < ni || nj < 1 || m < nj) continue;
                if (gud[ni][nj]) pq.push(mp(cur + 1, mp(ni, nj)));
            }
        }
    }
    cout << dp[n][m] << el;

    return 0;
}
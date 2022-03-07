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

int n, m;
int mcnt;
int ar[N][N];

int di[] = {0, 0, 1, -1};
int dj[] = {1, -1, 0, 0};

int solve(int r, int c){
    priority_queue<pair<int, pii>> pq;
    vector<vector<bool>> vis(n + 2, vector<bool>(m + 2, 1));
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            vis[i][j] = 0;
        }
    }
    int ans = 0;
    int cur = 0;
    vis[r][c] = 1;
    pq.push(mp(ar[r][c], mp(r, c)));
    while (!pq.empty() && cur < mcnt){
        auto tp = pq.top();
        int val = tp.fi;
        pii node = tp.se;
        pq.pop();
        ans += val;
        cur++;
        for (int i=0;i<4;i++){
            pii nnode = {node.fi + di[i], node.se + dj[i]};
            if (vis[nnode.fi][nnode.se]) continue;
            vis[nnode.fi][nnode.se] = 1;
            pq.push(mp(ar[nnode.fi][nnode.se], nnode));
        }
    }
    return ans;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cin >> ar[i][j];
        }
    }
    cin >> mcnt;
    int ans = 0;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            ans = max(ans, solve(i, j));
        }
    }
    cout << ans << el;

    return 0;
}
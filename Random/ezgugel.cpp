#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 3e3 + 10;
const int INF = 1e9;

int n;
char ar[N][N];
pii s, e;

bool vis[N][N];
queue<pii> qu[N + N]; 

int di[4] = {0, 0, 1, -1};
int dj[4] = {1, -1, 0, 0};
char cek[4] = {'R', 'L', 'D', 'U'};

int solve(){
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            vis[i][j] = 0;
        }
    }
    qu[0].push(s);
    for (int cost=0;cost<=2 * n;cost++){
        while (!qu[cost].empty()){
            auto node = qu[cost].front();
            qu[cost].pop();
            if (vis[node.fi][node.se]) continue;
            if (node == e) return cost;
            vis[node.fi][node.se] = 1;
            for (int i=0;i<4;i++){
                pii nnode = {node.fi + di[i], node.se + dj[i]};
                if (nnode.fi < 1 || nnode.fi > n || nnode.se < 1 || nnode.se > n) continue;
                if (vis[nnode.fi][nnode.se]) continue;
                int ncost = cost;
                if (cek[i] != ar[node.fi][node.se]) ncost++;
                qu[ncost].push(nnode);
            }
        }
    }
    return INF;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cin >> ar[i][j];
        }
    }
    cin >> s.fi >> s.se;
    cin >> e.fi >> e.se;
    cout << solve() << el;

    return 0;
}
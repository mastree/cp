#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int ID = 1e4 + 10;
const int INF = 1e9 + 7;
const int MV = 8;

int n, m;
vector<vector<int>> grid; // 0 = . / A / B , 1 = #
pii a, b;

int di[8] = {0, 0, -1, 1, 1, -1, 1, -1};
int dj[8] = {-1, 1, 0, 0, -1, 1, 1, -1};

int getid(int i, int j){
    return (i - 1) * m + j;
}
int getid(pii a){
    return getid(a.fi, a.se);
}
pii getpos(int id){
    int i = ((id - 1) / m) + 1;
    int j = id - (i - 1) * m;
    return mp(i, j);
}

int dp[ID][MV + 1][MV + 1][MV + 1];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    grid.resize(n + 2, vector<int>(m + 2, 1));
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            char c;
            cin >> c;
            if (c == '#') continue;
            grid[i][j] = 0;
            if (c == 'A'){
                a = mp(i, j);
            } else if (c == 'B'){
                b = mp(i, j);
            }
        }
    }
    for (int i=0;i<ID;i++){
        for (int j=0;j<=MV;j++){
            for (int k=0;k<=MV;k++){
                for (int l=0;l<=MV;l++){
                    dp[i][j][k][l] = INF;
                }
            }
        }
    }
    int aid = getid(a);
    int bid = getid(b);
    dp[aid][8][8][8] = 0;
    queue<pair<int, vector<int>>> q;
    q.push(mp(aid, vector<int>({8, 8, 8})));
    while (!q.empty()){
        auto cur = q.front();
        q.pop();
        int id = cur.fi;
        pii node = getpos(cur.fi);
        vector<int> last = cur.se;
        vector<int> nx = {last[1], last[2]};
        for (int i=0;i<8;i++){
            bool ada = 0;
            for (auto& x : last) if (x == i){
                ada = 1;
                break;
            }
            if (ada) continue;
            nx.pb(i);
            pii nnode = mp(node.fi + di[i], node.se + dj[i]);
            if (grid[nnode.fi][nnode.se] == 0){
                int nid = getid(nnode);
                if (dp[nid][nx[0]][nx[1]][nx[2]] == INF){
                    dp[nid][nx[0]][nx[1]][nx[2]] = dp[id][last[0]][last[1]][last[2]] + 1;
                    q.push(mp(nid, nx));

                    if (nid == bid){
                        cout << dp[nid][nx[0]][nx[1]][nx[2]] << el;
                        return 0;
                    }
                }
            }
            nx.pop_back();
        }
    }
    cout << -1 << el;

    return 0;
}
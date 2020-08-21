#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'

using namespace std;

const int N = 1e3 + 10;

int n, m, k;
int ar[N][N], pc[N][N];
int dp[N][N];

set<int> row[N], col[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    for (int i=1;i<=n;i++){
        string s;
        cin >> s;
        for (int j=1;j<=m;j++){
            ar[i][j] = (s[j - 1] == '#');
            row[i].insert(j);
            col[j].insert(i);
        }
    }
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    for (int i=0;i<=n + 2;i++) for (int j=0;j<=m + 2;j++) dp[i][j] = -1;
    queue<pair<pii, int>> qu;
    qu.push(mp(mp(x1, y1), 0));
    while (!qu.empty()){
        auto temp = qu.front();
        pii cur = temp.fi;
        int cost = temp.se;
        qu.pop();
        row[cur.fi].erase(cur.se);
        col[cur.se].erase(cur.fi);
        if (dp[cur.fi][cur.se] != -1) continue;
        dp[cur.fi][cur.se] = cost;

        vector<pair<pii, int>> exp;
        auto icolb = col[cur.se].lower_bound(cur.fi);
        auto icola = icolb;
        if (icola != col[cur.se].begin()){
            icola--;
            while (!ar[*icola][cur.se] && (cur.fi - *icola) <= k){
                exp.pb(mp(mp(*icola, cur.se), cost + 1));
                if (icola == col[cur.se].begin()) break;
                icola--;
            }
        } 
        if (icolb != col[cur.se].end()){
            while (!ar[*icolb][cur.se] && (*icolb - cur.fi) <= k){
                exp.pb(mp(mp(*icolb, cur.se), cost + 1));
                icolb++;
                if (icolb == col[cur.se].end()) break;
            }
        }
        auto irowb = row[cur.fi].lower_bound(cur.se);
        auto irowa = irowb;
        if (irowa != row[cur.fi].begin()){
            irowa--;
            while (!ar[cur.fi][*irowa] && (cur.se - *irowa) <= k){
                exp.pb(mp(mp(cur.fi, *irowa), cost + 1));
                if (irowa == row[cur.fi].begin()) break;
                irowa--;
            }
        } 
        if (irowb != row[cur.fi].end()){
            while (!ar[cur.fi][*irowb] && (*irowb - cur.se) <= k){
                exp.pb(mp(mp(cur.fi, *irowb), cost + 1));
                irowb++;
                if (irowb == row[cur.fi].end()) break;
            }
        }
        for (auto x : exp){
            qu.push(x);
            row[cur.fi].erase(x.fi.se);
            col[cur.se].erase(x.fi.fi);
        }
    }
    cout << dp[x2][y2] << el;

    return 0;
}
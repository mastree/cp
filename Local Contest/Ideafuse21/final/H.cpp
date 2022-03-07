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
const int INF = 1e9 + 10;

const vector<int> di = {0, 0, -1, 1};
const vector<int> dj = {-1, 1, 0, 0};

int q;
int n;
int s, b, m; // stamina, cur battery power, battery cap
int ar[N][N];
pii aw, ak;

bool is_valid(int r, int c){
    return 1 <= r && r <= n && 1 <= c && c <= n;
}

int dp[N][N][N]; // stamina, node = spending battery
priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq[N]; // spend, node
void dijkstra(){
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            for (int k=0;k<N;k++){
                dp[i][j][k] = INF;
            }
        }
    }
    dp[s][aw.fi][aw.se] = m - b;
    pq[s].push(mp(m - b, aw));
    for (int i=s;i>=0;i--){
        while (!pq[i].empty()){
            int nodex = pq[i].top().se.fi;
            int nodey = pq[i].top().se.se;
            int cur = pq[i].top().fi;
            pq[i].pop();
            if (cur > dp[i][nodex][nodey]) continue;
            for (int id=0;id<4;id++){
                int nnodex = nodex + di[id];
                int nnodey = nodey + dj[id];
                if (!is_valid(nnodex, nnodey)) continue;
                if (ar[nnodex][nnodey] == 2) continue;
                if (ar[nnodex][nnodey]){
                    if (i && max(cur - 1, 0) < dp[i - 1][nnodex][nnodey]){
                        dp[i - 1][nnodex][nnodey] = max(cur - 1, 0);
                        pq[i - 1].push(mp(max(cur - 1, 0), mp(nnodex, nnodey)));
                    } 
                    if (cur + 1 <= m && cur + 1 < dp[i][nnodex][nnodey]){
                        dp[i][nnodex][nnodey] = cur + 1;
                        pq[i].push(mp(cur + 1, mp(nnodex, nnodey)));
                    }
                } else{
                    if (i && cur < dp[i - 1][nnodex][nnodey]){
                        dp[i - 1][nnodex][nnodey] = cur;
                        pq[i - 1].push(mp(cur, mp(nnodex, nnodey)));
                    } 
                    if (cur + 1 <= m && cur + 1 < dp[i][nnodex][nnodey]){
                        dp[i][nnodex][nnodey] = cur + 1;
                        pq[i].push(mp(cur + 1, mp(nnodex, nnodey)));
                    }
                }
            }
        }
    }
    for (int i=0;i<=s;i++){
        if (dp[i][ak.fi][ak.se] < INF){
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

void solve(){
    cin >> n >> s >> b >> m;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            char c;
            cin >> c;
            if (c == 'S'){
                aw = mp(i, j);
                ar[i][j] = 0;
            } else if (c == 'T'){
                ak = mp(i, j);
                ar[i][j] = 0;
            } else if (c == '*'){
                ar[i][j] = 2;
            } else ar[i][j] = (int)(c - '0');
        }
    }
    dijkstra();
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    for (int i=1;i<=q;i++){
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}
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
const int INF = 1e8;

int q;
int n, m;
char ar[N][N];
vector<pii> person;
int dp[3][N][N];

vector<pii> dd = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

bool is_valid(int r, int c){
    return 1 <= r && r <= n && 1 <= c && c <= m;
}

void printMap(){
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cout << ar[i][j];
        }
        cout << el;
    }
}
void dijkstra(int id){
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            dp[id][i][j] = INF;
        }
    }
    dp[id][person[id].fi][person[id].se] = 0;
    set<pair<int, pii>> setdah;
    setdah.insert(mp(0, person[id]));
    while (!setdah.empty()){
        auto temp = *setdah.begin();
        setdah.erase(temp);
        int cur = temp.fi;
        auto node = temp.se;
        for (auto &del : dd){
            int nr = node.fi + del.fi;
            int nc = node.se + del.se;
            if (!is_valid(nr, nc)) continue;
            if (ar[nr][nc] == '*') continue;
            int plus = 0;
            if (ar[nr][nc] == '#') plus++;
            if (cur + plus < dp[id][nr][nc]){
                setdah.erase(mp(dp[id][nr][nc], mp(nr, nc)));
                dp[id][nr][nc] = cur + plus;
                setdah.insert(mp(dp[id][nr][nc], mp(nr, nc)));
            }
        }
    }
}

void solve(){
    cin >> n >> m;
    person.clear();
    person.pb(mp(1, 1));
    for (int i=1;i<=n + 2;i+=n + 1){
        for (int j=1;j<=m + 2;j++){
            ar[i][j] = '.';
        }
    }
    for (int j=1;j<=n + 2;j++){
        for (int i=1;i<=m + 2;i+=m + 1){
            ar[j][i] = '.';
        }
    }
    for (int i=2;i<=n + 1;i++){
        for (int j=2;j<=m + 1;j++){
            cin >> ar[i][j];
            if (ar[i][j] == '$'){
                person.pb(mp(i, j));
            }
        }
    }
    n += 2;
    m += 2;
    // printMap();
    for (int i=0;i<3;i++){
        dijkstra(i);
    }
    int ans = INF;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (ar[i][j] == '*') continue;
            int cur = dp[0][i][j] + dp[1][i][j] + dp[2][i][j];
            if (ar[i][j] == '#') cur -= 2;
            ans = min(ans, cur);
        }
    }
    cout << ans << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        solve();
    }

    return 0;
}
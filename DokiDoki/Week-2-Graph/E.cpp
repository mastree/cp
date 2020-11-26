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

int n, m, s, t;
vector<int> adj[N];
bool ada[N][N];

int sdist[N], tdist[N];

void init_sdist(){
    queue<pii> qu;
    fill(sdist, sdist + n + 2, INF);
    qu.push(mp(0, s));
    sdist[s] = 0;
    while (!qu.empty()){
        auto tp = qu.front();
        int cur = tp.fi;
        int node = tp.se;
        qu.pop();
        for (auto x : adj[node]){
            if (sdist[x] == INF){
                qu.push(mp(cur + 1, x));
                sdist[x] = cur + 1;
            }
        }
    }
}
void init_tdist(){
    queue<pii> qu;
    fill(tdist, tdist + n + 2, INF);
    qu.push(mp(0, t));
    tdist[t] = 0;
    while (!qu.empty()){
        auto tp = qu.front();
        int cur = tp.fi;
        int node = tp.se;
        qu.pop();
        for (auto x : adj[node]){
            if (tdist[x] == INF){
                qu.push(mp(cur + 1, x));
                tdist[x] = cur + 1;
            }
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> s >> t;
    for (int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
        ada[a][b] = 1;
        ada[b][a] = 1;
    }
    init_sdist();
    init_tdist();
    int cnt = 0;
    for (int i=1;i<=n;i++){
        for (int j=i + 1;j<=n;j++){
            if (ada[i][j] || i == j) continue;
            if (sdist[t] <= sdist[i] + tdist[j] + 1 && sdist[t] <= sdist[j] + tdist[i] + 1) cnt++;
        }
    }
    cout << cnt << el;

    return 0;
}
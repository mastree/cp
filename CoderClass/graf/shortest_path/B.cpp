#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;

const int N = 410;
const int INF = 1e9;

int n, m, q;
int dp[N][N];
int par[N][N];

vector<pii> adj[N];

void dijkstra(int s){
    fill(dp[s], dp[s] + n + 2, INF);
    dp[s][s] = 0;
    par[s][s] = s;
    set<pii> setdah;
    setdah.insert(mp(dp[s][s], s));
    while (!setdah.empty()){
        auto tp = *setdah.begin();
        setdah.erase(tp);
        int node = tp.se;
        int cur = tp.fi;
        for (auto x : adj[node]){
            if (dp[s][x.fi] > cur + x.se){
                par[s][x.fi] = node;
                setdah.erase(mp(dp[s][x.fi], x.fi));
                dp[s][x.fi] = cur + x.se;
                setdah.insert(mp(dp[s][x.fi], x.fi));
            }
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> q;
    for (int i=1;i<=m;i++){
        int a, b;
        int w;
        cin >> a >> b >> w;
        adj[a].pb(mp(b, w));
        adj[b].pb(mp(a, w));
    }
    for (int i=1;i<=n;i++){
        dijkstra(i);
    }
    while (q--){
        int a, b;
        cin >> a >> b;
        vector<int> path;
        while (b != a){
            path.pb(b);
            b = par[a][b];
        }
        path.pb(a);
        reverse(path.begin(), path.end());
        int len = path.size();
        for (int i=0;i<len;i++){
            cout << path[i];
            if (i != len - 1) cout << " ";
        }
        cout << el;
    }

    return 0;
}
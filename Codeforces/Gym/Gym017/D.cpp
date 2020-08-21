#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e5 + 10;
const int INF = 1e9;

int n, m;
vector<pii> adj[N];
int dp[N];

void dijk(){
    fill(dp, dp + n + 2, INF);
    dp[1] = 0;
    set<pii> setdah;
    setdah.insert(mp(0, 1));
    while (!setdah.empty()){
        auto tp = *setdah.begin();
        setdah.erase(tp);
        int node = tp.se;
        int cur = tp.fi;
        for (auto x : adj[node]){
            if (dp[x.fi] > dp[node] + 1){
                setdah.erase(mp(dp[x.fi], x.fi));
                dp[x.fi] = dp[node] + 1;
                setdah.insert(mp(dp[x.fi], x.fi));
            }
        }
    }
}
vector<pair<int, pii>> urut[N]; // urut[jarak ke n] <nilai, node, next node>
int nxt[N];
vector<int> path;
string ans;
void solve(){
    urut[0].pb(mp(0, mp(n, n + 1)));
    for (int i=0;i<=dp[n];i++){
        int mn = -1;

        vector<pair<pii, pii>> vec;
        for (auto x : urut[i]){
            int node = x.se.fi;
            int nx = x.se.se;
            nxt[node] = nx;
            for (auto y : adj[node]){
                if (dp[node] - dp[y.fi] == 1){
                    vec.pb(mp(mp(y.se, x.fi), mp(y.fi, node)));
                }
            }
        }
        sort(vec.begin(), vec.end());
        unordered_map<int, bool> vis;
        pii bef = mp(-1, -1);
        int tempid = 0;
        for (auto x : vec){
            if (vis[x.se.fi]) continue;
            vis[x.se.fi] = 1;
            if (x.fi != bef){
                tempid++;
                bef = x.fi;
            }
            urut[i + 1].pb(mp(tempid, x.se));
        }
    }
    int cur = 1;
    while (cur != n + 1){
        path.pb(cur);
        cur = nxt[cur];
    }
    for (int i=0;i<dp[n];i++){
        int a = path[i];
        int b = path[i + 1];
        for (auto x : adj[a]){
            if (x.fi == b){
                ans.pb(char(x.se + 'a'));
                break;
            }
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=m;i++){
        int a, b, c;
        char cc;
        cin >> a >> b >> cc;
        c = cc - 'a';
        adj[a].pb(mp(b, c));
        adj[b].pb(mp(a, c));
    }
    dijk();
    cout << dp[n] << el;

    solve();
    for (auto x : path){
        cout << x << " ";
    }
    cout << el;
    cout << ans << el;

    return 0;
}
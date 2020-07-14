#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
// #define MOD 1000000007
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'

using namespace std;

const int N = 2e5 + 10;
const ll INF = 1e18;

int q;
int n, m;
ll p[N], pc[N];
vector <int> adl[N];
int a, b, c;
ll dist[4][N];

void bfs(){
    queue <pair<int, ll>> qu;
    fill(dist[1], dist[1] + n + 2, -1);
    qu.push(mp(a, 0));

    while (!qu.empty()){
        auto temp = qu.front();
        qu.pop();
        if (dist[1][temp.fi] != -1) continue;
        dist[1][temp.fi] = temp.se;
        for (auto x : adl[temp.fi]){
            qu.push(mp(x, temp.se + 1));
        }
    }
    fill(dist[2], dist[2] + n + 2, -1);
    qu.push(mp(b, 0));

    while (!qu.empty()){
        auto temp = qu.front();
        qu.pop();
        if (dist[2][temp.fi] != -1) continue;
        dist[2][temp.fi] = temp.se;
        for (auto x : adl[temp.fi]){
            qu.push(mp(x, temp.se + 1));
        }
    }
    fill(dist[3], dist[3] + n + 2, -1);
    qu.push(mp(c, 0));

    while (!qu.empty()){
        auto temp = qu.front();
        qu.pop();
        if (dist[3][temp.fi] != -1) continue;
        dist[3][temp.fi] = temp.se;
        for (auto x : adl[temp.fi]){
            qu.push(mp(x, temp.se + 1));
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n >> m >> a >> b >> c;
        for (int i=1;i<=n;i++) adl[i].clear();
        for (int i=1;i<=m;i++){
            cin >> p[i];
        }
        sort(p + 1, p + 1 + m);
        for (int i=1;i<=m;i++){
            pc[i] = pc[i - 1] + p[i];
        }
        for (int i=1;i<=m;i++){ 
            int u, v;
            cin >> u >> v;
            
            adl[u].pb(v);
            adl[v].pb(u);
        }
        bfs();
        ll ans = INF;
        for (int i=1;i<=n;i++){
            ll temp = dist[1][i] + dist[2][i] + dist[3][i];
            if (temp > (ll)m){
                continue;
            }
            ans = min(ans, pc[dist[2][i]] + pc[temp]);
        }
        cout << ans << el;
    }

    return 0;
}
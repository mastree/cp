#pragma gcc optimize ("O2")
#pragma gcc optimize ("unroll-loops")

#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using piii = pair<int, pii>;

struct Query{
    int a, b, id;
    bool t;
    Query() {}
    Query(int a, int b, int id, bool c) : a(a), b(b), id(id), t(c) {}
};

piii mp3(const int& a, const int& b, const int& c){
    return mp(a, mp(b, c));
}

const int N = 4e2 + 10, Q = 1e5 + 10;
const int INF = 1e9 + 10;

int n, m;
pii tempar[N];
int ar[N];
int getid[N];
vector<pii> adj[N];

vector<Query> v[N];
int ans[Q];
void solve0(){
    int dist[n + 2][n + 2];
    for (int i=0;i<n + 2;i++){
        fill(dist[i], dist[i] + n + 2, INF);
        dist[i][i] = 0;
    }
    for (int i=1;i<=n;i++){
        for (auto x : adj[i]){
            dist[i][x.fi] = x.se;
        }
    }

    for (int k=1;k<=n;k++){
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
        for (auto x : v[k]){
            if (x.t) continue;
            int a = x.a, b = x.b;
            ans[x.id] = -1;
        
            if (dist[a][b] < INF) ans[x.id] = dist[a][b];
        }
    }
}
void solve1(){
    int dist[n + 2][n + 2];
    for (int i=0;i<n + 2;i++){
        fill(dist[i], dist[i] + n + 2, INF);
        dist[i][i] = 0;
    }
    for (int i=1;i<=n;i++){
        for (auto x : adj[i]){
            dist[i][x.fi] = x.se;
        }
    }

    for (int k=n;k>=1;k--){
        for (int i=n;i>=1;i--){
            for (int j=n;j>=1;j--){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
        for (auto x : v[k]){
            if (!x.t) continue;
            int a = x.a, b = x.b;
            ans[x.id] = -1;
        
            if (dist[a][b] < INF) ans[x.id] = dist[a][b];
        }
    }
}
int urut[N];
int urut1[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=n;i++){
        cin >> tempar[i].fi;
        tempar[i].se = i;
    }
    sort(tempar + 1, tempar + n + 1);
    for (int i=1;i<=n;i++){
        ar[i] = tempar[i].fi;
        getid[tempar[i].se] = i;
    }
    ar[0] = -INF;
    ar[n + 1] = INF;
    for (int i=1;i<=n;i++){
        if (ar[i] != ar[i - 1]) urut[i] = urut[i - 1] + 1;
        else urut[i] = urut[i - 1];
    }
    for (int i=n;i>=1;i--){
        if (ar[i] != ar[i + 1]) urut1[n - i + 1] = urut1[n - i] + 1;
        else urut1[n - i + 1] = urut1[n - i];
    }

    for (int i=1;i<=m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        a = getid[a];
        b = getid[b];
        adj[a].pb(mp(b, c));
        adj[b].pb(mp(a, c));
    }
    int q;
    cin >> q;
    for (int i=1;i<=q;i++){
        int a, b, k;
        bool c;
        cin >> a >> b >> k >> c;
        a = getid[a];
        b = getid[b];
        if (c){
            int l = 1, r = n;
            while (l < r){
                int m = (l + r + 1) / 2;
                if (urut1[m] <= k) l = m;
                else r = m - 1;
            }
            k = n - l + 1;
        } else{
            int l = 1, r = n;
            while (l < r){
                int m = (l + r + 1) / 2;
                if (urut[m] <= k) l = m;
                else r = m - 1;
            }
            k = l;
        }
        v[k].emplace_back(a, b, i, c);
    }
    solve0();
    solve1();
    for (int i=1;i<=q;i++){
        cout << ans[i] << el;
    }

    return 0;
}
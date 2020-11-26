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

const int N = 1e5 + 10;
const int INF = 2e9 + 10;
const int MOD = 1e9 + 7;

struct Query{
    int s, t, k;
    int id;
    Query(){}
};

int n, nq, sq, m;
vector<pii> pt;
int a[3], b[3], c[3];

Query q[N];

map<pii, int> titik;
vector<vector<pii>> adj;

int manhat(pii a, pii b){
    return abs(a.fi - b.fi) + abs(a.se - b.se);
}

void solve1(){
    adj.resize(n + 1);
    for (int i=1;i<=n;i++){
        for (int j=i + 1;j<=n;j++){
            int dist = manhat(pt[i - 1], pt[j - 1]) - 1;
            adj[i].emplace_back(j, dist);
            adj[j].emplace_back(i, dist);
        }
    }
    int dp[n + 2][n + 2];
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if (i != j) dp[i][j] = INF;
            else dp[i][j] = 0;
        }
    }
    set<pii> setdah;
    for (int sc=1;sc<=n;sc++){
        setdah.insert(mp(dp[sc][sc], sc));
        while (!setdah.empty()){
            auto tp = *setdah.begin();
            setdah.erase(tp);

            int node = tp.se;
            int cur = tp.fi;
            for (auto x : adj[node]){
                int nx = max(cur, x.se);
                if (dp[sc][x.fi] > nx){
                    setdah.erase(mp(dp[sc][x.fi], x.fi));
                    dp[sc][x.fi] = nx;
                    setdah.insert(mp(dp[sc][x.fi], x.fi));
                }
            }
        }
    }
    int ans = 0;
    int cur = 2;
    for (int i=1;i<=nq;i++){
        if (dp[q[i].s][q[i].t] <= q[i].k){
            ans = (ans + cur) % MOD;
        }
        cur = 2LL * cur % MOD;
    }
    cout << ans << el;
}

int par[N], sz[N], cc[5][N];

int find(int node){
    if (par[node] == node) return node;
    return par[node] = find(par[node]);
}
void make(int a, int b){
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    par[b] = a;
}

bool comp(Query a, Query b){
    return a.k < b.k;
}

void solve2(){
    for (int i=1;i<=n;i++){
        par[i] = i;
        sz[i] = 1;
    }
    sort(q + 1, q + 1 + nq, comp);
    int id = 1;
    bool ans[nq + 1];
    fill(ans, ans + nq + 1, 0);

    for (int jar=1;jar<=5;jar++){
        for (int i=1;i<=n;i++){
            pii pos = pt[i - 1];

            for (int dx=-jar;dx<=jar;dx++){
                int dy = jar - abs(dx);
                // cout << dx << " " << dy << el;

                pii nx = mp(pos.fi + dx, pos.se + dy);
                if (titik.count(nx)){
                    make(i, titik[nx]);
                }
                
                nx = mp(pos.fi + dx, pos.se - dy);
                if (titik.count(nx)){
                    make(i, titik[nx]);
                }
            }
        }
        while (id <= nq && q[id].k == jar - 1){
            ans[q[id].id] = (par[q[id].s] == par[q[id].t]);
            id++;
        }
        if (id > nq) break;
    }
    int tot = 0;
    int cur = 2;
    for (int i=1;i<=nq;i++){
        if (ans[i]) tot = (tot + cur) % MOD;
        cur = 2LL * cur % MOD;
    }
    cout << tot << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> nq >> sq >> m;
    for (int i=1;i<=n;i++){
        int a, b;
        cin >> a >> b;
        pt.emplace_back(a, b);
        // titik.insert({{a, b}, i});
        titik[mp(a, b)] = i;
    }
    for (int i=0;i<3;i++){
        cin >> a[i] >> b[i] >> c[i];
    }
    for (int i=1;i<=sq;i++){
        cin >> q[i].s >> q[i].t >> q[i].k;
        q[i].id = i;
    }
    for (int i=sq + 1;i<=nq;i++){
        q[i].s = (1LL * a[0] * q[i - 1].s + 1LL * b[0] * q[i - 2].s + c[0]) % n + 1;
        q[i].t = (1LL * a[1] * q[i - 1].t + 1LL * b[1] * q[i - 2].t + c[1]) % n + 1;
        q[i].k = (1LL * a[2] * q[i - 1].k + 1LL * b[2] * q[i - 2].k + c[2]) % m;
        q[i].id = i;
    }
    solve2();
    // if (n <= 500 && nq <= 500) solve1();
    // else solve2();

    return 0;
}
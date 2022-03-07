#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using ld = long double;

/** START OF DESPERATE OPTIMIZATION **/
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

template<typename T> void in(T & x) {
    x = 0;
    register T c = getchar();
    while (((c < 48) || (c > 57)) && (c != '-')) c = getchar();
    bool neg = false;
    if (c == '-') neg = true;
    for (; c < 48 || c > 57; c = getchar());
    for (; c > 47 && c < 58; c = getchar()) x = (x << 3) + (x << 1) + (c & 15);
    if (neg) x = -x;
}

template<typename T> void out(T n, char CC) {
    if (n < 0) {
        putchar('-');
        n *= -1;
    }
    char snum[65];
    int i = 0;
    do {
        snum[i++] = n % 10 + '0';
        n /= 10;
    } while (n);
    i = i - 1;
    while (i >= 0) putchar(snum[i--]);
    putchar(CC);
}
/** END OF DESPERATE OPTIMIZATION **/

const int N = 1e5 + 10;
const int INF = 1e9 + 10;
const int MW = 1e4;

int n, m, s, e;
vector<pii> adj[N];
vector<int> nadj[N];
int deg[N];
int dist[2][N];
double dp[N];

void dijkstra(int sc, int tp) {
    for (int u = 1; u <= n; u++) {
        dist[tp][u] = INF;
    }
    priority_queue<pii, vector<pii>, greater<pii>> pq; // dist, node
    dist[tp][sc] = 0;
    pq.push(mp(0, sc));
    while (!pq.empty()){
        int cur = pq.top().fi;
        int node = pq.top().se;
        pq.pop();
        if (cur > dist[tp][node]) continue;
        for (auto& x : adj[node]){
            if (cur + x.se < dist[tp][x.fi]){
                dist[tp][x.fi] = cur + x.se;
                pq.push(mp(dist[tp][x.fi], x.fi));
            }
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    in(n), in(m), in(s), in(e);
    for (int i=1;i<=m;i++){
        int u, v, w;
        in(u), in(v), in(w);
        assert(w <= MW);
        adj[u].pb(mp(v, w));
        adj[v].pb(mp(u, w));
    }
    dijkstra(s, 0);
    dijkstra(e, 1);
    for (int i=1;i<=n;i++){
        for (auto& x : adj[i]){
            if (dist[0][e] == dist[0][i] + x.se + dist[1][x.fi]){
                nadj[i].pb(x.fi);
                deg[x.fi]++;
            }
        }
    }
    dp[s] = 2.0;
    queue<int> q;
    q.push(s);
    while (!q.empty()){
        int node = q.front();
        q.pop();
        double ns = dp[node] / nadj[node].size();
        for (auto& x : nadj[node]){
            dp[x] += ns;
            if (--deg[x] == 0){
                q.push(x);
            }
        }
    }
    for (int i=1;i<=n;i++){
        printf("%.9lf\n", dp[i]);
    }

    return 0;
}
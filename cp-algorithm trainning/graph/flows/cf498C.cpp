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

const int N = 150, MAXN = 4e3;
const int INF = 1e9 + 1;

int n, m;
int ar[N];

unordered_map<int, pii> cek[N]; // factor, cnt, id
vector<int> adl[MAXN];
int cap[MAXN][MAXN];

int bfs(int s, int t, vector<int>& parent){
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pii> qu;
    qu.push(mp(s, INF));
    while (!qu.empty()){
        int cur = qu.front().fi;
        int flow = qu.front().se;
        qu.pop();

        for (auto x : adl[cur]){
            if (parent[x] == -1 && cap[cur][x]){
                parent[x] = cur;
                int nflow = min(flow, cap[cur][x]);
                if (x == t){
                    return nflow;
                }
                qu.push(mp(x, nflow));
            }
        }
    }
    return 0;
}

int maxflow(int s, int t){
    int flow = 0;
    vector<int> parent(n);
    int nflow;

    while (nflow = bfs(s, t, parent)){
        flow += nflow;
        int cur = t;
        while (cur != s){
            int ncur = parent[cur];
            cap[ncur][cur] -= nflow;
            cap[cur][ncur] += nflow;
            cur = ncur;
        }
    }
    return flow;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    int s = 1, t, tempid = 1;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        int temp = ar[i];
        for (int j=2;j * j<=temp;j++){
            if (temp % j == 0){
                int res = 0;
                while (temp % j == 0){
                    temp /= j;
                    res++;
                }
                cek[i][j] = mp(res, ++tempid);
            }
        }
        if (temp != 1){
            cek[i][temp] = mp(1, ++tempid); 
        }
    }
    t = tempid + 1;
    for (int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        if (a & 1 ^ 1) swap(a, b);
        for (auto xx : cek[a]){
            auto y = cek[b][xx.fi];
            if (y == mp(0, 0)) continue;
            auto x = xx.se;

            // s to odd
            if (adl[x.se].empty()){
                adl[s].pb(x.se);
                adl[x.se].pb(s);
                cap[s][x.se] = x.fi;
                cap[x.se][s] = 0;
            }

            // even to t
            if (adl[y.se].empty()){
                adl[y.se].pb(t);
                adl[t].pb(y.se);
                cap[y.se][t] = y.fi;
                cap[t][y.se] = 0;
            }

            // odd to even
            adl[x.se].pb(y.se);
            adl[y.se].pb(x.se);
            cap[x.se][y.se] = INF;
            cap[y.se][x.se] = 0;
        }
    }
    n = t + 1;
    int ans = maxflow(s, t);
    cout << ans << el;

    return 0;
}
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

const int N = 3e2 + 10;
const int INF = 1e9 + 10;

int n, m;
int ar[N], br[N];
vector<int> adl[N];
int cap[N][N];

void addEdge(int u, int v, int mx){
    adl[u].pb(v);
    adl[v].pb(u);
    cap[u][v] = mx;
}

int dfs(int s, int t, vector<int>& parent){
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
                int nflow = min(flow, cap[cur][x]);
                parent[x] = cur;
                if (x == t) return nflow;
                qu.push(mp(x, nflow));
            }
        }
    }
    return 0;
}

int maxflow(int s, int t){
    vector<int> parent(N);
    int ret = 0;
    int nflow = 0;
    while (nflow = dfs(s, t, parent)){
        ret += nflow;
        int cur = t;
        while (cur != s){
            int ncur = parent[cur];
            cap[ncur][cur] -= nflow;
            cap[cur][ncur] += nflow;
            cur = ncur;
        }
    }
    return ret;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    int tot1 = 0, tot2 = 0;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        tot1 += ar[i];
    }
    for (int i=1;i<=n;i++){
        cin >> br[i];
        tot2 += br[i];
    }
    if (tot1 != tot2){
        cout << "NO" << el;
        return 0;
    }
    int s = 1, t = n + n + 2;
    for (int i=1;i<=n;i++){
        addEdge(s, i + 1, ar[i]);
        addEdge(i + 1, n + i + 1, INF);
        addEdge(n + i + 1, t, br[i]);
    }
    for (int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        addEdge(a + 1, n + b + 1, INF);
        addEdge(b + 1, n + a + 1, INF);
    }
    int flow = maxflow(s, t);
    if (flow != tot1){
        cout << "NO" << el;
        return 0;
    }
    cout << "YES" << el;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if (cap[i + 1][n + j + 1] == 0) cout << 0 << " ";
            else cout << max(INF - cap[i + 1][n + j + 1], 0) << " ";
        }
        cout << el;
    }

    return 0;
}
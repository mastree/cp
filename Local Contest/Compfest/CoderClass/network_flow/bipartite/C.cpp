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

int n, m;
bool ar[N][N];

int di[] = {0, 0, -1, 1};
int dj[] = {-1, 1, 0, 0};

int getid(int a, int b){
    return (a - 1) * m + b; 
}

vector<int> adj[N * N];

bool vis[N * N];
int assign[N * N];

bool match(int v){
    if (vis[v]) return false;
    vis[v] = 1;
    for (auto& u : adj[v]){
        if (assign[u] == 0 || match(assign[u])){
            assign[u] = v;
            return true;
        }
    }
    return false;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    int ans = 0;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            char c;
            cin >> c;
            ans += ar[i][j] = (c == '*');
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if ((i + j) & 1) continue;
            int id1 = getid(i, j);
            if (ar[i][j]){
                for (int id=0;id<4;id++){
                    int ni = i + di[id];
                    int nj = j + dj[id];
                    if (1 <= ni && ni <= n && 1 <= nj && nj <= m && ar[ni][nj]){
                        int id2 = getid(ni, nj);
                        adj[id1].pb(id2);
                    }
                }
            }
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if ((i + j) & 1) continue;
            fill(vis, vis + n * m + 10, 0);
            if (match(getid(i, j))) ans--;
        }
    }
    cout << ans << el;

    return 0;
}
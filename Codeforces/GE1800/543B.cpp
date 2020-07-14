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

const int N = 3e3 + 10;

int n, m;
vector<int> adl[N];
int s[2], t[2], l[2];

int dist[N][N];

void bfs_dist(){
    bool vis[n + 2];
    queue<pii> qu;
    for (int i=1;i<=n;i++){
        fill(vis, vis + n + 2, 0);
        qu.push(mp(i, 0));
        while (!qu.empty()){
            pii temp = qu.front();
            qu.pop();
            if (vis[temp.fi]) continue;
            vis[temp.fi] = 1;
            dist[i][temp.fi] = temp.se;
            for (auto x : adl[temp.fi]){
                if (!vis[x]) qu.push(mp(x, temp.se + 1));
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
        int a, b;
        cin >> a >> b;
        adl[a].pb(b);
        adl[b].pb(a);
    }
    for (int i=0;i<2;i++){
        cin >> s[i] >> t[i] >> l[i];
    }
    bfs_dist();
    if (dist[s[0]][t[0]] > l[0] || dist[s[1]][t[1]] > l[1]){
        cout << -1 << el;
        return 0;
    }
    int banyak = min(m, dist[s[0]][t[0]] + dist[s[1]][t[1]]);

    for (int i=1;i<=n;i++){
        for (int j=i;j<=n;j++){
            int cur0 = min(dist[s[0]][i]+ dist[t[0]][j], dist[s[0]][j]+ dist[t[0]][i]);
            int cur1 = min(dist[s[1]][i]+ dist[t[1]][j], dist[s[1]][j]+ dist[t[1]][i]);
            if (cur0 + dist[i][j] <= l[0] && cur1 + dist[i][j] <= l[1])
                banyak = min(banyak, cur0 + cur1 + dist[i][j]);
        }
    }
    cout << m - banyak << el;

    return 0;
}
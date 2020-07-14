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

const int N = 60;

int q;
string s[N];
bool vis[N][N];
int n, m;

int di[4] = {-1, 1, 0, 0};
int dj[4] = {0, 0, -1, 1};

void dfs(int r, int c){
    if (vis[r][c]) return;
    vis[r][c] = 1;
    for (int i=0;i<4;i++){
        int nr = r + di[i];
        int nc = c + dj[i];
        if (1 <= nr && nr <= n && 1 <= nc && nc <= m){
            if (s[nr][nc] != '#'){
                dfs(nr, nc);
            }
        } else continue;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n >> m;
        for (int i=1;i<=n;i++){
            fill(vis[i], vis[i] + m + 2, 0);
            string temp;
            cin >> temp;
            s[i] = "*" + temp + "*";
        }
        int gud = 0, bad = 0;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                if (s[i][j] == 'G'){
                    gud++;
                } else if (s[i][j] == 'B'){
                    bad++;
                    for (int k=0;k<4;k++){
                        int ni = i + di[k];
                        int nj = j + dj[k];
                        if (1 <= ni && ni <= n && 1 <= nj && nj <= m){
                            if (s[ni][nj] != 'G' && s[ni][nj] != 'B'){
                                s[ni][nj] = '#';
                            }
                        }
                    }
                }
            }
        }
        if (s[n][m] == '#'){
            if (gud){
                cout << "NO" << el;
            } else{
                cout << "YES" << el;
            }
            continue;
        }
        dfs(n, m);
        bool ok = 1;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                if (s[i][j] == 'G'){
                    if (!vis[i][j]) ok = 0;
                } else if (s[i][j] == 'B'){
                    if (vis[i][j]) ok = 0;
                }
            }
        }
        if (ok){
            cout << "YES" << el;
        } else{
            cout << "NO" << el;
        }
    }

    return 0;
}
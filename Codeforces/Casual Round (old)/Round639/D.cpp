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

const int N = 1e3 + 10;

int n, m;
string s[N];

bool kosongR, kosongC;

int ans = 0;
bool vis[N][N];

void dfs(int r, int c){
    if (r == 0 || c == 0 || r == n+1 || c == m+1){
        return;
    }
    if (vis[r][c] || s[r][c] == '.') return;
    vis[r][c] = 1;
    dfs(r + 1, c);
    dfs(r - 1, c);
    dfs(r, c + 1);
    dfs(r, c - 1);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=n;i++){
        cin >> s[i];
        s[i] = '*' + s[i] + '*';
    }

    bool bisa = 1;
    for (int i=1;i<=n;i++){
        int cnt = 0;
        char bef = '.';
        for (int j=1;j<=m;j++){
            if (bef != s[i][j]){
                if (bef == '#') cnt++;
                bef = s[i][j];
            }
        }
        if (bef == '#') cnt++;
        if (cnt > 1) bisa = 0;
        else if (cnt == 0) kosongR = 1;
    }
    for (int j=1;j<=m;j++){
        int cnt = 0;
        char bef = '.';
        for (int i=1;i<=n;i++){
            if (bef != s[i][j]){
                if (bef == '#') cnt++;
                bef = s[i][j];
            }
        }
        if (bef == '#') cnt++;
        if (cnt > 1) bisa = 0;
        else if (cnt == 0) kosongC = 1;
    }
    if (kosongR && !kosongC) bisa = 0;
    if (kosongC && !kosongR) bisa = 0;
    if (!bisa){
        cout << -1 << el;
        return 0;
    }

    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (!vis[i][j] && s[i][j] == '#'){
                dfs(i, j);
                ans++;
            }
        }
    }
    cout << ans << el;

    return 0;
}
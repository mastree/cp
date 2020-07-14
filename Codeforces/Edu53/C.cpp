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

const int N = 2e5 + 10;
const int INF = 1e9;

int n;
string s;
int x, y;
int curx, cury;
int cnt[4]; // U, D, R, L
int pc[N][4];

bool bisa(int l, int r){
    int le[4] = {0, 0, 0, 0};
    int ri[4] = {0, 0, 0, 0};
    for (int i=0;i<4;i++){
        le[i] = pc[l - 1][i];
        ri[i] = pc[n][i] - pc[r][i];
    }
    int ru = le[0] + ri[0] - le[1] - ri[1];
    int rr = le[2] + ri[2] - le[3] - ri[3];
    int mn = abs(y - ru) + abs(x - rr);
    return (r - l + 1 - mn) >= 0;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;
    cin >> x >> y;
    int mnstep = abs(x) + abs(y);
    if (mnstep > n || (mnstep & 1) != (n & 1)){
        cout << -1 << el;
        return 0;
    }

    s = "X" + s;
    for (int i=1;i<=n;i++){
        for (int j=0;j<4;j++) pc[i][j] = pc[i - 1][j];
        if (s[i] == 'U'){
            pc[i][0]++;
            cnt[0]++;
            cury++;
        } else if (s[i] == 'D'){
            pc[i][1]++;
            cnt[1]++;
            cury--;
        } else if (s[i] == 'R'){
            pc[i][2]++;
            cnt[2]++;
            curx++;
        } else{
            pc[i][3]++;
            cnt[3]++;
            curx--;
        }
    }
    if (curx == x && cury == y){
        cout << 0 << el;
        return 0;
    }
    int ans = INF;
    int l = 1, r = 1;
    for (;l<=n;l++){
        r = max(l, r);
        while (r < n && !bisa(l, r)) r++;
        if (bisa(l, r)) ans = min(ans, r - l + 1);
    }
    if (ans == INF){
        cout << -1 << el;
        return 0;
    }
    cout << ans << el;

    return 0;
}
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

const int N = 100;

int n, k;
vector<vector<int>> ar(6, vector<int>(N, 0));
vector<pair<int, pii>> ans;
pii slot = mp(0, 0);

void goleft(){
    if (slot.se == 1) return;
    int r = slot.fi, c = slot.se;
    if (ar[r][c - 1]) ans.pb(mp(ar[r][c - 1], slot));
    swap(ar[r][c - 1], ar[r][c]);
    slot.se--;
}
void goright(){
    if (slot.se == n) return;
    int r = slot.fi, c = slot.se;
    if (ar[r][c + 1]) ans.pb(mp(ar[r][c + 1], slot));
    swap(ar[r][c + 1], ar[r][c]);
    slot.se++;
}
void goup(){
    if (slot.fi == 2) return;
    int r = slot.fi, c = slot.se;
    if (ar[r - 1][c]) ans.pb(mp(ar[r - 1][c], slot));
    swap(ar[r - 1][c], ar[r][c]);
    slot.fi--;
}
void godown(){
    if (slot.fi == 3) return;
    int r = slot.fi, c = slot.se;
    if (ar[r + 1][c]) ans.pb(mp(ar[r + 1][c], slot));
    swap(ar[r + 1][c], ar[r][c]);
    slot.fi++;
}
void move(){
    if (slot.fi == 2){
        if (slot.se > 1) goleft();
        else godown();
    } else{
        if (slot.se < n) goright();
        else goup();
    }
}
void handlespecial(){
    bool bisa = 0;
    for (int i=2;i<=3;i++){
        for (int j=1;j<=n;j++){
            if (ar[i][j] == 0) continue;
            if (i == 2 && ar[1][j] == ar[2][j]){
                k--;
                ans.pb(mp(ar[2][j], mp(1, j)));
                ar[2][j] = 0;
                bisa = 1;
            }
            if (i == 3 && ar[4][j] == ar[3][j]){
                k--;
                ans.pb(mp(ar[3][j], mp(4, j)));
                ar[3][j] = 0;
                bisa = 1;
            }
        }
    }
    if (!bisa){
        cout << -1 << el;
        exit(0);
    }
}
void solve(){
    for (int i=1;i<=2 * n && k;i++){
        for (int j=1;j<=n;j++){
            if (ar[2][j] && ar[1][j] == ar[2][j]){
                k--;
                ans.pb(mp(ar[2][j], mp(1, j)));
                ar[2][j] = 0;
            }
            if (ar[3][j] && ar[4][j] == ar[3][j]){
                k--;
                ans.pb(mp(ar[3][j], mp(4, j)));
                ar[3][j] = 0;
            }
        }
        for (int i=1;i<n * 2;i++) move();
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i=1;i<=4;i++){
        for (int j=1;j<=n;j++){
            cin >> ar[i][j];
        }
    }
    if (k == 2 * n){
        handlespecial();
    }
    for (int i=2;i<=3;i++){
        for (int j=1;j<=n;j++){
            if (ar[i][j] == 0){
                slot = mp(i, j);
                break;
            }
        }
        if (slot != mp(0, 0)) break;
    }
    solve();
    if (k || ans.size() > 20000){
        cout << -1 << el;
        return 0;
    }
    cout << ans.size() << el;
    for (auto x : ans){
        cout << x.fi << " " << x.se.fi << " " << x.se.se << el;
    }

    return 0;
}
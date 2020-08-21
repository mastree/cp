#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e3 + 10;

int n;
int ar[N], br[N];

bool udha[N], udhb[N];
int memo[N][N];
pii rangea[N], rangeb[N]; 

void init(){
    for (int i=1;i<=n;i++){
        rangea[i] = mp(1, n);
        rangeb[i] = mp(1, n);
        for (int j=1;j<=n;j++){
            memo[i][j] = -2;
        }
    }
}

int turn;
int ask(int i, int j){
    if (memo[i][j] != -2) return memo[i][j];
    if (rangea[i].se < rangeb[j].fi){
        rangea[i].se--;
        rangeb[j].fi++;
        memo[i][j] = -1;
        return memo[i][j];
    } else if (rangea[i].fi > rangeb[j].se){
        rangea[i].fi++;
        rangeb[j].se--;
        memo[i][j] = 1;
        return memo[i][j];
    }
    turn--;
    cout << "? " << i << " " << j << endl;
    char res;
    cin >> res;
    if (res == '>'){
        rangea[i].fi++;
        rangeb[j].se--;
        rangea[i].fi = max(rangea[i].fi, rangeb[j].fi + 1);
        rangeb[j].se = min(rangea[i].se - 1, rangeb[j].se);
        memo[i][j] = 1;
        return memo[i][j];
    } else if (res == '<'){
        rangea[i].se--;
        rangeb[j].fi++;
        rangea[i].se = min(rangea[i].se, rangeb[j].se - 1);
        rangeb[j].fi = max(rangea[i].fi + 1, rangeb[j].fi);
        memo[i][j] = -1;
        return memo[i][j];
    }
    ar[i] = j;
    br[j] = i;
    int mn = min(rangea[i].se, rangeb[j].se);
    int mx = max(rangea[i].fi, rangeb[j].fi);
    rangea[i] = mp(mx, mn);
    rangeb[j] = mp(mx, mn);
    memo[i][j] = 0;
    return memo[i][j];
}
int cari(int a){
    if (ar[a] == 0){
        for (int i=1;i<=n;i++){
            if (br[i] == 0 && min(rangea[a].se, rangeb[i].se) >= max(rangea[a].fi, rangeb[i].fi) && (memo[a][i] == -2 || memo[a][i] == 0)){
                ar[a] = i;
                br[i] = a;
                break;
            }
        }
    }
    return ar[a];
}
void solve(){
    turn = 5 * n * ((int)log2(n));
    int last = 0, i = 0;
    while (turn && last < n){
        if (i >= n){
            i -= n;
            last++;
        }
        int ni = (i + last) % n;
        ask(i + 1, ni + 1);

        i++;
    }
    cout << "! ";
    for (int i=1;i<=n;i++){
        cout << cari(i) << " ";
    }
    cout << endl;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    init();
    solve();

    return 0;
}
#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e3 + 10;
const ll INF = 1e18 + 10;

int n, m;
int ar[N][N];

ll ans[N][N];
pii near[N][N];

void init_near(){
    for (int i=0;i<=n + 1;i++){
        for (int j=0;j<=m + 1;j++){
            near[i][j] = mp(-N, -N);
        }
    }
}
ll edist(const pii& a, const pii& b){
    ll delx = abs(a.fi - b.fi);
    ll dely = abs(a.se - b.se);
    return delx * delx + dely * dely;
}
pii fnear(const pii& a, const pii& b, const pii& c){
    if (edist(a, c) < edist(b, c)) return a;
    return b;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    n++;
    m++;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            char c;
            cin >> c;
            ar[i][j] = c == '1';
            ans[i][j] = INF;
        }
    }
    
    // kiri atas
    init_near();
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (ar[i][j]) near[i][j] = mp(i, j);
            else{
                near[i][j] = fnear(near[i - 1][j], near[i][j - 1], mp(i, j));
                near[i][j] = fnear(near[i][j], near[i - 1][j - 1], mp(i, j));
            }
            ans[i][j] = min(ans[i][j], edist(near[i][j], mp(i, j)));
        }
    }
    // kanan atas
    init_near();
    for (int i=1;i<=n;i++){
        for (int j=m;j>=1;j--){
            if (ar[i][j]) near[i][j] = mp(i, j);
            else{
                near[i][j] = fnear(near[i - 1][j], near[i][j + 1], mp(i, j));
                near[i][j] = fnear(near[i][j], near[i - 1][j + 1], mp(i, j));
            }
            ans[i][j] = min(ans[i][j], edist(near[i][j], mp(i, j)));
        }
    }
    // kiri bawah
    init_near();
    for (int i=n;i>=1;i--){
        for (int j=1;j<=m;j++){
            if (ar[i][j]) near[i][j] = mp(i, j);
            else{
                near[i][j] = fnear(near[i + 1][j], near[i][j - 1], mp(i, j));
                near[i][j] = fnear(near[i][j], near[i + 1][j - 1], mp(i, j));
            }
            ans[i][j] = min(ans[i][j], edist(near[i][j], mp(i, j)));
        }
    }
    // kanan bawah
    init_near();
    for (int i=n;i>=1;i--){
        for (int j=m;j>=1;j--){
            if (ar[i][j]) near[i][j] = mp(i, j);
            else{
                near[i][j] = fnear(near[i + 1][j], near[i][j + 1], mp(i, j));
                near[i][j] = fnear(near[i][j], near[i + 1][j + 1], mp(i, j));
            }
            ans[i][j] = min(ans[i][j], edist(near[i][j], mp(i, j)));
        }
    }
    ll tot = 0;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (ans[i][j] != INF) tot += ans[i][j];
        }
    }
    cout << tot << el;

    return 0;
}
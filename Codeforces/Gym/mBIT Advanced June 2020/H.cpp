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
const int INF = 1e6 + 10;

int n;
int ar[N][N];
int h[N][N];
bool udh[N][N];

int di[4] = {1, -1, 0, 0};
int dj[4] = {0, 0, 1, -1};

bool valid(int a){
    return 1 <= a && a <= n;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cin >> ar[i][j];
        }
    }
    set<pair<int, pair<int, int>>> setdah;
    for (int i=2;i<=n - 1;i++){
        for (int j=2;j<=n - 1;j++){
            h[i][j] = INF;
            setdah.insert(mp(INF, mp(i, j)));
        }
    }
    for (int i=1;i<=n;i++){
        h[i][1] = ar[i][1];
        h[i][n] = ar[i][n];
        h[1][i] = ar[1][i];
        h[n][i] = ar[n][i];
        setdah.insert(mp(ar[i][1], mp(i, 1)));
        setdah.insert(mp(ar[i][n], mp(i, n)));
        setdah.insert(mp(ar[1][i], mp(1, i)));
        setdah.insert(mp(ar[n][i], mp(n, i)));
    }
    while (setdah.size()){
        auto temp = *setdah.begin();
        int cur = temp.fi;
        pii node = temp.se;
        setdah.erase(temp);
        for (int i=0;i<4;i++){
            int na = node.fi + di[i];
            int nb = node.se + dj[i];
            if (!valid(na) || !valid(nb)) continue;
            if (h[na][nb] > cur){
                setdah.erase(mp(h[na][nb], mp(na, nb)));
                h[na][nb] = max(cur, ar[na][nb]);
                setdah.insert(mp(h[na][nb], mp(na, nb)));
            }
        }
    }
    ll ans = 0;
    for (int i=2;i<=n - 1;i++){
        for (int j=2;j<=n - 1;j++){
            ans += h[i][j] - ar[i][j];
        }
    }
    cout << ans << el;

    return 0;
}
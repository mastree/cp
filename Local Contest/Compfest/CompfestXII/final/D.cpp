#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MX = 1e3 + 10;

ll pref[MX][MX], cpref[MX][MX];
ll ar[MX][MX];
int n, m, r;

ll range(int ra, int ca, int rb, int cb){
    ra = max(ra, 1);
    ca = max(ca, 1);
    rb = min(rb, MX - 1);
    cb = min(cb, MX - 1);
    return pref[rb][cb] - pref[ra - 1][cb] - pref[rb][ca - 1] + pref[ra - 1][ca - 1];
}
ll crange(int ra, int ca, int rb, int cb){
    ra = max(ra, 1);
    ca = max(ca, 1);
    rb = min(rb, MX - 1);
    cb = min(cb, MX - 1);
    return cpref[rb][cb] - cpref[ra - 1][cb] - cpref[rb][ca - 1] + cpref[ra - 1][ca - 1];
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> r;
    for (int i=1;i<=n;i++){
        int r, c;
        ll b;
        cin >> r >> c >> b;
        ar[r][c] = b;
    }
    for (int i=1;i<MX;i++){
        ll tot = 0;
        ll ctot = 0;
        for (int j=1;j<MX;j++){
            tot += ar[i][j];
            ctot += (ar[i][j] > 0);
            pref[i][j] = pref[i - 1][j] + tot;
            cpref[i][j] = cpref[i - 1][j] + ctot;
        }
    }
    for (int i=1;i<=4;i++){
        for (int j=1;j<=4;j++){
            cout << pref[i][j] << " ";
            assert(range(1, 1, i, j) == pref[i][j]);
        }
        cout << el;
    }
    cout << el;
    for (int i=1;i<=4;i++){
        for (int j=1;j<=4;j++){
            cout << cpref[i][j] << " ";
            assert(crange(1, 1, i, j) == cpref[i][j]);
        }
        cout << el;
    }

    return 0;
}
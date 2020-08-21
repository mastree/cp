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
const double INF = 1e9;

int q;
int n, m, xa, ya, xb, yb, k;

pii getpos(int x, int y, int i, int j){
    if (i & 1) y = n - y;
    if (j & 1) x = m - x;
    return mp(x, y);
}
int dist_up(int i, int j){
    pii pos = getpos(xb, yb, i, j);
    int ret = (n - ya) + pos.se + (i - 1) * n;
    return abs(ret); 
}
int dist_down(int i, int j){
    pii pos = getpos(xb, yb, i, j);
    int ret = ya + (n - pos.se) + (i - 1) * n;
    return abs(ret);
}
int dist_left(int i, int j){
    pii pos = getpos(xb, yb, i, j);
    int ret = xa + (m - pos.fi) + (j - 1) * m;
    return abs(ret);
}
int dist_right(int i, int j){
    pii pos = getpos(xb, yb, i, j);
    int ret = (m - xa) + pos.fi + (j - 1) * m;
    return abs(ret);
}
double edist(double a, double b){
    return sqrt(a * a + b * b);
}

void solve(){
    cin >> m >> n >> xa >> ya >> xb >> yb >> k;
    double ans = INF;
    for (int i=0;i<=k;i++){
        int j = k - i;

        double up = dist_up(i, j);
        double down = dist_down(i, j);
        double left = dist_left(i, j);
        double right = dist_right(i, j);
        ans = min(ans, edist(up, left));
        ans = min(ans, edist(up, right));
        ans = min(ans, edist(down, left));
        ans = min(ans, edist(down, right));
    }
    cout << ans << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(5);
    cin >> q;
    while (q--){
        solve();
    }

    return 0;
}
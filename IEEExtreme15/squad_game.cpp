#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using ld = long double;

const ll INF = 1e18;

struct point {
    ll x,y;
    point(ll _x = 0, ll _y = 0) : x(_x), y(_y) {}
    point operator+(const point& p) const { return point(x + p.x, y + p.y); }
    point operator-(const point& p) const { return point(x - p.x, y - p.y); }
    point operator*(ll t) { return point(x * t, y * t); }
    point operator/(ll t) { return point(x / t, y / t); }
    ll operator*(const point& p) const { return x * p.x + y * p.y; }
    ll operator%(const point& p) const { return x * p.y - y * p.x; }
    ll squared_norm() { return (*this) * (*this); }
    bool operator==(const point& p) const { return (x == p.x) && (y == p.y); }
};

ll doubleAreaTriangle(point a, point b, point c) {
    return abs((a-b) % (c-b));
}

vector<int> allmask[11];

void solve() {
    int n;
    cin >> n;
    for (int i=0;i<=n;i++) allmask[i].clear();
    for (int i=0;i<(1 << n);i++){
        int cnt = __builtin_popcount(i);
        allmask[cnt].pb(i);
    }
    vector<point> A, B, C;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        A.emplace_back(point(x, y));
    }
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        B.emplace_back(point(x, y));
    }
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        C.emplace_back(point(x, y));
    }
    vector<int> orderb;
    pair<ll, int> ret = mp(INF, -1);
    for (int i=0;i<n;i++){
        orderb.pb(i);
    }
    int permb = 0;
    int mxmask = (1 << n);
    do {
        vector<ll> dp(mxmask, INF);
        vector<int> par(mxmask, -1);
        dp[0] = 0;
        for (int i=0;i<n;i++){
            for (auto mask : allmask[i]){
                if (dp[mask] < INF){
                    for (int j=0;j<n;j++){
                        int bit = (1 << j);
                        if (mask & bit) continue;
                        int nmask = mask + bit;
                        ll nval = dp[mask] + doubleAreaTriangle(A[j], B[orderb[j]], C[i]);
                        if (dp[nmask] > nval){
                            dp[nmask] = nval;
                            par[nmask] = j;
                        }
                    }
                }
            }
        }
        ret = min(ret, mp(dp[mxmask - 1], permb));
        permb++;
    } while (next_permutation(orderb.begin(), orderb.end()));
    {
        sort(orderb.begin(), orderb.end());
        while (ret.se--) next_permutation(orderb.begin(), orderb.end());
        vector<ll> dp(mxmask, INF);
        vector<int> par(mxmask, -1);
        dp[0] = 0;
        for (int i=0;i<n;i++){
            for (auto mask : allmask[i]){
                if (dp[mask] < INF){
                    for (int j=0;j<n;j++){
                        int bit = (1 << j);
                        if (mask & bit) continue;
                        int nmask = mask + bit;
                        ll nval = dp[mask] + doubleAreaTriangle(A[j], B[orderb[j]], C[i]);
                        if (dp[nmask] > nval){
                            dp[nmask] = nval;
                            par[nmask] = j;
                        }
                    }
                }
            }
        }
        vector<int> orderc(n, 0);
        int mask = mxmask - 1;
        int id = n - 1;
        while (mask){
            orderc[par[mask]] = id--;
            mask = (mask - (1 << par[mask]));
        }
        for (int i=0;i<n;i++){
            cout << i + 1 << " " << orderb[i] + 1 << " " << orderc[i] + 1 << el;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}
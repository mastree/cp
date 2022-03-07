#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

const ld EPS = 1e-9;
const int R = 101;
const ld MAX = 1e19;

// N * (1 + (R / 100)) ^ x >= P
vector<vector<ld>> pre(R);
ld logr[R];

void solve() {
    int rr;
    ull nn, pp;
    cin >> nn >> rr >> pp;
    long double n = nn, p = pp;

    if (p <= n) {
        cout << 0 << '\n';
        return;
    }
    long double X = log2(p / n);
    ll approx = max((ll)ceil(X / logr[rr]), 1LL);

    while (n * pre[rr][approx] + EPS < p) approx++;
    while (approx > 1 && n * pre[rr][approx - 1] + EPS >= p) approx--;
    cout << approx << '\n';
}
 
int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    // precompute
    for (int i=1;i<R;i++) {
        pre[i].pb(1);

        int pw = 0;
        ld r = (1 + ((ld)i) / 100);
        logr[i] = log2(r);
        while (true) {
            pw++;
            ld temp = pre[i][pw / 2] * pre[i][pw / 2];
            if (pw & 1) temp *= r;
            pre[i].pb(temp);
            if (temp > MAX) break;
        }
    }

    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cout << "Case " << t << ": ";
        solve();
    }
    
    return 0;
}

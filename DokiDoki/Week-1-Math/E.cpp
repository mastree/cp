#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

const int N = 1e5 + 10;

int m, n;
ld pre[N];

ld fpow(ld a, int b){
    ld ret = 1.0;
    while (b){
        if (b & 1){
            ret *= a;
        }
        a *= a;
        b >>= 1;
    }
    return ret;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(11);
    cin >> m >> n;

    for (int i=1;i<=m;i++){
        ld base = ((ld)i) / ((ld)m);
        pre[i] = fpow(base, n);
    }
    for (int i=m;i>=2;i--){
        pre[i] -= pre[i - 1];
    }
    ld ans = 0;
    for (int i=1;i<=m;i++){
        ans += pre[i] * ((ld)i);
    }
    cout << ans << el;

    return 0;
}
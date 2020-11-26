#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using ld = long double;

const int N = 1e3 + 10;

int n;
ld ans[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(11);

    cin >> n;
    ld sisa = 1;
    ans[1] = sisa / ld(n);

    ld rasio = 1;
    for (int i=2;i<=n;i++){
        rasio *= ld(1) - ans[i - 1];
        ans[i] = ans[1] * (ld(1) / rasio);
    }
    for (int i=n;i>=1;i--){
        cout << ans[i] * ld(100) << " ";
    }
    cout << el;

    return 0;
}
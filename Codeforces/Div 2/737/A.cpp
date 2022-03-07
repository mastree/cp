#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e5 + 10;
const double INF = 1e10 + 10;

int n, q;
int ar[N];

void solve(){
    cin >> n;
    double ri = 0;
    double ans = -INF;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        ri += ar[i];
    }
    sort(ar + 1, ar + n + 1);
    double le = 0;
    for (int i=1;i<n;i++){
        le += ar[i];
        ri -= ar[i];
        ans = max(ans, le / i + ri / (n - i));
    }
    cout << ans << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(10);
    cin >> q;
    while (q--){
        solve();
    }

    return 0;
}
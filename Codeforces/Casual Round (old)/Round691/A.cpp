#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e5 + 10;

ll n, m;
ll ar[N], br[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    sort(ar + 1, ar + n + 1);
    ll ans = 0;
    for (int i=1;i<n;i++){
        ans = __gcd(ans, ar[i + 1] - ar[i]);
    }
    for (int i=1;i<=m;i++){
        cin >> br[i];
        cout << __gcd(ans, ar[1] + br[i]) << ' ';
    }
    cout << el;

    return 0;
}
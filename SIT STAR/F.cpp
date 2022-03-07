#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n, m;
ll ans = 0;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i * (m - 1) + 1<=n;i++){
        int need = i * (m - 1) + 1;
        ans += n - need + 1;
    }
    cout << ans << el;

    return 0;
}
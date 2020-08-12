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

int n;
ll bus[N];
ll ans;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        ll a;
        cin >> a;
        ans += a;
    }
    for (int i=1;i<=n;i++){
        cin >> bus[i];
    }
    sort(bus + 1, bus + n + 1, greater<ll>());
    for (int i=1;i<=n;i++){
        ans -= 1LL * bus[i] * (i - 1);
    }
    cout << ans << el;

    return 0;
}
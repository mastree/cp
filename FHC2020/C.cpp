#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e6;

int q;
int n;
pii ar[N];

void solve(){
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i].fi >> ar[i].se;
    }
    sort(ar + 1, ar + n + 1, greater<pii>());
    unordered_map<int, int> dp;
    for (int i=1;i<=n;i++){
        int pos = ar[i].fi, len = ar[i].se;
        dp[pos - len] = max(len + dp[pos], dp[pos - len]);
        dp[pos] = max(len + dp[pos + len], dp[pos]);
    }
    int ans = 0;
    for (auto x : dp) ans = max(ans, x.se);
    cout << ans << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("timber_input.txt", "r", stdin);
    freopen("C.out", "w", stdout);

    cin >> q;
    for (int i=1;i<=q;i++){
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}
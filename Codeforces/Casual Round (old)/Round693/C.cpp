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

int q;
int n;
ll ar[N];
ll dp[N];

void solve(){
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    fill(dp, dp + N, 0);
    ll ans = 0;
    for (int i=n;i>=1;i--){
        ll skor = ar[i];
        if (i + (int)ar[i] <= n) skor += dp[i + (int)ar[i]];
        dp[i] = skor;
        ans = max(ans, skor);
    }
    cout << ans << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        solve();
    }

    return 0;
}
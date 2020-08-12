#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 3e3 + 10;
const int MAX = (int)1e9 + (int)1e5;
const ll INF = 1e18;

int n;
int ar[N];
map<int, ll> dp;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    for (int i=1;i<=n;i++){
        int jarak = i - 1;
        ll cost = (ll)abs((ar[i] - jarak) - ar[1]);
        dp[ar[i] - jarak] = cost;
    }
    ll mn = INF;
    for (auto& x : dp){
        mn = min(mn, x.se);
        x.se = mn;
    }
    for (int i=2;i<=n;i++){
        map<int, ll> next;
        for (auto x : dp){
            ll jarak = (ll)abs((x.fi + 1) - ar[i]);
            next[x.fi + 1] = x.se + jarak;
        }
        dp.swap(next);
        ll mn = INF;
        for (auto& x : dp){
            mn = min(mn, x.se);
            x.se = mn;
        }
    }
    ll ans = INF;
    for (auto x : dp){
        ans = min(ans, x.se);
    }
    cout << ans << el;

    return 0;
}
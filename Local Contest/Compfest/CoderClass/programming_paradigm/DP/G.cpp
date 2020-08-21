#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e3 + 10, M = 5e3 + 10;

int n, m;
int val[M];
vector<pii> ayam; // weight, value
int dp[M]; // dp[isi] = value max

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=n;i++){
        int a, b;
        cin >> a >> b;
        val[a] = max(val[a], b);
    }
    for (int i=1;i<M;i++){
        if (val[i]){
            ayam.pb(mp(i, val[i]));
        }    
    }
    for (auto x : ayam){
        for (int i=0;i + x.fi<=m;i++){
            dp[i + x.fi] = max(dp[i + x.fi], dp[i] + x.se);
        }
    }
    int ans = 0;
    for (int i=0;i<=m;i++){
        ans = max(ans, dp[i]);
    }
    cout << ans << el;

    return 0;
}
#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 15;

int q;
int n, m, k;
pair<pii, int> ar[N + 2]; 

void solve(){
    cin >> n >> m >> k;
    int MASK = (1 << n);
    vector<int> adj(n, 0), adjmask(MASK, 0);
    vector<ll> tot(MASK, 0);
    for (int i=0;i<n;i++){
        int l, r, a;
        cin >> l >> r >> a;
        ar[i] = mp(mp(l, r), a);
    }
    for (int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        adj[a] |= (1 << b);
        adj[b] |= (1 << a);
    }
    adjmask[0] = MASK - 1;
    for (int mask=0;mask<MASK;mask++){
        for (int j=0;j<n;j++){
            if (mask & (1 << j)){
                adjmask[mask] |= adj[j];
                tot[mask] += ar[j].se;
            }
        }
    }
    vector<ll> dp(MASK, 0);
    dp[0] = 1;
    ll ans = 0;
    for (int mask=0;mask<MASK;mask++){
        if (tot[mask] == k) ans += dp[mask];
        for (int j=0;j<n;j++){
            int bit = (1 << j);
            if ((adjmask[mask] & bit) && (mask == 0 || (ar[j].fi.fi <= tot[mask] && tot[mask] <= ar[j].fi.se))){
                int nmask = (mask | bit);
                if (nmask > mask){
                    dp[nmask] += dp[mask];
                }
            }
        }
    }
    cout << ans << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    for (int i=1;i<=q;i++){
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}
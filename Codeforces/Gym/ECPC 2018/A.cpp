#pragma gcc optimize ("O3")
#pragma gcc optimize ("unroll-loops")

#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int q;
ll cari(ll a, ll b, vector<ll>& vec){
    if (a > b) return 0LL;
    return upper_bound(vec.begin(), vec.end(), b) - lower_bound(vec.begin(), vec.end(), a);
}

void solve(){
    int x, y, len;
    ll MOD, K;
    cin >> x >> y >> MOD >> K;
    len = x + y;
    vector<ll> pang(len);
    for (int i=0;i<len;i++){
        pang[i] = (1LL << i) % MOD;
    }
    vector<pair<ll, int>> awal; // 0..21
    if (len <= 21 + 1){
        awal.pb(mp(pang[len - 1], 1));
        for (int i=0;i<len - 1;i++){
            int curlen = awal.size();
            for (int j=0;j<curlen;j++){
                auto temp = awal[j];
                if (temp.se == x) continue;
                temp.fi = (temp.fi + pang[i]) % MOD;
                temp.se++;
                awal.pb(temp);
            }
        }
        vector<vector<ll>> a(30);
        for (auto& xx : awal){
            a[xx.se].pb(xx.fi);
        }
        ll ans = 0;
        for (auto& xx : a[x]){
            if (xx >= K) ans++;
        }        
        cout << ans << el;
    } else{
        awal.pb(mp(0LL, 0));
        int cnt1 = 0;
        for (int i=0;i<=21;i++){
            int curlen = awal.size();
            for (int j=0;j<curlen;j++){
                auto temp = awal[j];
                if (temp.se == x) continue;
                temp.fi = (temp.fi + pang[i]) % MOD;
                temp.se++;
                if (temp.fi) cnt1++;
                awal.pb(temp);
            }
        }
        vector<pair<ll, int>> akhir; // 22..42
        akhir.pb(mp(pang[len - 1], 1));
        for (int i=22;i<len - 1;i++){
            int curlen = akhir.size();
            for (int j=0;j<curlen;j++){
                auto temp = akhir[j];
                if (temp.se == x) continue;
                temp.fi = (temp.fi + pang[i]) % MOD;
                temp.se++;
                akhir.pb(temp);
            }
        }
        vector<vector<ll>> a(30), b(30);
        for (auto& xx : awal){
            a[xx.se].pb(xx.fi);
        }
        for (auto& xx : akhir){
            b[xx.se].pb(xx.fi);
        }
        for (int i=0;i<30;i++){
            sort(a[i].begin(), a[i].end());
        }
        ll ans = 0;
        for (int i=0;i<30;i++){
            if (b[i].empty()) continue;
            int pi = x - i;
            for (auto& xx : b[i]){
                ll cur = xx;
                ll l = (K - cur + MOD) % MOD;
                ll r = MOD - 1 - cur;
                if (l > r){
                    ans += cari(0, r, a[pi]) + cari(l, MOD - 1, a[pi]);
                } else{
                    ans += cari(l, r, a[pi]);
                }
            }
        }
        cout << ans << el;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    freopen("zeros.in", "r", stdin);
    cin >> q;
    while (q--){
        solve();
    }

    return 0;
}
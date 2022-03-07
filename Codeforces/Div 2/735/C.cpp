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
ll n, m;

void solve(){
    cin >> n >> m;
    if (m < n){
        cout << 0 << el;
        return;
    }
    vector<int> pos;
    for (int i=0;i<30;i++){
        if (n & (1LL << i)) continue;
        pos.pb(i);
    }
    ll l = 0, r = (1LL << pos.size()) - 1, ans = m + 1;
    while (l <= r){
        ll md = (l + r) / 2;
        ll ang = n, out = 0;
        for (int i=0;i<=30;i++){
            if (md & (1LL << i)){
                out += (1LL << pos[i]);
            }
        }
        if (ang + out > m){
            r = md - 1;
            ans = out;
        } else{
            l = md + 1;
        }
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
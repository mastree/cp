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
void solve(){
    map<pii, bool> ada;
    set<int> xx, yy;
    for (int i=1;i<=3;i++){
        int a, b;
        cin >> a >> b;
        ada[mp(a, b)] = 1;
        xx.insert(a);
        yy.insert(b);
    }
    pii ans;
    for (auto x : xx){
        for (auto y : yy){
            if (ada[mp(x, y)]) continue;
            ans = mp(x, y);
        }
    }
    cout << ans.fi << " " << ans.se << el;
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
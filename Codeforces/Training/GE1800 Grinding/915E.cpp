#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n, q;
int ans;

int iris(pii a, pii b){
    return max(min(a.se, b.se) - max(a.fi, b.fi) + 1, 0);
}
int value(pii a){
    return a.se - a.fi + 1;
}

// a - b
vector<pii> get_frag(pii a, pii b){
    vector<pii> ret;
    if (iris(a, b) == value(a)) return ret;
    if (a.fi < b.fi){
        ret.pb(mp(a.fi, b.fi - 1));
    }
    if (a.se > b.se){
        ret.pb(mp(b.se + 1, a.se));
    }
    return ret;
}

set<pair<pii, bool>> setdah;
void solve(){
    int l, r, tipe;
    cin >> l >> r >> tipe;

    auto it = setdah.lower_bound(mp(mp(l + 1, 0), 0));
    it--;
    vector<pair<pii, bool>> pus, tam;
    tam.pb(mp(mp(l, r), (tipe == 2)));
    while (1){
        int sec = iris(it->fi, mp(l, r));
        if (sec == 0) break;
        pus.pb(*it);
        ans -= value(it->fi) * it->se;
        auto temp = get_frag(it->fi, mp(l, r));
        for (auto x : temp){
            tam.pb(mp(x, it->se));
        }
        it++;
    }
    for (auto x : pus){
        setdah.erase(x);
    }
    for (auto x : tam){
        setdah.insert(x);
        if (x.se){
            ans += value(x.fi);
        }
    }
    cout << ans << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    ans = n;
    setdah.insert(mp(mp(0, 0), 0));
    setdah.insert(mp(mp(n + 1, n + 1), 0));
    setdah.insert(mp(mp(1, n), 1));
    cin >> q;
    while (q--){
        solve();
    }

    return 0;
}
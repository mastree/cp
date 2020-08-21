#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int N = 1e6 + 10;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int q;
int n, k;
ll w;
ll L[N], H[N];
ll lr[5], hr[5];

ll per[N];

void init(){
    for (int i=k + 1;i<=n;i++){
        L[i] = (lr[1] * L[i - 2] + lr[2] * L[i - 1] + lr[3]) % lr[4] + 1LL;
        H[i] = (hr[1] * H[i - 2] + hr[2] * H[i - 1] + hr[3]) % hr[4] + 1LL;
    }
}
void tambah(set<pll>& setdah, pll val){
    auto it = setdah.lower_bound(val);
    it--;
    vector<pll> pus;
    while (it->se <= val.se){
        pus.pb(*it);
        it--;
    }
    for (auto x : pus) setdah.erase(x);
    setdah.insert(val);
}

void solve(){
    cin >> n >> k >> w;
    for (int i=1;i<=k;i++){
        cin >> L[i];
    }
    for (int i=1;i<=4;i++){
        cin >> lr[i];
    }
    for (int i=1;i<=k;i++){
        cin >> H[i];
    }
    for (int i=1;i<=4;i++){
        cin >> hr[i];
    }
    init();
    ll ans = 1;
    ll last = 0;
    set<pll> setdah; // x, max h (x1 < x2 < x3 < ..., h1 > h2 > h3 > ...)
    setdah.insert(mp(0LL, INF)); 
    setdah.insert(mp(INF, 0LL));

    for (int i=1;i<=n;i++){
        per[i] = per[i - 1];
        if (last < L[i]) last = L[i];
        per[i] = (per[i] + (L[i] + w - last) * 2LL) % MOD;
        last = L[i] + w;

        auto it = setdah.lower_bound(mp(L[i], 0LL));
        per[i] = (per[i] + max(0LL, H[i] - it->se) * 2LL) % MOD;
        tambah(setdah, mp(L[i] + w, H[i]));
    }
    for (int i=1;i<=n;i++){
        // cout << per[i] << " ";
        ans = ans * per[i] % MOD;
    }
    // cout << el;
    cout << ans << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("perimetric_chapter_1_input.txt", "r", stdin);
    freopen("A.out", "w", stdout);

    cin >> q;
    for (int i=1;i<=q;i++){
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}
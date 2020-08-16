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
using plll = pair<pair<ll, ll>, ll>;

plll mp3(const ll& a, const ll& b, const ll& c){
    return mp(mp(a, b), c);
}

const int N = 1e6 + 10;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int q;
int n, k;
ll L[N], W[N], H[N];
ll LR[5], WR[5], HR[5];
ll per[N];

void init(){
    for (int i=k + 1;i<=n;i++){
        L[i] = (LR[1] * L[i - 2] + LR[2] * L[i - 1] + LR[3]) % LR[4] + 1LL;
        W[i] = (WR[1] * W[i - 2] + WR[2] * W[i - 1] + WR[3]) % WR[4] + 1LL;
        H[i] = (HR[1] * H[i - 2] + HR[2] * H[i - 1] + HR[3]) % HR[4] + 1LL;
    }
}
void debug(){
    cout << el;
    for (int i=1;i<=n;i++){
        cout << L[i] << " ";
    }
    cout << el;
    for (int i=1;i<=n;i++){
        cout << W[i] << " ";
    }
    cout << el;
    for (int i=1;i<=n;i++){
        cout << H[i] << " ";
    }
    cout << el;
    for (int i=1;i<=n;i++){
        cout << per[i] << " ";
    }
    cout << el;
}

void solve(){
    cin >> n >> k;
    for (int i=1;i<=k;i++){
        cin >> L[i];
    }
    for (int i=1;i<=4;i++){
        cin >> LR[i];
    }
    for (int i=1;i<=k;i++){
        cin >> W[i];
    }
    for (int i=1;i<=4;i++){
        cin >> WR[i];
    }
    for (int i=1;i<=k;i++){
        cin >> H[i];
    }
    for (int i=1;i<=4;i++){
        cin >> HR[i];
    }
    init();
    ll ans = 1;
    set<pll> setdah; // range(l, r)
    setdah.insert(mp(-1, -1));
    setdah.insert(mp(INF, INF));
    for (int i=1;i<=n;i++){
        ll l = L[i], r = L[i] + W[i];
        ll tam = (W[i] + H[i]) * 2LL % MOD;
        ll kur = 0;

        vector<pll> pus;

        auto it = setdah.lower_bound(mp(l + 1, 0));
        it--;
        if (it->se >= l){
            pus.pb(*it);
        }
        it++;
        while (it->fi <= r){
            pus.pb(*it);
            it++;
        }

        if (pus.empty()){
            setdah.insert(mp(l, r));
        } else{
            pll baru = mp(l, r);
            for (auto x : pus){
                baru.fi = min(baru.fi, x.fi);
                baru.se = max(baru.se, x.se);

                kur = (kur + (min(r, x.se) - max(x.fi, l)) * 2LL) % MOD;
                kur = (kur + H[i] * 2LL) % MOD;

                setdah.erase(x);
            }
            setdah.insert(baru);
        }
        tam = (tam - kur + MOD) % MOD;
        per[i] = (per[i - 1] + tam) % MOD;
    }
    for (int i=1;i<=n;i++){
        ans = (ans * per[i]) % MOD;
    }
    ans = (ans % MOD + MOD) % MOD;
    cout << ans << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("perimetric_chapter_2_input.txt", "r", stdin);
    freopen("A2.out", "w", stdout);

    cin >> q;
    for (int i=1;i<=q;i++){
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}
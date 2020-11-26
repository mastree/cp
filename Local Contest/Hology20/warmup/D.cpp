#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const ll MOD = 998244353;
const int N = 3e5 + 10;

int n;
pii ar[N];
ll fac[N];

ll cnt[N], cnt2[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    fac[0] = 1;
    for (int i=1;i<N;i++){
        fac[i] = fac[i - 1] * i % MOD;
    }

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i].fi >> ar[i].se;
        cnt[ar[i].fi]++;
        cnt2[ar[i].se]++;
    }
    {
        int ada = 0, ada2 = 0;
        for (int i=1;i<=n;i++){
            if (cnt[i]) ada++;
            if (cnt2[i]) ada2++;
        }
        if (ada == 1 || ada2 == 1){
            cout << 0 << el;
            return 0;
        }
    }
    ll ans = 0;
    ll cur = 1;
    for (int i=1;i<=n;i++){
        if (cnt[i]){
            cur = cur * fac[cnt[i]] % MOD;
        }
    }
    ans = cur;
    cur = 1;
    for (int i=1;i<=n;i++){
        if (cnt2[i]){
            cur = cur * fac[cnt2[i]] % MOD;
        }
    }
    ans = (ans + cur) % MOD;

    sort(ar + 1, ar + 1 + n);
    bool ok = 1;

    map<pii, ll> haha;
    for (int i=1;i<=n;i++){
        if (ar[i].fi < ar[i - 1].fi || ar[i].se < ar[i - 1].se) ok = 0;
        haha[ar[i]]++;
    }
    if (ok){
        cur = 1;
        for (auto x : haha){
            cur = cur * fac[x.se] % MOD;
        }
        ans = (ans - cur + MOD) % MOD;
    }

    ans = (fac[n] - ans + MOD) % MOD;
    cout << ans << el;

    return 0;
}
#pragma gcc optimize ("O2")
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

const int N = 1e5 + 10;
const ll MOD = 1e9 + 7;

ll fpow(ll a, ll b){
    ll ret = 1;
    while (b){
        if (b & 1){
            ret = ret * a % MOD;
        }
        b >>= 1;
        a = a * a % MOD;
    }
    return ret;
}

int n;
ll ar[N];
ll ans;

bool sieve[N];

vector<int> arpos[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    ll mx = 0;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        mx = max(mx, ar[i]);
    }
    fill(sieve + 2, sieve + N, 1);
    for (int i=2;i * i<N;i++){
        if (!sieve[i]) continue;
        for (int j=i * i;j<N;j+=i){
            sieve[j] = 0;
        }
    }
    ans = 1;
    ll last = 0;
    for (ll i=1;i * i<=mx;i++){
        if (!sieve[i]) continue;
        last = i;
        vector<pair<ll, int>> temp;
        for (int j=1;j<=n;j++){
            ll cnt = 0;
            while (ar[j] % i == 0){
                ar[j] /= i;
                cnt++;
            }
            if (cnt) temp.pb(mp(cnt, j));
        }
        sort(temp.begin(), temp.end(), greater<pair<ll, int>>());
        set<int> setdah;
        setdah.insert(0);
        setdah.insert(n + 1);

        ll pang = 0;
        for (auto x : temp){
            ll val = x.fi;
            int pos = x.se;
            auto itb = setdah.lower_bound(pos);
            auto it = itb--;
            pang = (pang + (val * (*it - pos) * (pos - *itb))) % (MOD - 1);
            setdah.insert(pos);
        }
        ans = (ans * fpow(i, pang)) % MOD;
    }
    for (int i=1;i<=n;i++){
        if (ar[i] > last){
            arpos[ar[i]].pb(i);
        }
    }
    for (ll i=last + 1;i<N;i++){
        if (!sieve[i] || arpos[i].empty()) continue;
        int back = 0;
        for (auto x : arpos[i]){
            ans = ans * fpow(i, 1LL * (x - back) * (n - x + 1)) % MOD;
            back = x;
        }
    }
    cout << ans << el;

    return 0;
}
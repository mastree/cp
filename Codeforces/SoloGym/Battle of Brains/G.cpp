#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;

ll hit(ll n){
    return (n + 1) * n / 2 % MOD;
}

int q;
void solve(){
    int n;
    cin >> n;
    vector<ll> vec(n + 1);
    for (int i=1;i<=n;i++){
        char c;
        cin >> c;
        vec[i] = (ll)c;
    }
    ll all = 0;
    vector<ll> le(n + 2, 0), ri(n + 2, 0);
    for (int i=1;i<=n;i++){
        le[i] = (le[i - 1] + hit(i)) % MOD;
    }
    for (int i=1;i<=n;i++){
        ri[n - i + 1] = le[i];
    }
    all = le[n];
    ll ret = 0;
    for (int i=1;i<=n;i++){
        ret = (ret + vec[i] * (all - le[i - 1] - ri[i + 1] + 2 * MOD) % MOD) % MOD;
    }
    cout << (ret + MOD) % MOD << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    for (int i=1;i<=q;i++){
        cout << "Case " << i << ": ";
        solve();
    }

    return 0;
}
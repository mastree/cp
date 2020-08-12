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

int n;
ll bit[N];
ll ans;

void upd(int x, ll val){
    while (x < N){
        bit[x] = (bit[x] + val) % MOD;
        x = x + (x & (-x));
    }
}
ll ask(int x){
    ll ret = 0;
    while (x > 0){
        ret = (ret + bit[x]) % MOD;
        x = x - (x & (-x));
    }
    return ret;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    upd(1, 1LL);
    for (int i=1;i<=n;i++){
        int a;
        cin >> a;
        ll temp = ask(a);
        ans = (ans + temp) % MOD;
        upd(a, temp);
    }
    cout << ans << el;

    return 0;
}
#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
// #define MOD 1000000007
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'

using namespace std;

const ll MOD = 1e9 + 7;
const ll BORD = 1e18 + 2;

ll l, r;

ll fpow(ll a, ll b){
    if (b == 0) return 1;
    ll temp = fpow(a, b / 2);
    temp = temp * temp % MOD;
    if (b & 1) temp = temp * a % MOD;
    return temp;
}
ll inv(ll a){
    return fpow(a, MOD - 2);
}

ll findod(ll x, ll y){
    ll le = 0, ri = 0;
    ll ret = 0;
    ll cur = 1;
    ll turn = 0;

    ll cnt = 0;

    while (1){
        turn++;
        le = ri + 1LL;
        ri = le + cur - 1LL;
        if (le > y) break;
        if (turn & 1){
            ll range = min(ri, y) - max(le, x) + 1LL;
            if (range > 0){
                range %= MOD;
                ll ta = max(0LL, x - le) % MOD;
                ll a = ((cnt + ta) * 2LL + 1LL) % MOD;
                ll b = (a + range * 2LL - 2LL) % MOD;
                ll temp = (((a + b) * inv(2)) % MOD) * range % MOD;
                ret = (ret + temp) % MOD; 
            }
            cnt = (cnt + cur) % MOD;
        }
        cur *= 2;
    }
    return ret;
}

ll findev(ll x, ll y){
    ll le = 0, ri = 0;
    ll ret = 0;
    ll cur = 1;
    ll turn = 0;

    ll cnt = 0;

    while (1){
        turn++;
        le = ri + 1LL;
        ri = le + cur - 1LL;
        if (le > y) break;

        if (turn & 1 ^ 1){
            ll range = min(ri, y) - max(le, x) + 1LL;
            if (range > 0){
                range %= MOD;
                ll ta = max(0LL, x - le) % MOD;
                ll a = ((cnt + ta) * 2LL + 2LL) % MOD;
                ll b = (a + range * 2LL - 2LL) % MOD;
                ll temp = (((a + b) * inv(2)) % MOD) * range % MOD;
                ret = (ret + temp) % MOD;
            }
            cnt = (cnt + cur) % MOD;
        }
        cur += cur;
    }
    return ret;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> l >> r;
    ll ans = 0;
    ans = (ans + findod(l, r) % MOD + MOD) % MOD;
    ans = (ans + findev(l, r) % MOD + MOD) % MOD;
    cout << ans << el;

    return 0;
}
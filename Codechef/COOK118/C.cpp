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

const int N = 1e5 + 10;
const ll MOD = 999998777;
const ll P = 31;

int q;
int n;
string s;

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

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> s;
        int n = s.length();

        vector<ll> has(n + 2, 0);
        ll cur = 1;
        for (int i=1;i<=n;i++){
            ll dig = s[i - 1] - 'a' + 1;
            has[i] = (dig * cur + has[i - 1]) % MOD;
            cur = cur * P % MOD;
        }
        int nx = n / 2;
        int ans = 0;
        for (int n1=1;n1<nx;n1++){
            int n2 = nx - n1;
            ll h11 = has[n1];
            ll h12 = ((has[n1 * 2] - has[n1] + MOD) % MOD) * inv(fpow(P, n1)) % MOD;
            ll h21 = ((has[n1 * 2 + n2] - has[n1 * 2] + MOD) % MOD) * inv(fpow(P, n1 * 2)) % MOD;
            ll h22 = ((has[n] - has[n1 * 2 + n2] + MOD) % MOD) * inv(fpow(P, n1 * 2 + n2)) % MOD;
            if (h11 == h12 && h21 == h22) ans++;
        }
        cout << ans << el;
    }

    return 0;
}
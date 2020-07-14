#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef __uint128_t int128;

vector<int> numset = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}; 

ll binpow(ll a, ll b, ll m){
    ll ret = 1;
    a %= m;
    while (b){
        if (b & 1){
            ret = (int128)ret * a % m;
        }
        a = (int128)a * a % m;
        b >>= 1;
    }
    return ret;
}

bool is_composite(ll n, ll a, ll d, int s){
    ll x = binpow(a, d, n);
    if (x == 1 || x == n - 1) return 0;
    for (int r=1;r<s;r++){
        x = (int128)x * x % n;
        if (x == n - 1) return 0;
    }
    return 1;
}

bool mrcheck(ll n){
    if (n <= 4) return n == 2 || n == 3;
    int r = 0;
    ll d = n - 1;
    while ((d & 1) == 0){
        d >>= 1;
        r++;
    }
    for (int a : numset){
        if (n == a) return 1;
        if (is_composite(n, a, d, r)) return 0;
    }
    return 1;
}

int q;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        ll n;
        cin >> n;
        if (mrcheck(n)){
            cout << "YES\n";
        } else{
            cout << "NO\n";
        }
    }

    return 0;
}
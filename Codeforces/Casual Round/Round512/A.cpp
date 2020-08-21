#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'

using namespace std;

ll n, m, k;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    ll kk = 2;
    if (k % kk == 0){
        k /= 2;
        kk = 1;
    }
    // if (n * m % k != 0){
    //     cout << "NO" << el;
    //     return 0;
    // }
    ll gn = __gcd(n, k);
    if (gn >= kk){
        n = n / gn * kk;
        kk = 1;
    } else{
        n = n / gn;
    }
    k /= gn;
    ll gm = __gcd(m, k);
    if (gm >= kk){
        m = m / gm * kk;
        kk = 1;
    } else{
        m = m / gm;
    }
    k /= gm;
    if (k == 1 && kk == 1){
        cout << "YES" << el;
        cout << "0 0" << el;
        cout << n << " " << 0 << el;
        cout << 0 << " " << m << el;
    } else{
        cout << "NO" << el;
    }

    return 0;
}
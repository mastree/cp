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

int q;
ll a, m; 

ll phi(ll x){
    ll res = x;
    for (ll i=2;i*i<=x;i++){
        if (x % i == 0){
            res -= res / i;
            while (x%i == 0) x/=i;
        }
    }
    if (x > 1) res -= res / x;
    return res;
}

ll sol(){
    ll gcc = __gcd(a, m);
    return phi(m/gcc);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while(q--){
        cin >> a >> m;
        cout << sol() << el;
    }

    return 0;
}
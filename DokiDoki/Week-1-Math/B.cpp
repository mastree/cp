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

int q;
ll a, b;

bool cek(ll x){
    bool prime = 1;
    for (ll i=2;i * i<=x;i++){
        if (x % i == 0){
            prime = 0;
            break;
        }
    }
    return prime && x != 1;
}

void solve(){
    cin >> a >> b;
    ll tempa = a - b;
    ll tempb = a + b;
    if (tempa == 1 && cek(tempb)){
        cout << "YES" << el;
    } else{
        cout << "NO" << el;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        solve();
    }

    return 0;
}
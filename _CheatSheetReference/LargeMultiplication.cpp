#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll largemul(ll a, ll b, ll m){
    ll ret = 0;
    a %= m;
    for (; b; b >>= 1, a = (a << 1) % m){
        if (b & 1){
            ret = (ret + a) % m;
        }
    }
    return ret;
}
#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define ll long long
#define el '\n'

using namespace std;

ll sol(ll a, ll b){
    if (a<b) swap(a,b);
    if (b==0 && a==0) return 0;
    
    ll msb_a=0,msb_b=0;
    for (ll powa=0;powa<=61;powa++){
        if (((ll)1 << powa)&a){ 
            msb_a=powa;
        }
    }
    if (b==0) return ((ll)1 << (msb_a+1))-(ll)1;
    for (ll powb=0;powb<=61;powb++){
        if (((ll)1 << powb)&b){
            msb_b=powb;
        }
    }
 //   cout << msb_a << " " << msb_b << el;
    if (abs(msb_a-msb_b)>=1){
        return ((ll)1 << (msb_a+1))-(ll)1;
    }
    else if (msb_a==msb_b){
        ll tm=((ll)1 << msb_a);
        return sol(a-tm,b-tm);
    }

}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll a,b;
    cin >> a >> b;


    // ll msb_a=log2(a),msb_b=log2(b);
    // bitset<64> bit_a(a),bit_b(b);

    // cout << bit_a << el << bit_b << el;
    // cout << msb_a << el << msb_b << el;

    cout << sol(a,b) << el;

    return 0;
}
#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 998244353
#define pii pair<int,int>
#define ll long long
#define el '\n'

using namespace std;

ll w,h;

ll fpow(ll a,ll b){
 //   cerr << b << el;
    if (b==0) return 1;
    
    ll tm=fpow(a,b/2);
    if (b%2>0) return tm*tm%MOD*a%MOD;
    else return tm*tm%MOD;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> w >> h;

    cout << fpow(2,w+h) << el;

    return 0;
}
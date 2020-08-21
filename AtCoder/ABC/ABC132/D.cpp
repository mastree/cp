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
ll n,k,r;
ll pc[4005];

ll ppow(ll a,ll b){
    if (b==0) return 1;
    ll tm=ppow(a,b/2);
    if (b&1) return (tm*tm%MOD)*a%MOD;
    return tm*tm%MOD;
}

ll comb(ll n,ll k){
    return pc[n]*ppow(pc[k]*pc[n-k]%MOD,MOD-2)%MOD;
}

ll sol(ll a){
    ll mxmid=k-1;
    ll mid=a-1;
    if (r<mid){
        return 0;
    }

    ll res=comb(mxmid,mid);
    ll sisa=r-mid;
    res=res*comb(sisa+a,a)%MOD;

    return res;
}


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    pc[0]=1;
    for (ll i=1;i<4005;i++){
        pc[i]=pc[i-1]*i%MOD;
    }
    
    cin >> n >> k;
    r=n-k;
    
    for (ll i=1;i<=k;i++){
        cout << sol(i) << el;
    }

    return 0;
}
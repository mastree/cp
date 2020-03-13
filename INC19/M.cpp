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

const int N = 100007;

ll a,b;
ll fak[3*N];
ll n,k;

ll fast(ll a, ll b){
    if (b==0) return 1;
    ll tm=fast(a,b/2);
    if (b&1) return (tm*tm%MOD)*a%MOD;
    return tm*tm%MOD;
}

ll comb(ll n, ll k){
    if (k>n) return 0;
    ll ans;
    ans=(fak[n]*fast(fak[k],MOD-2)%MOD)*fast(fak[n-k],MOD-2)%MOD;

    return ans;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    fak[0]=1;
    for (ll i=1;i<3*N;i++){
        fak[i]=(fak[i-1]*i)%MOD;
    }

    cin >> a >> b;

    n=b+1;
    k=a;

    ll ans=0;
    for (ll i=0;i<=n;i++){
        if (i&1) ans-=(comb(n,i)*comb(n+k-1-3*i,n-1)%MOD);
        else ans+=(comb(n,i)*comb(n+k-1-3*i,n-1)%MOD);
        ans%=MOD;
        if (ans<0) ans+=MOD;
    }

    cout << ans << el;

    return 0;
}
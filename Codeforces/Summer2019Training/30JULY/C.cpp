#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000000000000007
#define pii pair<ll,ll>
#define ll long long
#define el '\n'

using namespace std;

ll n,I;
ll ar[400100];
map <ll,ll> cek;
ll cnt;
ll pc[400100];

ll fpow(ll a, ll b){
    if (b==0) return 1;
    if (b==1) return a;

    ll tm=fpow(a,b/2),res;
    if (b&1){
        res=tm*tm*a;
        if (res>=n) return n;
        return res;
    }
    res=tm*tm;
    if (res>=n) return n;
    return res;
} 

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> I;
    I*=8;

    for (ll i=0;i<n;i++){
        cin >> ar[i];
        if (cek[ar[i]]==0) cnt++;
        cek[ar[i]]++;
    }

    ll id=0;
    for (auto x : cek){
      //  cerr << x.se << el;
        id++;
        pc[id]=pc[id-1]+x.se;
    }

    ll mk=I/n;
    mk=fpow(2,mk);
    if (mk>=cnt){
        cout << 0 << el;
        return 0;
    }

    ll ans=MOD;

  //  for (ll i=0;i<=cnt;i++) cerr << pc[i] << el;

    for (ll i=0;i+mk<=cnt;i++){
   //     cerr << i << " " << i+mk << el;
        ans=min(ans,pc[i]+(pc[cnt]-pc[i+mk]));
    }

    cout << ans << el;

    return 0;
}
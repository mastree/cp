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

const int N = 100007;

ll x,n;
vector <ll> fac;
map<ll,ll> cnt,power;

void cons_factor(ll a){
    for (ll i=2;i*i<=a;i++){
        while (a%i==0){
            if (!cnt[i]) fac.pb(i);
            cnt[i]++;
            a/=i;
        }
    }

    if (a!=1){
        if (!cnt[a]) fac.pb(a);
        cnt[a]++;
    }

}

ll fast(ll a,ll b){
    if (b==(ll)0) return 1;
    if (b==1) return a;
    ll tm=fast(a,b/2);
    if (b%2) return (((tm*tm)%MOD)*a%MOD)%MOD;
    else return (tm*tm)%MOD;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> x >> n;
    cons_factor(x);
    sort(fac.begin(),fac.end());

    ll ans=1;
    for (auto k : fac){
        ll tm=n,rep=0;

        while (tm){
            tm/=k;
         //   cout << tm << el;
            power[k]=power[k]+tm;
            rep++;
        }
    //    cout << k << " " << power[k] << el;
    }

    for (auto k : fac){
        ans=(ans*fast(k,power[k])%MOD);
    }

    cout << ans << el;

    return 0;
}
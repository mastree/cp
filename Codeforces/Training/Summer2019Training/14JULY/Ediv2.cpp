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

ll n;
ll ar[100005];
ll dig[12];
ll pc10[21];

ll Cdigit(ll a){
    return (ll)(log10(a)+1);
}

ll depan(ll a,ll len){
    ll p=(ll)(log10(a)+1);
    return a/pc10[p-len];
}

ll belakang(ll a,ll len){
    ll p=(ll)(log10(a)+1);
    return a-(depan(a,p-len)*pc10[len]);
}

ll selipin(ll x) {
    ll ret=0;
    vector<ll> p;
    while (x>0) {
        p.pb(x%10);
        x/=10;
    }
    reverse(p.begin(),p.end());
    for (ll i=0;i<p.size();i++) {
        ret+=p[i];
        if (i==p.size()-1) ret*=1;
        else ret*=100;
    }
    return ret;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    pc10[0]=1;
    for (ll i=1;i<21;i++){
        pc10[i]=pc10[i-1]*10;
        if (i>9) pc[i]%=MOD;
    }

    cin >> n;
    for (ll i=0;i<n;i++){
        cin >> ar[i];
        dig[Cdigit(ar[i])]++;
    }

    ll ans=0,ans2=0;

    for (ll i=0;i<n;i++){
        for (ll j=1;j<=10;j++){
            if (dig[j]==0) continue;
            ll alen=(ll)(log10(ar[i])+1);
            if (j>=alen){
                ans+=((selipin(ar[i])%MOD)*10*dig[j])%MOD;
                ans%=MOD;
                ans+=(((selipin(ar[i]))%MOD)*dig[j])%MOD;
                ans%=MOD;
            }else{
                ll bk=belakang(ar[i],j),fr=depan(ar[i],alen-j);
                ll tm=ans;
              //  cerr << i << " " << fr << " " << bk << el;
                
                ans+=((selipin(bk)%MOD)*10*dig[j])%MOD;
                ans%=MOD;
                ans+=(((selipin(bk))%MOD)*dig[j])%MOD;
                ans%=MOD;

            //    ans=(ans+fr*pc10[j+j-1]%MOD)%MOD*dig[j]%MOD*2%MOD;
                ans2+=(((fr*pc10[j+j]%MOD)%MOD)*dig[j]%MOD)*2%MOD;
                ans2%=MOD;
            }
        }
    }

    cout << (ans+ans2)%MOD << el;

    return 0;
}
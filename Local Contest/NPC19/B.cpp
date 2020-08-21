#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define el '\n'

const int SIZE = 70000;
const int LIMIT = sqrt(SIZE)+1;

bitset<SIZE> prime;
vector<ll> prim;

void sieve() {
 prime.flip();
 prime[1]=0;
 for(int i=2;i<=LIMIT;i++){
  if (prime[i]){
   for(int j=2*i;j<SIZE;j+=i){
             prime[j]=0;
            }
        }
 }

    for(ll i=2;i<=SIZE;i++){
        if(prime[i]){
            prim.push_back(i);
        }
    }
}

ll binpowmod(ll a, ll b, ll c) {
    a = a%c;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a)%c;
        a = (a * a)%c;
        b >>= 1;
    }
    return res%c;
}

ll gcdExtended(ll a, ll b, ll *x, ll *y){ 
    if (a == 0){ 
        *x = 0; 
        *y = 1; 
        return b; 
    }
    ll x1, y1;
    ll gcd = gcdExtended(b%a, a, &x1, &y1); 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
    return gcd; 
}

pair<ll,ll> getSolution(ll a, ll b){
    ll x,y;
    ll g = gcdExtended(a, b, &x, &y);
    return make_pair(x, y);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    sieve();
    int t;
    cin >> t;
    while(t--){
        ll k,l,m;
        cin >> k >> l >> m;
        ll satu,dua;
        for(auto x:prim){
            if(m%x==0){
                satu=x;
                dua=m/x;
                break;
            }
        }

        ll modpow = (satu-1)*(dua-1);
        l = l%modpow;
        vector<ll> cobasatu;
        for(ll i=0;i<satu;i++){
            ll w = binpowmod(i, l, satu);
            if(k%satu==w){
                cobasatu.push_back(i);
            }
        }
        vector<ll> cobadua;
        for(ll i=0;i<dua;i++){
            ll w = binpowmod(i, l, dua);
            if(k%dua==w){
                cobadua.push_back(i);
            }
        }
        ll ans=-1;
        for(auto em:cobasatu){
            for(auto en:cobadua){
                pair<int,int> test = getSolution(satu, dua);
                test.first *= (en-em);
                test.second *= (en-em);
                ll dd = (em+satu*test.first);
                if(dd<0){
                    ll hey = -1*dd;
                    hey = hey%m;
                    hey = -1*hey;
                    hey += m;
                    dd=hey;
                }
                ans=dd%m;
                break;
            }
        }
        cout << ans << el;
    }
    return 0;
}
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

ll n,q;
ll ar[100006];
ll pow2[41];
ll cnt[41];
ll state[41];
int mkpow=0;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (ll i=0;i<41;i++){
        pow2[i]=((ll)1 << i);
        cnt[i]=0;
        state[i]=1;
    }

    cin >> n >> q;
    
    for (int i=0;i<n;i++){
        ll tm;
        cin >> tm;
        for (int i=0;i<41;i++){
            if ((tm&pow2[i])>0){
                cnt[i]++;
                mkpow=max(mkpow,i);
            }
        }
    }
 //   for (auto x : cnt) cerr << x << " "; cerr << el;

    for (int z=0;z<q;z++){
        for (int i=0;i<=mkpow;i++){
            ll del=n-cnt[i];
            cnt[i]=(2*del*cnt[i])%MOD;
        }n=n*n%MOD;
    }

//    for (auto x : cnt) cerr << x << " "; cerr << el; 

    ll tot=0;
    for (int i=0;i<41;i++){
        ll tm=(cnt[i]*pow2[i])%MOD;
        tot=(tot+tm)%MOD;
    }

    while (tot<0) tot+=MOD;

    cout << tot << el;

    return 0;
}
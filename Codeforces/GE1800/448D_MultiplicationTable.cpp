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

ll N=500000;
ll n,m,k;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    //num.pb(1);
    ll ans=0;
    ll low=1,high=n*m;
    while (low<high){
        ll cnt=0;
        ll mid=(low+high)/2;

        for (ll i=1;i<=m;i++){
            ll tm;
        //    if (n*i==mid) tm=n;
            tm=(mid)/i;
            cnt+=min(n,tm);
        }
     //   cout << mid << " " << cnt << el;

        if (cnt<k){
            low=mid+1;
        } else{
            high=mid;
        }
    }    

    cout << high << el;

    return 0;
}
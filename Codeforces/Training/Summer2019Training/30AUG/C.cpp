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


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> q;

    while (q--){
        ll n,m;
        cin >> n >> m;

        ll cnt=n/m;
        ll dig=m%10;

        ll pc[11];
        pc[0]=0;
        for (ll i=1;i<=10;i++){
            pc[i]=i*dig%10;
        }
        for (ll i=2;i<=10;i++){
            pc[i]+=pc[i-1];
        }

        cout << ((cnt-cnt%10)/10)*pc[10]+pc[cnt%10] << el;
    }

    return 0;
}
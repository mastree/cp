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

ll n,x,Plev[51];
ll sz[51];

ll sol(ll lev,ll height){
    if (lev==0){
        return height;
    }
    if (height>=sz[lev]){
        return Plev[lev];
    }
    if (height<=1){
        return 0;
    }

    ll mid=(sz[lev]+1)/2;

    if (height>=mid){
        return 1+Plev[lev-1]+sol(lev-1,height%mid); 
    }

    return sol(lev-1,height-1);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x;
    sz[0]=1;
    Plev[0]=1;
    for (int i=1;i<=n;i++){
        sz[i]=sz[i-1]+sz[i-1]+3;
        Plev[i]=Plev[i-1]+Plev[i-1]+1;
    }

    ll ans=sol(n,x);
    cout << ans << el;

    return 0;
}
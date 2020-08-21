#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 100000000000000007
#define pii pair<int,int>
#define ll long long
#define el '\n'

using namespace std;

ll ar[300015];
ll pc[300015][11];
ll dp[300015];
ll ri[300015];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n,m,k;
    cin >> n >> m >> k;
    for (ll i=1;i<=n;i++){
        cin >> ar[i];
    }

    ll ans=0; // dp[i]= f(l,i)  || l<=i+1;

    for (ll mul=0;mul+m<=n;mul++){
        ll tot=0;
        for (ll i=1;i<=m;i++){
            tot+=ar[i+mul];
        }

        dp[mul+1]=tot-k;
    }
    
    for (ll i=1;i<=n;i++){
        ll tm=0;
        ri[i]=max(dp[i],(ll)0);
        for (ll j=0;j<m-1;j++){
            tm+=ar[i+j];
            ri[i]=max(ri[i],tm-k);
        }
    }

    for (ll j=1;j<=m;j++){
        pc[j][j]=dp[j];
        for (ll i=j+m;i+m-1<=n;i+=m){
            pc[i][j]=pc[i-m][j]+dp[i];
        }
    }

    for (ll j=1;j<=m;j++){
        ll mn=min(pc[j%m][j],(ll)0);
        ans=max(ans,ri[j]);
        for (ll i=j;i+m-1<=n;i+=m){
            mn=min(mn,pc[i][j]);
            ans=max(ans,pc[i][j]-mn+ri[i+m]);
        }
    }


    cout << ans << el;

    return 0;
}
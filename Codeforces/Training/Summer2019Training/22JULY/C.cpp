#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define ll long long
#define el '\n'
#define pll pair<ll,ll>
#define pli pair<ll,int>

using namespace std;


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,k;
    cin >> n >> k;

    ll dif[n+1],ar[n+1],ans=0; 
  //  pli dif[n+1]; // dif[i]=ar[i+1]-ar[i]
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }

    for (int i=1;i<n;i++){
        dif[i]=ar[i+1]-ar[i];
    }

    sort(dif+1,dif+n);
    int cek=n;
    for (int i=1;cek>k;i++){
        ans+=dif[i];
        cek--;
    }

    cout << ans << el;

    return 0;
}
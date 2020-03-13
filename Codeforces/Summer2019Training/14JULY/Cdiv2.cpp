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
ll a[100005];

ll selipin(ll x) {
    ll ret=0;
    vector<int> p;
    while (x>0) {
        p.pb(x%10);
        x/=10;
    }
    reverse(p.begin(),p.end());
    for (int i=0;i<p.size();i++) {
        ret+=p[i];
        ret*=10;
        ret*=10;
    }
    return ret/10;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    ll ans=0;
    for (int i=1;i<=n;i++) {
        ans+=((selipin(a[i])%MOD)*n)%MOD;
        ans%=MOD;
        ans+=(((selipin(a[i])/10)%MOD)*n)%MOD;
        ans%=MOD;
    }
    cout << ans << endl;

    return 0;
}
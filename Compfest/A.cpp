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

using namespace std;

vector <pll> ar;
vector <pll> v;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i=0;i<n;i++){
        ll a,b;
        cin >> a >> b;
        ar.pb(mp(a,b));
    }

    sort(ar.begin(),ar.end());

    ll mk=0,id=-1;
    for (auto x : ar){
        if (mk<x.fi){
            mk=x.se;
            v.pb(x);
            id++;
        } else{
            mk=max(x.se,mk);
            v[id].se=mk;
        }
    }

    ll ans=0;
    for (auto x : v){
        ans+=(x.fi+x.se)*(x.se-x.fi+1)/2;
    }

    cout << ans << el;

    return 0;
}
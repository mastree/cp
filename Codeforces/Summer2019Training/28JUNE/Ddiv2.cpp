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

    int n;
    cin >> n;

    pair <ll,ll> ar[n];
    for (int i=0;i<n;i++){
        long double a;
        cin >> a;

        ar[i].fi=(ll)floorl(a);
        ar[i].se=(ll)ceill(a);
    //    cerr << ar[i].fi << " " << ar[i].se << el;
    }

    ll tot=0;
    for (int i=0;i<n;i++){
        tot+=ar[i].fi;
    }

    ll ans[n];
    for (int i=0;i<n;i++){
        if (tot>=0){
            ans[i]=ar[i].fi;
        } else{
            ans[i]=ar[i].se;
            tot+=ar[i].se-ar[i].fi;
        }
    }

    for (int i=0;i<n;i++) cout << ans[i] << el;

    return 0;
}
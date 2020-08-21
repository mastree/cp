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

    ll x,y,z;
    cin >> x >> y >> z;
    ll tot=x+y;
    ll mk=tot/z,res1=x/z,res2=y/z;

    if (mk==res1+res2){
        cout << mk << " " << 0 << el;
        return 0;
    }

    ll md=min(z-x%z,z-y%z);
    cout << mk << " " << md << el;

    return 0;
}
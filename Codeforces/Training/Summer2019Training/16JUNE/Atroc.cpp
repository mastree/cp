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

    ll n,x,y;
    cin >> n >> x >> y;

    ll u=0,d=0,l=0,r=0;

    if (x>=0) r=x;
    else l=-x;
    if (y>=0) u=y;
    else d=-y;

    if (u+d+l+r>n){
        cout << -1 << el;
        return 0;
    }

    ll sisa=n-u-d-l-r;
    if (sisa%2){
        cout << -1 << el;
        return 0;
    }

    cout << u << " " << r+sisa/2 << " " << d << " " << l+sisa/2  << el;

    return 0;
}
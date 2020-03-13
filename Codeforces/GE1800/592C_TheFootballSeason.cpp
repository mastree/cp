#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'

using namespace std;

ll n,p,w,d;
ll x,y;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> p >> w >> d;
    for (y=0;y<w;y++){
        ll sisa=p-d*y; 
        if (sisa<0){
            cout << -1 << el;
            return 0; 
        } 

        if (sisa%w==0){
            break;
        }
    }

    x=(p-d*y)/w;
    if (x+y>n || x<0 || (x*w+y*d!=p)){
        cout << -1 << el;
        return 0;
    }
    cout << x << " " << y << " " << n-x-y << el;  

    return 0;
}
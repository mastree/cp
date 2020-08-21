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

const int N = 2e5 + 7;

int n, xx, yy;
vector <pii> v;
multiset <int> le, ri;
int ans=0;
int l, r, u, d;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> xx >> yy;
    for (int i=0;i<n;i++){
        int a, b;
        cin >> a >> b;
        v.pb(mp(a,b));
    }

    for (auto koor : v){
        if (koor.fi<xx && koor.se<yy){
            l++;u++;
        } else if (koor.fi>xx && koor.se<yy){
            l++;d++;
        } else if (koor.fi<xx && koor.se>yy){
            r++;u++;
        } else if (koor.fi>xx && koor.se>yy){
            r++;d++;
        } else if (koor.fi==xx){
            if (koor.se<yy) l++;
            else r++;
        } else{
            if (koor.fi<xx) u++;
            else d++;
        }
        // cout << l << " " << r << " " << u << " " << d << el;
    }

    ans = max(max(l,r),max(u,d));
    cout << ans << el;
    if (ans==l){
        cout << xx << " " << yy-1 << el;
    } else if (ans==r){
        cout << xx << " " << yy+1 << el;
    } else if (ans==u){
        cout << xx-1 << " " << yy << el;
    } else{
        cout << xx+1 << " " << yy << el; 
    }

    return 0;
}
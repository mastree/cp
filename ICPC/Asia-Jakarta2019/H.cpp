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

typedef pair<ll, ll> pll;

const int N = 1e5 + 10;

int n;
ll ans;
pll ar[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        pll temp;
        cin >> temp.fi >> temp.se;
        if (temp.fi > temp.se) swap(temp.fi, temp.se);
        ar[i] = temp;
        if (ans < temp.fi * temp.se){
            ans = temp.fi * temp.se;
        }
    }
    sort(ar + 1, ar + n + 1, greater<pll>());
    ll mx = ar[1].se;
    for (int i=2;i<=n;i++){
        ll side = min(mx, ar[i].se);
        if (ar[i].fi * side * 2 > ans){
            ans = ar[i].fi * side * 2;
        }
        mx = max(mx, ar[i].se);
    }
    
    if (ans & 1){
        cout << ans / 2 << ".5" << el;
    } else{
        cout << ans / 2 << ".0" << el;
    }

    return 0;
}
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

ll a, b, c, d, e, f;
ll ans;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b >> c >> d >> e >> f;
    ll cur = a;
    for (int i=1;i<(b + c);i++){
        ans += cur;
        // cout << i << " => " << cur << el;
        if (i < b && i < f){
            cur++;
        } else if ((i < b) || (i < f)){

        } else{
            cur--;
        }
    }
    cout << ans << el;

    return 0;
}
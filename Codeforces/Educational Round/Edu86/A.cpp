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

int q;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        ll a, b, x, y;
        cin >> x >> y >> a >> b;
        ll ans = 0;
        if (a * 2 < b){
            ans = (x + y) * a;
        } else{
            ll kur = min(x, y);
            ans += kur * b;
            x -= kur;
            y -= kur;
            ans += (x + y) * a;
        }
        cout << ans << el;
    }

    return 0;
}
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

const int N = 1e5 + 10;

int q;
ll x, y;

ll fl(ll x){
    ll res = 0;
    while (x % 2 == 0 && x != 0){
        res++;
        x/=2;
    }
    return res;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> x >> y;

        if (x > y) swap(x, y);
        ll ans = x + y;
        ll ax = x, ay = y;

        if (x == 0 || y == 0){
            cout << ans << el;
            continue;
        }
        while (x % 2 == 0 && y % 2 == 0){
            x /= 2;
            y /= 2;
        }
        ll sel = abs(ax - ay);
        if ((x & 1) && (y & 1)){
            if (sel % 4 == 0){
                ans += 2;
            }
        }
        cout << ans << el;
    }

    return 0;
}
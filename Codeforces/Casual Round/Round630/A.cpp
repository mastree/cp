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
        ll a, b, c, d;
        ll x, y, x1, y1, x2, y2;
        cin >> a >> b >> c >> d;
        cin >> x >> y >> x1 >> y1 >> x2 >> y2;

        ll bedax = b - a;
        ll beday = d - c;

        if (x1 == x2 && (b || a)){
            cout << "No" << el;
            continue;
        }

        if (y1 == y2 && (c || d)){
            cout << "No" << el;
            continue;
        }

        ll maxx = x2 - x;
        ll minx = x1 - x;
        ll maxy = y2 - y;
        ll miny = y1 - y;

        if (maxx >= bedax && bedax >= minx && maxy >= beday && beday >= miny){
            cout << "Yes" << el;
        } else{
            cout << "No" << el;
        }
    }

    return 0;
}
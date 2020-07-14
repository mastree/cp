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

typedef pair<double, double> pdd;

const pdd ORI = mp(0.0, 0.0);
const double PI = acos(-1);

ll xa, ya, xb, yb;
pdd a, b;

double mandist(pdd a, pdd b){
    double delx = a.fi - b.fi;
    double dely = a.se - b.se;
    return sqrt(delx * delx + dely * dely);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(11);
    cin >> xa >> ya >> xb >> yb;
    a = mp((double)xa, (double)ya);
    b = mp((double)xb, (double)yb);
    double ans = mandist(ORI, a) + mandist(ORI, b);
    cout << mandist(a, b) << el;
    ans = min(ans, PI * mandist(a, b));
    cout << ans << el;

    return 0;
}
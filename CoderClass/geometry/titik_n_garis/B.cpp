#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using ld = long double;

ld x, y;
ld xa, ya, xb, yb;

void input(ld& a){
    ll temp;
    cin >> temp;
    a = (ld)temp;
}
ld find_edist(ld xa, ld ya, ld xb, ld yb){
    ld delx = xa - xb;
    ld dely = ya - yb;
    return sqrtl(delx * delx + dely * dely);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(11);

    input(x);
    input(y);
    input(xa);
    input(ya);
    input(xb);
    input(yb);

    ld delx = xb - xa;
    ld dely = yb - ya;
    ld l = 0, r = 1;
    ld best;
    for (int i=0;i<200;i++){
        ld p1 = l + (r - l) / ((ld)3);
        ld p2 = r - (r - l) / ((ld)3);

        ld f1 = find_edist(x, y, xa + delx * p1, ya + dely * p1);
        ld f2 = find_edist(x, y, xa + delx * p2, ya + dely * p2);
        if (f1 > f2){
            l = p1;
            best = f2;
        } else{
            r = p2;
            best = f1;
        }
    }
    cout << best << el;

    return 0;
}
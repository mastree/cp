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

const ld EPS = 1e-9;

ld x[2][2], y[2][2];

ld find_edist(ld xa, ld ya, ld xb, ld yb){
    ld delx = xb - xa;
    ld dely = yb - ya;
    return delx * delx + dely * dely;
}
ld point_to_line(ld x, ld y, ld a, ld b, ld c){
    return abs(x * a + y * b + c) / sqrtl(a * a + b * b);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(11);

    for (int i=0;i<2;i++){
        for (int j=0;j<2;j++){
            cin >> x[i][j] >> y[i][j];
        }
    }
    // ax + by + c = 0
    ld a = (y[0][1] - y[0][0]);
    ld b = (x[0][0] - x[0][1]);
    ld c = -(a * x[0][0] + b * y[0][0]);

    ld delx = x[1][1] - x[1][0];
    ld dely = y[1][1] - y[1][0];
    ld l = 0, r = 1;
    ld best;
    for (int i=0;i<150;i++){
        ld p1 = l + (r - l) / 3;
        ld p2 = r - (r - l) / 3;

        ld f1 = point_to_line(x[1][0] + p1 * delx, y[1][0] + p1 * dely, a, b, c);
        ld f2 = point_to_line(x[1][0] + p2 * delx, y[1][0] + p2 * dely, a, b, c);
        if (f1 > f2){
            best = f2;
            l = p1;
        } else{
            best = f1;
            r = p2;
        }
    }
    ld xx = x[1][0] + l * delx;
    ld yy = y[1][0] + l * dely;
    ld xa = min(x[0][0], x[0][1]);
    ld xb = max(x[0][0], x[0][1]);
    ld ya = min(y[0][0], y[0][1]);
    ld yb = max(y[0][0], y[0][1]);
    if (best > EPS || !(xa <= xx && xx <= xb && ya <= yy && yy <= yb)){
        cout << -1 << " " << -1 << el;
        return 0;
    }
    cout << xx << " " << yy << el;

    return 0;
}
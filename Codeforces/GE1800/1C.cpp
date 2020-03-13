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
const double eps = 1e-4;
const double PI = acos(-1);

pair<double, double> ar[4];
double angle[4];

double dist(double a, double b){
    return sqrt(a * a + b * b);
}

double ang(double a, double b, double c, double d){
    return acos((a * c + b * d)/(dist(a, b) * dist(c, d)));
}

bool eq(double a, double b){
    return (abs(a - b) <= eps);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i=1;i<=3;i++){
        cin >> ar[i].fi >> ar[i].se;
    }
    pair<double, double> v1, v2;
    v1 = mp(ar[2].fi - ar[1].fi, ar[2].se - ar[1].se);
    v2 = mp(ar[3].fi - ar[1].fi, ar[3].se - ar[1].se);
    angle[1] = ang(v1.fi, v1.se, v2.fi, v2.se);
    v1 = mp(ar[1].fi - ar[2].fi, ar[1].se - ar[2].se);
    v2 = mp(ar[3].fi - ar[2].fi, ar[3].se - ar[2].se);
    angle[2] = ang(v1.fi, v1.se, v2.fi, v2.se);
    v1 = mp(ar[2].fi - ar[3].fi, ar[2].se - ar[3].se);
    v2 = mp(ar[1].fi - ar[3].fi, ar[1].se - ar[3].se);
    angle[3] = ang(v1.fi, v1.se, v2.fi, v2.se);
    for (int i=1;i<=3;i++){
        angle[i] *= 180/PI;
        // cout << angle[i] << el;
    }

    int sudut = -1;
    double rad;
    for (int i=3;i<=100;i++){
        for (int j=1;j<i-1;j++){
            for (int k=1;j+k<i;k++){
                int l = i - j - k;
                double a = j;
                double b = k;
                double c = l;
                if (eq(angle[1]/a, angle[2]/b) && eq(angle[2]/b, angle[3]/c)){
                    sudut = i;
                    rad = dist(ar[2].fi - ar[3].fi, ar[2].se - ar[3].se) / (2 * sin(angle[1] / 180 * PI));
                    break;
                }
            }
            if (sudut != -1) break;
        }
        if (sudut != -1) break;
    }

    double alp = 2 * PI / (double)sudut;
    double ans = rad * rad * sin(alp) * ((double)sudut) / 2;
    cout << fixed << setprecision(10) << ans << el;

    return 0;
}
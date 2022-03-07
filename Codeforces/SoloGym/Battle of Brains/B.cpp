#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const double EPS = 1e-9;
const double PI = acos(-1);

int q;
double m, d;

double findr(double v){
    double l = 0, r = 100;
    double temp = PI * 4 / 3;
    while (r - l > EPS){
        double m = (l + r) / 2;
        if (temp * m * m * m < v){
            l = m;
        } else{
            r = m;
        }
    }
    return (l + r) / 2;
}

void solve(){
    cin >> m >> d;
    double r = findr(m / d);
    cout <<  (m / d) * 3 / r << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(4);
    cin >> q;
    for (int i=1;i<=q;i++){
        cout << "Case " << i << ": ";
        solve();
    }

    return 0;
}
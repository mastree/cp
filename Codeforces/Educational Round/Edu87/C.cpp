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

const double PI = acos(-1);

int n, q;
double side;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(11);
    cin >> q;
    while (q--){
        cin >> n;
        n = n + n;
        side = (double)n;
        double alp = (double)360.0 / side;
        double beta = ((double)180.0 - alp) / 2.0;
        if (n % 4 == 0){
            double x = 0.5 * (1 / cos(PI * beta / 180.0));
            double y = x * sin(PI * beta / 180.0) * 2.0;
            cout << y << el;
        } else{
            double x = abs(0.5 * (1 / cos(PI * beta / 180.0)));
            // double x2 = x + x;
            double diag = x + x;
            double ceta = 90.0 - beta;
            double coss = cos(ceta * 180.0 / PI);
            double sinn = sin(ceta * 180.0 / PI);
            diag = 
            // double y = abs(x * sin(PI * beta / 180.0) * 2.0); // diameter = 2 * x
            // double z = abs(cos(ceta * 180.0 / PI));
            // double hz = abs(sin(ceta * 180.0 / PI));
            // double temp = abs(2.0 * x - 2.0 * hz + 2.0 * z);
            // double ans = temp * cos(PI / 4.0);
            cout << 2 * x << el;
        }
    }

    return 0;
}
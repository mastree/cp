#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n;
long double p, np; 

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    if (n == 0){
        cout << 0 << el;
        return 0;
    }
    p = ((long double)n) / ((long double)100);
    np = 1.0 - p;
    np *= np;
    cout << fixed << setprecision(11) << p / (1 - np) << el;

    return 0;
}
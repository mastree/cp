#include <bits/stdc++.h>
    
using namespace std;
    
const long double eps = 1e-12;
    
int tc;
long double a, b, c, x;
long double ca, cb, bc, ba;
    
long double G(long double pa, long double ha, long double hb) {
    long double lola = pa - ba;
    long double lolb = c + hb;
    long double ret = (lola * lola + lolb * lolb); // from home to river
    long double da = ha - pa, db = c; 
    ret += (da * da + db * db); // from river to some point
    return ret;
}

long double hitung(long double pa, long double ha, long double hb) {
    long double lola = pa - ba;
    long double lolb = c + hb;
    long double ret = sqrtl(lola * lola + lolb * lolb); // from home to river
    long double da = ha - pa, db = c; 
    ret += sqrtl(da * da + db * db); // from river to some point
    return ret;
}
    
void solve() {
    cin >> a >> b >> c >> x;
    bc = b + c;
    long double res = 0;
    // To the river then to grandma's house
    long double l = 0, r = a;
    ba = 0;
    for (int i=0;i<100;i++) {
        long double p1 = l + (r - l) / 3.0;
        long double p2 = r - (r - l) / 3.0;
        if (G(p1, a, b) > G(p2, a, b)) {
            l = p1;
        } else {
            r = p2;
        }
    }
    res += hitung(r, a, b);
    long double apt = sqrtl(a * a + b * b); 
    long double y = 100 - x;
    res += apt * (x / 100.0); // x% to home
    ca = a * (x / 100.0), cb = b * (y / 100.0);
    // To river then to home
    l = ca, r = a;
    ba = ca;
    for (int i=0;i<100;i++) {
        long double p1 = l + (r - l) / 3.0;
        long double p2 = r - (r - l) / 3.0;
        if (G(p1, a, cb) > G(p2, a, cb)) {
            l = p1;
        } else {
            r = p2;
        }
    }
    res += hitung(r, a, cb);
    cout << res << '\n';
}
    
int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cout << fixed << setprecision(12);
    cin >> tc;
    while (tc--) {
        solve();
    }
    
    return 0;
}
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

const int N = 60;

int q;
ld ab, cd, ad, bc;

void solve(){
    cin >> ab >> cd >> ad >> bc;
    ld l = 0, r = 1;
    ld del = ab - cd;
    for (int i=1;i<150;i++){
        ld m = (l + r) / 2;

        ld mline = ab - del * m;
        if ((ab + mline) * m > (cd + mline) * ((ld)1 - m)){
            r = m;
        } else{
            l = m;
        }
    }
    cout << ad * l << " " << bc * l << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(6);
    cin >> q;
    for (int i=1;i<=q;i++){
        cout << "Lahan #" << i << ": ";
        solve();
    }

    return 0;
}
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

int q;

void solve(){
    ll x[3], y[3];
    for (int i=0;i<3;i++){
        cin >> x[i] >> y[i];
    }
    ll delx = x[1] - x[0];
    ll dely = y[1] - y[0];
    ll cc = delx * y[0] - dely * x[0];
    
    ll temp1 = dely * x[2] + cc;
    ll temp2 = delx * y[2];
    if (temp1 < temp2){
        cout << "rasi kucing" << el;
    } else if (temp1 > temp2){
        cout << "rasi anjing" << el;
    } else{
        cout << "rasi ular" << el;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    for (int i=1;i<=q;i++){
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}
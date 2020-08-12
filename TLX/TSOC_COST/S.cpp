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

const int N = 1e3 + 10;
const ld TOT = 1800;

int q;
int n;
int ar[N];

void solve(){
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    ld ans = 0, cur = 1;
    ans += ar[1];

    ld jar = 0;
    for (int i=1;i<=n;i++){
        jar += (((ld)ar[i] - ar[i - 1]) / ((ld)2)) * (((ld)ar[i] - ar[i - 1])/ TOT);
    }
    ld still = ((ld)ar[n]) / TOT;
    ld tam = (1 - still) * ((TOT - (ld)ar[n]) / 2);

    for (int i=0;i<100000;i++){
        ans += cur * jar + cur * tam;
        cur *= still;
    }
    cout << ans << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(11);

    cin >> q;
    while (q--){
        solve();
    }

    return 0;
}